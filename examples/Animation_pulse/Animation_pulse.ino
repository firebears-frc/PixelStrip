#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include "PulseAnimation.h"

#define PIN 1
#define NUM_PIXELS 8

PixelStrip strip = PixelStrip(NUM_PIXELS, PIN, NEO_GRB);
PulseAnimation *animation;

void setup() {
  animation = new PulseAnimation();
  strip.setup();
  strip.setAnimation(animation);
}

void loop() {
  strip.draw();
  strip.show();
  delay(5);
}
