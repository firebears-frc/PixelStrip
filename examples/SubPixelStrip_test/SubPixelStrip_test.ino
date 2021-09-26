#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <SubPixelStrip.h>
#include <Animation.h>
#include <Wire.h>
#include "PulseAnimation.h"

const int PIN = 4;
const int BRIGHTNESS = 128;
const int NUM_PIXELS = 8;

PixelStrip *strip;
SubPixelStrip *redStrip, *greenStrip;
PulseAnimation *redAnimation, *greenAnimation;


void setup() {

  // set up all Animations
  redAnimation = new PulseAnimation();
  redAnimation->setColor(0, 0xff0000);
  redAnimation->setColor(1, 0x888888);
  greenAnimation = new PulseAnimation();
  greenAnimation->setColor(0, 0x00ff00);
  greenAnimation->setColor(1, 0x444444);

  // set up all PixelStrips
  strip = new PixelStrip(NUM_PIXELS, PIN, NEO_GRBW);
  strip->setBrightness(BRIGHTNESS);
  int halfPixels = NUM_PIXELS / 2;
  redStrip = new SubPixelStrip(halfPixels, strip, 0);
  greenStrip = new SubPixelStrip(NUM_PIXELS - halfPixels, strip, halfPixels);
  redStrip->setAnimation(redAnimation);
  greenStrip->setAnimation(greenAnimation);

  // assign Animations
  strip->begin();
  strip->clear();
  strip->show();
}

void loop() {
  redStrip->draw();
  greenStrip->draw();
  strip->show();
  delay(10);
}


