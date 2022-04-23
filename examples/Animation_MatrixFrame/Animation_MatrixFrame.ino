#include <PixelStrip.h>
#include "FrameAnimation.h"

const int PIN = 7;
const int MAX_X = 8;
const int MAX_Y = 32;
const int BRIGHTNESS = 64;

PixelStrip *strip = new PixelStrip((new NEOPIXEL<PIN>), MAX_X, MAX_Y);
FrameAnimation *animation;

void setup() {
  animation = new FrameAnimation();
  animation->color = YELLOW;
  animation->waitTime = 100;
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(animation);
  strip->setup();
}

void loop() {
  strip->draw();
  strip->show();
  delay(10);
}
