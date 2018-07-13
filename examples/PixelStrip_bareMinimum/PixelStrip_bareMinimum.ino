#include <PixelStrip.h>

const int PIN = 7;
const int NUM_PIXELS = 8;
const int BRIGHTNESS = 128;

PixelStrip *strip = new PixelStrip(NUM_PIXELS, PIN);

void setup() {
  strip->setup();
  strip->setBrightness(BRIGHTNESS);
}

void loop() {
  strip->clear();
  strip->setPixelColor(0, 0x880000);
  strip->show();
}
