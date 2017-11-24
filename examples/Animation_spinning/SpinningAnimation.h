#ifndef SpinningAnimation_h
#define SpinningAnimation_h
#include <Animation.h>

/**
 * Animation class that causes a single pixel to move across the strip.
 */
class SpinningAnimation : public Animation {
public:
  void reset(Adafruit_NeoPixel *strip);
  void draw(Adafruit_NeoPixel *strip);
  
  /** Color of the spinning pixel */
  uint32_t _color = 0x000088;
  
  /** Milliseconds for the pixel to travel across all the pixels. */
  unsigned long _time_delay;


};
#endif


