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
    unsigned long color = 0x008800;
  private:
};
#endif
