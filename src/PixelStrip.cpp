#include "PixelStrip.h"
#include <Adafruit_NeoPixel.h>

PixelStrip::PixelStrip(uint16_t num, uint8_t pin) 
: 
Adafruit_NeoPixel(num, pin, NEO_GRB + NEO_KHZ800) {
	_animation = 0;
}

PixelStrip::PixelStrip(uint16_t num, uint8_t pin, uint8_t npType)
:
Adafruit_NeoPixel(num, pin, npType + NEO_KHZ800) {
        _animation = 0;
}

void PixelStrip::setAnimation(Animation *animation)  {
	_animation = animation;
	if (_animation) {
		_animation->reset(this);
	} else {
		clear();
	}
}

void PixelStrip::setup() {
  if (_animation) {
	  _animation->reset(this);
  }
  begin();
}

void PixelStrip::draw() {
  if (_animation) {
	  _animation->draw(this);
  } 
}

void PixelStrip::setTimeout(unsigned long milliseconds) {
  _timeout = millis() + milliseconds;
}

int PixelStrip::isTimedout() {
  return (millis() >= _timeout);
}

