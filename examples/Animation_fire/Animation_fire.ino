#include <PixelStrip.h>
#include "FireAnimation.h"
#include "SmoothFireAnimation.h"

const int PIN = 7;
const int NUM_PIXELS = 144;
const int BRIGHTNESS = 64;

PixelStrip *strip = new PixelStrip((new NEOPIXEL<PIN>), NUM_PIXELS);
FireAnimation *animation;

void setup() {
  animation = new FireAnimation();
  animation->sparkHeight = NUM_PIXELS / 2;
  animation->sparks = NUM_PIXELS / 24;
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(animation);
  strip->setup();
  blink(strip, 3);
}

void loop() {
  strip->draw();
  strip->show();
}

void blink(PixelStrip *strip, int n) {
  strip->clear();
  strip->show();
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < n; i++) {
    strip->setPixelColor(0, RED);
    strip->show();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    strip->clear();
    strip->show();
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }
}