#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>

const int PIN = 7;
const int NUM_PIXELS = 8;
const int BRIGHTNESS = 128;

PixelStrip *strip = new PixelStrip(NUM_PIXELS, PIN, NEO_GRB);

void setup() {
  strip->setup();
  strip->setBrightness(BRIGHTNESS);
}

void loop() {
  strip->setPixelColor(0, 0xFF0000);
  strip->show();
  delay(1000);
  strip->clear();
  strip->show();
  delay(1000);
}
