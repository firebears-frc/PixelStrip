#ifndef MyAnimation_h
#define MyAnimation_h
#include <PixelStrip.h>

/**

*/
class MyAnimation : public Animation {
  public:
    void reset(PixelStrip *strip);
    void draw(PixelStrip *strip);
    unsigned long waitTime = 500;
    uint32_t color = DARKGREEN;
  private:
    int pixelState = 0;
};
#endif
