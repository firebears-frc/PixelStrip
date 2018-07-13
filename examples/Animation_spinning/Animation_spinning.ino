#include <PixelStrip.h>
#include "SpinningAnimation.h"

const int PIN = 7;
const int NUM_PIXELS = 8;
const int BRIGHTNESS = 128;

/**
 * Test NeoPixel program that allows animations to be plugged into 
 * a pixel strip.
 * Switch to a new animation every three seconds.
 */
 
SpinningAnimation *redAnimation, *greenAnimation;
PixelStrip *strip = new PixelStrip(NUM_PIXELS, PIN);
int mode = 0;
long timeout;

void setup() {
  redAnimation = new SpinningAnimation();
  redAnimation->color = 0x880000;
  greenAnimation = new SpinningAnimation();
  greenAnimation->color = 0x008800;
  strip->setup();
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(redAnimation);
  timeout = millis() + 3000;
}



void loop() {
  strip->draw();
  strip->show();
  delay(5);

  if (millis() > timeout) {
    mode = (mode + 1) % 3;
    if (mode == 1) {
      strip->setAnimation(redAnimation);
    } else if (mode == 2) {
      strip->setAnimation(greenAnimation);
    } else {
      strip->setAnimation(0);
    }
    timeout = millis() + 3000;
  }
}
