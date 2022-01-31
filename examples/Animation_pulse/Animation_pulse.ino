#include <PixelStrip.h>
#include "PulseAnimation.h"

const int PIN = 7;
const int NUM_PIXELS = 8;
const int BRIGHTNESS = 128;

PixelStrip *strip = new PixelStrip((new NEOPIXEL<PIN>), NUM_PIXELS);
PulseAnimation *animation;

void setup() {
  animation = new PulseAnimation();
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(animation);
  strip->setup();
}

void loop() {
  strip->draw();
  strip->show();
  delay(10);
}
