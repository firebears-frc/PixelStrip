#include "FrameAnimation.h"

void FrameAnimation::reset(PixelStrip *strip) {
  strip->begin();
  setTimeout(waitTime);
}

void FrameAnimation::draw(PixelStrip *strip) {
  if (isTimedout()) {
    strip->clear();
    pixelState = (pixelState + 1) % 4;
    int mode = pixelState;

    for (int x = 0; x < strip->maxX() - 1; x++) {
      strip->setPixelColor(x, 0, pickColor(mode++, color));
    }

    for (int y = 0; y < strip->maxY() - 1; y++) {
      strip->setPixelColor(strip->maxX() - 1, y, pickColor(mode++, color));
    }

    for (int x = strip->maxX() - 1; x > 0; x--) {
      strip->setPixelColor(x, strip->maxY() - 1, pickColor(mode++, color));
    }

    for (int y = strip->maxY() - 1; y > 0; y--) {
      strip->setPixelColor(0, y, pickColor(mode++, color));
    }

    setTimeout(waitTime);
  }
}

uint32_t FrameAnimation::pickColor(int mode, uint32_t c) {
  return (mode % 4) < 2 ? c : BLACK;
}
