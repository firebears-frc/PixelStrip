#ifndef PixelStrip_h
#define PixelStrip_h
#include <Adafruit_NeoPixel.h>
#include "Animation.h"

/**
 * Extends the Adafruit_NeoPixel class, but adds methods for plugging in an
 * Animation to the strip.
 */
class PixelStrip : 
public Adafruit_NeoPixel
{
public:
  PixelStrip(uint16_t num, uint8_t pin);
  PixelStrip(uint16_t num, uint8_t pin, uint8_t npType);
  void setup();
  void draw();
  void setAnimation(Animation *animation);
  Animation *_animation;
  virtual void setTimeout(unsigned long milliseconds);
  virtual int isTimedout();
  unsigned long _timeout;
};
#endif



