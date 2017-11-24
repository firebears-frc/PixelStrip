#include <Adafruit_NeoPixel.h>
#include "SpinningAnimation.h"

uint32_t _black;
int _current_pixel;

void SpinningAnimation::reset(Adafruit_NeoPixel *strip) {
  _black = strip->Color(0, 0, 0);
  _current_pixel = 0;
  _time_delay = 1000.0 / strip->numPixels();
}

void SpinningAnimation::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    strip->setPixelColor(_current_pixel, _black);
    _current_pixel = _current_pixel + 1;
    if (_current_pixel >= strip->numPixels()) {
      _current_pixel = 0;
    }
    strip->setPixelColor(_current_pixel, _color);
    setTimeout(_time_delay);
  }
}
