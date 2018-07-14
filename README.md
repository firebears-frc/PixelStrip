# PixelStrip
Arduino library for NeoPixel animations.  Extends FastLED library.

```
#include <PixelStrip.h>

const int PIN = 7;
const int NUM_PIXELS = 8;
const int BRIGHTNESS = 128;
int state = 0;

PixelStrip *strip = new PixelStrip(NUM_PIXELS, PIN);

void setup() {
  strip->setup();
  strip->setBrightness(BRIGHTNESS);
  strip->clear();
  strip->setTimeout(1);
}

void loop() {
  if (strip->isTimedout()) {
    uint32_t color = ((state++) % 2 == 0) ? 0xff0000 : 0x888888;
    strip->setPixelColor(0, color);
    strip->show();
    strip->setTimeout(500);
  }
}
```
