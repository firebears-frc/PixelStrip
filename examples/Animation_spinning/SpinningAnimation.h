#ifndef SpinningAnimation_h
#define SpinningAnimation_h
#include <PixelStrip.h>

/**
 * Animation class that causes a single pixel to move across the strip.
 */
class SpinningAnimation : public Animation {
public:
  void reset(PixelStrip *strip);
  void draw(PixelStrip *strip);
  
  /** Color of the spinning pixel */
  uint32_t color = BLUE;
  
  /** Milliseconds for the pixel to travel across all the pixels. */
  unsigned long waitTime;

private:
  int currentPixel;
};
#endif
