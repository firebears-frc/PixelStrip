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
PixelStrip *strip = new PixelStrip((new NEOPIXEL<PIN>), NUM_PIXELS);
int mode = 0;

void setup() {
  redAnimation = new SpinningAnimation();
  redAnimation->color = RED;
  greenAnimation = new SpinningAnimation();
  greenAnimation->color = GREEN;
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(redAnimation);
  strip->setTimeout(1);
  strip->setup();
}

void loop() {
  strip->draw();
  strip->show();

  if (strip->isTimedout()) {
    mode = (mode + 1) % 3;
    if (mode == 1) {
      strip->setAnimation(redAnimation);
    } else if (mode == 2) {
      strip->setAnimation(greenAnimation);
    } else {
      strip->setAnimation(0);
    }
    strip->setTimeout(3000);
  }
}
