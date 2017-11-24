#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include "SpinningAnimation.h"

#define PIN 7
#define NUM_PIXELS 8

/**
 * Test NeoPixel program that allows animations to be plugged into 
 * a pixel strip.
 * Switch to a new animation every three seconds.
 */
 
SpinningAnimation *redAnimation, *greenAnimation;
PixelStrip strip = PixelStrip(NUM_PIXELS, PIN, NEO_GRBW);
int mode = 0;
long timeout;

void setup() {
  redAnimation = new SpinningAnimation();
  redAnimation->_color = 0x880000;
  greenAnimation = new SpinningAnimation();
  greenAnimation->_color = 0x008800;
  strip.setup();
  strip.setAnimation(redAnimation);
  timeout = millis() + 3000;
}



void loop() {
  strip.draw();
  strip.show();
  delay(5);

  if (millis() > timeout) {
    mode = (mode + 1) % 3;
    if (mode == 1) {
      strip.setAnimation(redAnimation);
    } else if (mode == 2) {
      strip.setAnimation(greenAnimation);
    } else {
      strip.setAnimation(0);
    }
    timeout = millis() + 3000;
  }
}
