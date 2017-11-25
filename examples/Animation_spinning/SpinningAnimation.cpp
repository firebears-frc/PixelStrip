#include <Adafruit_NeoPixel.h>
#include "SpinningAnimation.h"

uint32_t black;
int current_pixel;

void SpinningAnimation::reset(Adafruit_NeoPixel *strip) {
  black = strip->Color(0, 0, 0);
  current_pixel = 0;
  time_delay = 1000.0 / strip->numPixels();
}

void SpinningAnimation::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    strip->setPixelColor(current_pixel, black);
    current_pixel = current_pixel + 1;
    if (current_pixel >= strip->numPixels()) {
      current_pixel = 0;
    }
    strip->setPixelColor(current_pixel, color);
    setTimeout(time_delay);
  }
}
