#include "Animation.h"
#include <Adafruit_NeoPixel.h>


void Animation::reset(Adafruit_NeoPixel *strip) {
  //
}

void Animation::draw(Adafruit_NeoPixel *strip) {
  //
}

void Animation::setTimeout(unsigned long milliseconds) {
  _timeout = millis() + milliseconds;
}

int Animation::isTimedout() {
  return (millis() >= _timeout);
}

