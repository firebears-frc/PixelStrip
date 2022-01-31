#ifndef FireAnimation_h
#define FireAnimation_h
#include <PixelStrip.h>

/**

*/
class FireAnimation : public Animation {
  public:
    void reset(PixelStrip *strip);
    void draw(PixelStrip *strip);
    int cooling = 80;
    int sparking = 50;
    int sparks = 3;
    int sparkHeight = 4;
    bool reversed = true;
    bool mirrored = false;
  private:
    byte* heat;
    int heatSize = 0;
    int blendSelf = 2;
    int blendNeighbor1 = 3;
    int blendNeighbor2 = 2;
    int blendNeighbor3 = 1;
    int blendTotal = 8;
    uint32_t heatColor(byte temperature);
};
#endif
