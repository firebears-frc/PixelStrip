#include "SpinningAnimation.h"

void SpinningAnimation::reset(PixelStrip *strip) {
  currentPixel = 0;
  waitTime = 1000.0 / strip->numPixels();
  setTimeout(waitTime);
  strip->clear();
}

void SpinningAnimation::draw(PixelStrip *strip) {
  if (isTimedout()) {
    strip->setPixelColor(currentPixel, BLACK);
    currentPixel = (currentPixel + 1) % strip->numPixels();
    strip->setPixelColor(currentPixel, color);
    setTimeout(waitTime);
  }
}