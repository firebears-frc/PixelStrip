#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include <Wire.h>
#include "PulseAnimation.h"

#define PIN 1
#define NUM_PIXELS 8
#define I2C_ADDRESS 4

PixelStrip strip = PixelStrip(NUM_PIXELS, PIN, NEO_GRB);
PulseAnimation *animation1, *animation2, *animation3;
int wireTimeout = 0;

/**
 * Change animations when I2C messages are received.
 */
void setup() {
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveEvent);
  animation1 = new PulseAnimation();
  animation2 = new PulseAnimation();
  animation2->setColor(0, 0x0000ff);
  animation2->setColor(1, 0x888888);
  animation3 = new PulseAnimation(3);
  animation3->setColor(0, 0x880000);
  animation3->setColor(1, 0x444444);
  animation3->setColor(2, 0x000088);
  strip.setup();
  strip.setAnimation(animation1);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  strip.draw();
  strip.show();
  delay(10);
  if (wireTimeout > 0 && millis() > wireTimeout)  {
    digitalWrite(LED_BUILTIN, LOW);
    wireTimeout = 0;
  }
}

void receiveEvent(int howMany) {
  while (Wire.available() > 0) {
    int x = Wire.read();
    switch (x) {
      case 1 :
        strip.setAnimation(animation1);
        break;
      case 2 :
        strip.setAnimation(animation2);
        break;
      case 3 :
        strip.setAnimation(animation3);
        break;
      default :
        strip.setAnimation(0);
    }
    digitalWrite(LED_BUILTIN, HIGH);
    wireTimeout = millis() + 500;
  }
}
