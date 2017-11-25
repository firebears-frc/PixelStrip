#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include "MyAnimation.h"

#define PIN 7
#define NUM_PIXELS 8

PixelStrip strip = PixelStrip(NUM_PIXELS, PIN, NEO_GRB);
MyAnimation *animation;

void setup() {
  animation = new MyAnimation();
  strip.setup();
  strip.setAnimation(animation);
}

void loop() {
  strip.draw();
  strip.show();
  delay(10);
}
