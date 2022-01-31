#include <PixelStrip.h>
#include "MyAnimation.h"

const int PIN = 7;
const int NUM_PIXELS = 8;
const int BRIGHTNESS = 128;

PixelStrip *strip = new PixelStrip((new NEOPIXEL<PIN>), NUM_PIXELS);
MyAnimation *animation;

void setup() {
  animation = new MyAnimation();
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(animation);
  strip->setup();
}

void loop() {
  strip->draw();
  strip->show();
  delay(10);
}
