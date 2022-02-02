#ifndef SmoothFireAnimation_h
#define SmoothFireAnimation_h
#include <PixelStrip.h>

/**

*/
class SmoothFireAnimation : public Animation {
  public:
    void reset(PixelStrip *strip);
    void draw(PixelStrip *strip);
    float sparkProbability = 0.3;
    int sparks = 3;
    int sparkHeight = 4;
    float sparkHeat = 0.5;
    float cooling = 1.0;
    float spreadRate = 1.0;
    bool reversed = false;
    bool mirrored = false;
  private:
    float* heat;
    int heatSize = 0;
    long lastDraw;
    uint32_t heatColor(byte temperature);
    float randomFloat();
};
#endif