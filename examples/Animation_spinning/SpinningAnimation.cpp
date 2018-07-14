#include <Adafruit_NeoPixel.h>
#include "SpinningAnimation.h"

uint32_t black;
int currentPixel;

void SpinningAnimation::reset(Adafruit_NeoPixel *strip) {
  black = 0x000000;
  currentPixel = 0;
  waitTime = 1000.0 / strip->numPixels();
  setTimeout(waitTime);
  strip->clear();
}

void SpinningAnimation::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    strip->setPixelColor(currentPixel, black);
    currentPixel = (currentPixel + 1) % strip->numPixels();
    strip->setPixelColor(currentPixel, color);
    setTimeout(waitTime);
  }
}