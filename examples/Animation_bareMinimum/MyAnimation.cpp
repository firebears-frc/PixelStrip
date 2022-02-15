#include "MyAnimation.h"

void MyAnimation::reset(PixelStrip *strip) {
  strip->begin();
  setTimeout(waitTime);
}

void MyAnimation::draw(PixelStrip *strip) {
  if (isTimedout()) {
    strip->setPixelColor(0, (pixelState%3==0) ? DARKGREEN : BLACK);
    pixelState = (pixelState + 1) % 3;
    for (int pixelNum = 0; pixelNum < strip->numPixels(); pixelNum++) {
      uint32_t pixelColor = ((pixelNum + pixelState) % 3 == 0) ? color : BLACK;
      strip->setPixelColor(pixelNum, pixelColor);
    }
    setTimeout(waitTime);
  }
}