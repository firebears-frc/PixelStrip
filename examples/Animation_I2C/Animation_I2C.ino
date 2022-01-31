#include <PixelStrip.h>
#include <Wire.h>
#include "PulseAnimation.h"

const int MAX_ANIMATIONS = 3;
const int MAX_PIXELSTRIPS = 1;
const int BRIGHTNESS = 128;
const int I2C_ADDRESS = 4;

PixelStrip *strip[MAX_PIXELSTRIPS];
PulseAnimation *animation[MAX_ANIMATIONS];
int wireTimeout = 0;

/**
   Change animations when I2C messages are received.
   When a message is received, the built-in LED will flash for a half second.
*/
void setup() {
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveEvent);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // set up all Animations
  animation[0] = new PulseAnimation();
  animation[1] = new PulseAnimation();
  animation[1]->setColor(0, BLUE);
  animation[1]->setColor(1, GRAY);
  animation[2] = new PulseAnimation(3);
  animation[2]->setColor(0, RED);
  animation[2]->setColor(1, DIMGREY);
  animation[2]->setColor(2, BLUE);

  // set up all PixelStrips
  CLEDController *controller[] = {new NEOPIXEL<7>};
  for (int s = 0; s < MAX_PIXELSTRIPS; s++) {
    strip[s] = new PixelStrip(controller[s], 8);
    strip[s]->setAnimation(animation[0]);
    strip[s]->setBrightness(BRIGHTNESS);
    strip[s]->setup();
  }
  Serial.begin(9600);
}

void loop() {
  for (int s = 0; s < MAX_PIXELSTRIPS; s++) {
    strip[s]->draw();
    strip[s]->show();
  }
  delay(10);
  if (wireTimeout > 0 && millis() > wireTimeout)  {
    digitalWrite(LED_BUILTIN, LOW);
    wireTimeout = 0;
  }
}

/**
   Expects to receive two characters.
   The first character specifies the pixel strip number.
   The second character sets the animation number on that strip.
*/
void receiveEvent(int howMany) {
  while (Wire.available() > 0) {
    int s = Wire.read() - '0';
    int a = Wire.read() - '0';
    if (a >= 0 && a < MAX_ANIMATIONS) {
      strip[s]->setAnimation(animation[a]);
    } else {
      strip[s]->setAnimation(0);
    }
    digitalWrite(LED_BUILTIN, HIGH);
    wireTimeout = millis() + 500;
    Serial.print("receiveEvent(");
    Serial.print(s); Serial.print(",");
    Serial.print(a); Serial.println(")");
  }
}
