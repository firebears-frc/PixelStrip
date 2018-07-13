#ifndef PixelStrip_h
#define PixelStrip_h
#include <FastLED.h>

class Animation;

/**
   Encapsulates FastLED, but adds methods for plugging in an
   Animation to the strip.
*/
class PixelStrip
{
    const uint8_t _pin;
    const uint16_t _numPixels;
    const uint8_t _npType;

  public:
    PixelStrip(uint16_t numPixels, uint8_t pin);
    PixelStrip(uint16_t numPixels, uint8_t pin, uint8_t npType);
    void begin(void);
    void show(void);
    uint32_t Color(uint8_t r, uint8_t g, uint8_t b);
    uint32_t Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
    void setPixelColor(uint16_t n, uint32_t c);
    void setBrightness(uint8_t b);
    void clear(void);
    uint16_t numPixels(void);
    void setup();
    void draw();
    void setAnimation(Animation *animation);
    void setTimeout(unsigned long milliseconds);
    int isTimedout();

  private:
    Animation *_animation;
    unsigned long _timeout;
    CRGB *_led;
};

class Animation {
public:
  virtual void reset(PixelStrip *strip);
  virtual void draw(PixelStrip *strip);
  void setTimeout(unsigned long milliseconds);
  int isTimedout();
  unsigned long _timeout;
};
#endif



