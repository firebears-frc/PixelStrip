# PixelStrip
Arduino library for [NeoPixel](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels) / WS2812B LED animations.  This library extends  [FastLED](https://fastled.io/).

## TODO
* Fix `_translatePixel` so it works with matrices in all orientation options
* Add PixelStrip_MatrixTest as an example to figure out all orientation options
* Create a `print` function like in NeoMatrix.  Also maybe an icon/sprite library
* Add some interesting matrix animation examples
* Add matrix example code to this README file.

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
