#ifndef Animation_h
#define Animation_h
#include <FastLED.h>

class PixelStrip;

/**
 * Abstract parent class for other animation classes.
 */
class Animation {
  
public:
  virtual void reset(PixelStrip *strip);
  virtual void draw(PixelStrip *strip);
  void setTimeout(unsigned long milliseconds);
  int isTimedout();
  
private:
  unsigned long _timeout;
};
#endif
