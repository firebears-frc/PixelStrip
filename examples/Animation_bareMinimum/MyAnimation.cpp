#include <Adafruit_NeoPixel.h>
#include "MyAnimation.h"

unsigned long timeout;
unsigned long wait = 500;
int _color = 0x880000;
int q = 0;

void MyAnimation::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  timeout = millis() + wait;
  Serial.begin(9600);
}

void MyAnimation::draw(Adafruit_NeoPixel *strip) {
  if (millis() > timeout) {
    timeout = millis() + wait;
    Serial.print(q); Serial.println(" !!!");
    q + (q + 1) % 3;
    int num = strip->numPixels();
    for (int x = 0; x < num; x++) {
      int c = ((x + q) % 3 == 0) ? _color : 0x000000;
      strip->setPixelColor(x, c);
    }
  }
}

