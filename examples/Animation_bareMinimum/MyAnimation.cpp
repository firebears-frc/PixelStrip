#include <Adafruit_NeoPixel.h>
#include "MyAnimation.h"

unsigned long wait = 500;
unsigned long color = 0x880000;
int state = 0;

void MyAnimation::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(wait);
  color = 0x880000;
}

void MyAnimation::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    strip->setPixelColor(0, (state%3==0) ? 0x008800 : 0x000000);
    state = (state + 1) % 3;
    for (int pixelNum = 0; pixelNum < strip->numPixels(); pixelNum++) {
      unsigned long pixelColor = ((pixelNum + state) % 3 == 0) ? color : 0x000000;
      strip->setPixelColor(pixelNum, pixelColor);
    }
    setTimeout(wait);
  }
}
