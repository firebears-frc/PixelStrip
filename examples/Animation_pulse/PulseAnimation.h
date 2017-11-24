#ifndef PulseAnimation_h
#define PulseAnimation_h
#include <Animation.h>

/**
 *
 */
class PulseAnimation : public Animation {
  public:
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);


    /** Milliseconds for each pulse cycle.  */
    unsigned long _time_cycle = 2000;


  private:
    int f(unsigned long t);
    uint32_t fadeColor(uint32_t c, int brightness);
};
#endif

