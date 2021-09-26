#ifndef SubPixelStrip_h
#define SubPixelStrip_h
#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>

class SubPixelStrip : public PixelStrip {

  public:
    SubPixelStrip(uint16_t num, PixelStrip *parent, uint16_t offset);
    void clear();
    void begin(void);
    void show(void);
    uint16_t numPixels(void);
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
    void setPixelColor(uint16_t n, uint32_t c);

  private:
    PixelStrip *_parent;
    uint16_t _num;
    uint16_t _offset;
};
#endif

