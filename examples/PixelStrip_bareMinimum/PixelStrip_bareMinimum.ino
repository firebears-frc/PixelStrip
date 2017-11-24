#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>

const int PIN = 7;
const int NUM_PIXELS = 8;

PixelStrip strip = PixelStrip(NUM_PIXELS, PIN, NEO_GRB);

void setup() {
  strip.setup();
}

void loop() {
  // Change pixels
  strip.show();
}
