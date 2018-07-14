#include "PixelStrip.h"

PixelStrip::PixelStrip(CLEDController *controller, uint16_t numPixels) : _numPixels(numPixels) {
  _led = new CRGB[numPixels];
  clear();
  _animation = 0;
  FastLED.addLeds(controller, _led, _numPixels, 0);
}

void PixelStrip::begin(void)  {
}

void PixelStrip::show(void) {
  FastLED.show();
}

void PixelStrip::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
  _led[n] = ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

void PixelStrip::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
  _led[n] = ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

void PixelStrip::setPixelColor(uint16_t n, uint32_t c) {
  _led[n] = c;
}

void PixelStrip::setBrightness(uint8_t b) {
  FastLED.setBrightness(b);
}

void PixelStrip::clear(void) {
  for (uint16_t n = 0; n < _numPixels; n++) {
    _led[n] = CRGB::Black;
  }
}

uint16_t PixelStrip::numPixels(void) {
  return _numPixels;
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

