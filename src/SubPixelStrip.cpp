#include "SubPixelStrip.h"

SubPixelStrip::SubPixelStrip(uint16_t num, PixelStrip *parent, uint16_t offset)  :
PixelStrip(parent->numPixels(), parent->getPin())
{
  _animation = 0;
  _num = num;
  _parent = parent;
  _offset = offset;
}

void SubPixelStrip::clear() {
  uint32_t black = _parent->Color(0, 0, 0);
  for (uint16_t i = 0; i < _num; i++) {
    setPixelColor(i, black);
  }
}

void SubPixelStrip::begin(void) {
 // _parent->begin();
}

void SubPixelStrip::show(void) {
  _parent->show();
}

uint16_t SubPixelStrip::numPixels(void) {
  return _num;
}

void SubPixelStrip::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
  _parent->setPixelColor(n + _offset, r, g, b);
}

void SubPixelStrip::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
  _parent->setPixelColor(n + _offset, r, g, b, w);
}

void SubPixelStrip::setPixelColor(uint16_t n, uint32_t c) {
  _parent->setPixelColor(n + _offset, c);
}


