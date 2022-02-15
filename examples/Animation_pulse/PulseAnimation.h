#ifndef PulseAnimation_h
#define PulseAnimation_h
#include "PixelStrip.h"

/**
 * Pulse alternating pixels against a list of colors.
 */
class PulseAnimation : public Animation {
  public:
    PulseAnimation();
    PulseAnimation(int n);
    void reset(PixelStrip *strip);
    void draw(PixelStrip *strip);
    void setColor(int i, uint32_t c);

    /** Milliseconds for each pulse cycle.  */
    unsigned long timeCycle = 2000;

  private:
    int f(unsigned long t);
    uint32_t fadeColor(uint32_t c, int brightness);
    uint32_t *colorList;
    int colorCount;
};
#endif