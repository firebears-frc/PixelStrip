#ifndef FrameAnimation_h
#define FrameAnimation_h
#include <PixelStrip.h>

/**

*/
class FrameAnimation : public Animation {
  public:
    void reset(PixelStrip *strip);
    void draw(PixelStrip *strip);
    unsigned long waitTime = 500;
    uint32_t color = DARKGREEN;
  private:
    uint32_t pickColor(int mode, uint32_t c);
    int pixelState = 0;
};
#endif
