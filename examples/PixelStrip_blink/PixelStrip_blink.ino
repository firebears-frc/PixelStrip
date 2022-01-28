#include <PixelStrip.h>

const int PIN = 7;
const int NUM_PIXELS = 8;
const int BRIGHTNESS = 128;

PixelStrip *strip = new PixelStrip((new NEOPIXEL<PIN>), NUM_PIXELS);

void setup() {
  strip->setup();
  strip->setBrightness(BRIGHTNESS);
}

void loop() {
  strip->setPixelColor(0, RED);
  strip->show();
  delay(1000);
  strip->clear();
  strip->show();
  delay(1000);
}