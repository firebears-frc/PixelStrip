#ifndef Animation_h
#define Animation_h
#include <Adafruit_NeoPixel.h>

/**
 * Abstract parent class for other animation classes.
 */
class Animation {
public:
  virtual void reset(Adafruit_NeoPixel *strip);
  virtual void draw(Adafruit_NeoPixel *strip);
  virtual void setTimeout(unsigned long milliseconds);
  virtual int isTimedout();
  unsigned long _timeout;
};
#endif


