#include <Adafruit_NeoPixel.h>
#include "MyAnimation.h"

int pixelState = 0;

void MyAnimation::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTime);
}

void MyAnimation::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    strip->setPixelColor(0, (pixelState%3==0) ? 0x008800 : 0x000000);
    pixelState = (pixelState + 1) % 3;
    for (int pixelNum = 0; pixelNum < strip->numPixels(); pixelNum++) {
      unsigned long pixelColor = ((pixelNum + pixelState) % 3 == 0) ? color : 0x000000;
      strip->setPixelColor(pixelNum, pixelColor);
    }
    setTimeout(waitTime);
  }
}