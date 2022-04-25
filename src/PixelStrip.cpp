#include "PixelStrip.h"

PixelStrip::PixelStrip(CLEDController *controller, uint16_t numPixels)
    : _numPixels(numPixels), _parent(0), _offset(0), _maxX(numPixels), _maxY(0), _options(MATRIX_PROGRESSIVE | MATRIX_ROW_MAJOR | MATRIX_TOP | MATRIX_LEFT)
{
  _led = new CRGB[numPixels];
  clear();
  _animation = 0;
  _wrap = false;
  FastLED.addLeds(controller, _led, _numPixels, 0);
}

PixelStrip::PixelStrip(CLEDController *controller, uint16_t width, uint16_t height)
    : _numPixels(width * height), _parent(0), _offset(0), _maxX(width), _maxY(height), _options(MATRIX_PROGRESSIVE | MATRIX_ROW_MAJOR | MATRIX_TOP | MATRIX_LEFT)
{
  _led = new CRGB[_numPixels];
  clear();
  _animation = 0;
  _wrap = false;
  FastLED.addLeds(controller, _led, _numPixels, 0);
}

PixelStrip::PixelStrip(CLEDController *controller, uint16_t width, uint16_t height, uint32_t options)
    : _numPixels(width * height), _parent(0), _offset(0), _maxX(width), _maxY(height), _options(options)
{
  _led = new CRGB[_numPixels];
  clear();
  _animation = 0;
  _wrap = false;
  FastLED.addLeds(controller, _led, _numPixels, 0);
}

PixelStrip::PixelStrip(PixelStrip *parent, uint16_t numPixels, uint16_t offset)
    : _numPixels(numPixels), _parent(parent), _offset(offset), _maxX(numPixels), _maxY(0), _options(MATRIX_PROGRESSIVE | MATRIX_ROW_MAJOR | MATRIX_TOP | MATRIX_LEFT)
{
  _animation = 0;
  _wrap = false;
}

void PixelStrip::setWrap(boolean b)
{
  _wrap = b;
}

void PixelStrip::begin(void)
{
}

void PixelStrip::show(void)
{
  FastLED.show();
}

void PixelStrip::setPixelColor(uint16_t n, uint32_t c)
{
  if (_parent)
  {
    _parent->setPixelColor(n + _offset, c);
  }
  else if (n >= 0 && n < _numPixels)
  {
    _led[n] = c;
  }
  else if (_wrap)
  {
    uint16_t nn = n;
    while (nn >= _numPixels)
      nn -= _numPixels;
    while (nn < 0)
      nn += _numPixels;
    _led[nn] = c;
  }
}

void PixelStrip::setPixelColor(uint16_t x, uint16_t y, uint32_t c)
{
  if ((x < 0) || (y < 0) || (x > _maxX) || (y > _maxY))
    return;
  setPixelColor(_translatePixel(x, y), c);
}

uint16_t PixelStrip::_translatePixel(uint16_t x, uint16_t y)
{
  uint16_t xx = x;
  uint16_t yy = y;

  if ((_options & MATRIX_TOP) && (_options & MATRIX_RIGHT))  {
    xx = y;
    yy = _maxY - (x + 1);
  } else if ((_options & MATRIX_BOTTOM) && (_options & MATRIX_RIGHT)) {
    xx = _maxX - (x + 1);
    yy = _maxY - (y + 1);
  } else if ((_options & MATRIX_BOTTOM) && (_options & MATRIX_LEFT)) {
    xx = _maxX - (y + 1);
    yy = x;
  } else {
    xx = x;
    yy = y;
  }

  if (_options & MATRIX_ZIGZAG)  {
      if ((_options & MATRIX_COLUMN_MAJOR) && (xx % 2 == 1)) {
        yy = _maxY - (yy + 1);
      } else if ((_options & MATRIX_ROW_MAJOR) && (yy % 2 == 1)) {
        xx = _maxX - (xx + 1);
      }
  }

  if (_options & MATRIX_COLUMN_MAJOR)
    return xx * _maxY + yy;
  else
    return xx + yy * _maxX;
}

void PixelStrip::setBrightness(uint8_t b)
{
  FastLED.setBrightness(b);
}

void PixelStrip::clear(void)
{
  for (uint16_t n = 0; n < _numPixels; n++)
  {
    setPixelColor(n, CRGB::Black);
  }
}

void PixelStrip::fillScreen(uint32_t c)
{
  for (uint16_t n = 0; n < _numPixels; n++)
  {
    setPixelColor(n, c);
  }
}

uint16_t PixelStrip::numPixels(void)
{
  return _numPixels;
}

uint16_t PixelStrip::maxX(void)
{
  return _maxX;
}

uint16_t PixelStrip::maxY(void)
{
  return _maxY;
}

void PixelStrip::setAnimation(Animation *animation)
{
  _animation = animation;
  if (_animation)
  {
    _animation->reset(this);
  }
  else
  {
    clear();
  }
}

void PixelStrip::setup()
{
  if (_animation)
  {
    _animation->reset(this);
  }
  begin();
}

void PixelStrip::draw()
{
  if (_animation)
  {
    _animation->draw(this);
  }
}

void PixelStrip::setTimeout(unsigned long milliseconds)
{
  _timeout = millis() + milliseconds;
}

int PixelStrip::isTimedout()
{
  return (millis() >= _timeout);
}
