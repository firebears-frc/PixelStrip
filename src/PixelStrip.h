#ifndef PixelStrip_h
#define PixelStrip_h
#include <FastLED.h>
#include <Animation.h>

class Animation;

/**
   Encapsulates FastLED, but adds methods for plugging in an
   Animation to a strip.
*/
class PixelStrip
{
  const uint16_t _numPixels;
  const uint16_t _offset;
  const PixelStrip *_parent;

  public:
    PixelStrip(CLEDController *controller, uint16_t numPixels);
    PixelStrip(PixelStrip *parent, uint16_t numPixels, uint16_t offset);
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
#endif



