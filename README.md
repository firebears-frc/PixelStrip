# PixelStrip
Arduino library for [NeoPixel](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels) / WS2812B LED animations.  This library extends  [FastLED](https://fastled.io/).

## TODO
* Create a `print` function like in NeoMatrix.  Also maybe an icon/sprite library
* Add some interesting matrix animation examples

## Installation
The `PixelStrip.zip` file can be created by the `build.sh` script (on either Mac or Linux).  To install into your Arduino IDE:

* Sketch > Include Library > Manage Libraries and then install the FastLED library.
* Sketch > Include Library > Add ZIP Library and then add the `PixelStrip.zip` file.

## Sample Code

```
#include <PixelStrip.h>

const int PIN = 7;
const int NUM_PIXELS = 8;
const int BRIGHTNESS = 128;
int state = 0;

PixelStrip *strip = new PixelStrip((new NEOPIXEL<PIN>), NUM_PIXELS);

void setup() {
  strip->setBrightness(BRIGHTNESS);
  strip->clear();
  strip->setup();
  strip->setTimeout(1);
}

void loop() {
  if (strip->isTimedout()) {
    uint32_t color = ((state++) % 2 == 0) ? RED : GRAY;
    strip->setPixelColor(0, color);
    strip->show();
    strip->setTimeout(500);
  }
}
```

## Arduino wiring

![Uno setup](uno_setup.png)

## Matrix Example

```
#include <PixelStrip.h>

const int PIN = 7;
const int MAX_X = 8;
const int MAX_Y = 8;
const int BRIGHTNESS = 128;
const int TIME = 20;

PixelStrip *strip = new PixelStrip((new NEOPIXEL<PIN>), MAX_X, MAX_Y, MATRIX_TOP | MATRIX_LEFT);

void setup() {
  strip->setBrightness(BRIGHTNESS);
  strip->setup();
}

void loop() {

  // Blink the zero pixel as RED
  for (int i = 0; i < 8; i++) {
    strip->setPixelColor(0, RED);
    strip->show();
    delay(TIME);
    strip->clear();
    strip->show();
    delay(TIME / 2);
  }
  delay(500);

  // Blink the origin pixel as GREEN
  for (int i = 0; i < 8; i++) {
    strip->setPixelColor(0, 0, GREEN);
    strip->show();
    delay(TIME);
    strip->clear();
    strip->show();
    delay(TIME / 2);
  }
  delay(500);

  // Blink pixels in sequence as YELLOW
  for (int p = 0; p < MAX_X * MAX_Y; p++) {
    strip->setPixelColor(p, YELLOW);
    strip->show();
    delay(TIME);
    strip->clear();
    strip->show();
    delay(TIME / 2);
  }
  delay(500);

  // Blink each row as BLUE or WHITE, top to bottom and left to right
  for (int y = 0; y < MAX_Y; y++) {
    uint32_t c = (y % 2 == 0) ? BLUE : WHITE;
    for (int x = 0; x < MAX_X; x++) {
      strip->setPixelColor(x, y, c);
      strip->show();
      delay(TIME * 2);
      strip->clear();
      strip->show();
      delay(TIME);
    }
  }

  delay(500);
}
```
