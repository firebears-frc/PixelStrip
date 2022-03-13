#include "PixelStrip.h"

PixelStrip::PixelStrip(CLEDController *controller, uint16_t numPixels)
  :  _numPixels(numPixels), _parent(0), _offset(0), _maxX(numPixels), _maxY(0), _options(ORTHOGONAL)
{
  _led = new CRGB[numPixels];
  clear();
  _animation = 0;
  _wrap = false;
  FastLED.addLeds(controller, _led, _numPixels, 0);
}

PixelStrip::PixelStrip(CLEDController *controller, uint16_t width, uint16_t height)
  :  _numPixels(width * height), _parent(0), _offset(0), _maxX(width), _maxY(height), _options(ORTHOGONAL)
{
  _led = new CRGB[_numPixels];
  clear();
  _animation = 0;
  _wrap = false;
  FastLED.addLeds(controller, _led, _numPixels, 0);
}

PixelStrip::PixelStrip(CLEDController *controller, uint16_t width, uint16_t height, uint32_t options)
  :  _numPixels(width * height), _parent(0), _offset(0), _maxX(width), _maxY(height), _options(options)
{
  _led = new CRGB[_numPixels];
  clear();
  _animation = 0;
  _wrap = false;
  FastLED.addLeds(controller, _led, _numPixels, 0);
}

PixelStrip::PixelStrip(PixelStrip *parent, uint16_t numPixels, uint16_t offset)
  : _numPixels(numPixels), _parent(parent), _offset(offset), _maxX(numPixels), _maxY(0), _options(ORTHOGONAL)
{
  _animation = 0;
  _wrap = false;
}

void PixelStrip::setWrap(boolean b) {
  _wrap = b;
}

void PixelStrip::begin(void)  {
}

void PixelStrip::show(void) {
  FastLED.show();
}

void PixelStrip::setPixelColor(uint16_t n, uint32_t c) {
  if (_parent) {
    _parent->setPixelColor(n + _offset, c);
  } else if (n >= 0 && n < _numPixels) {
    _led[n] = c;
  } else if (_wrap) {
    uint16_t nn = n;
    while (nn >= _numPixels) nn -= _numPixels;
    while (nn < 0) nn += _numPixels;
    _led[nn] = c;
  }
}

void PixelStrip::setPixelColor(uint16_t x, uint16_t y, uint32_t c) {
  if ((_options & ZIGZAG) && (y % 2 == 1)) {
    setPixelColor((_maxX - (x + 1)) + y * _maxX, c);
  } else {
    setPixelColor(x + y * _maxX, c);
  }
}

void PixelStrip::setBrightness(uint8_t b) {
  FastLED.setBrightness(b);
}

void PixelStrip::clear(void) {
  for (uint16_t n = 0; n < _numPixels; n++) {
    setPixelColor(n, CRGB::Black);
  }
}

uint16_t PixelStrip::numPixels(void) {
  return _numPixels;
}

uint16_t PixelStrip::maxX(void) {
  return _maxX;
}

uint16_t PixelStrip::maxY(void) {
  return _maxY;
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

