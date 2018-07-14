#ifndef PulseAnimation_h
#define PulseAnimation_h
#include <Animation.h>

/**
 *
 */
class PulseAnimation : public Animation {
  public:
    PulseAnimation();
    PulseAnimation(int n);
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
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