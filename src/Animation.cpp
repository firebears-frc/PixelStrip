#include "Animation.h"

void Animation::reset(PixelStrip *strip) {
  //
}

void Animation::draw(PixelStrip *strip) {
  //
}

void Animation::setTimeout(unsigned long milliseconds) {
  _timeout = millis() + milliseconds;
}

int Animation::isTimedout() {
  return (millis() >= _timeout);
}

