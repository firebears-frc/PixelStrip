#include "FireAnimation.h"

void FireAnimation::reset(PixelStrip *strip) {
  strip->begin();
  if (strip->numPixels() > heatSize) {
    if (heatSize > 0) free(heat);
    heatSize = strip->numPixels();
    heat = new byte[heatSize] { 0 };
  }
  blendTotal = (blendSelf + blendNeighbor1 + blendNeighbor2 + blendNeighbor3);
}

void FireAnimation::draw(PixelStrip *strip) {
  int size = mirrored ? strip->numPixels() / 2 : strip->numPixels();

  // First cool each cell by a little bit
  int coolRange = ((cooling * 10) / size) + 2;
  for (int i = 0; i < size; i++) {
    int t = heat[i] - random(0, coolRange);
    heat[i] = max(0L, t);
  }

  // Next drift heat up and diffuse it a little but
  for (int i = 0; i < size; i++)
    heat[i] = (heat[i] * blendSelf +
               heat[(i + 1) % size] * blendNeighbor1 +
               heat[(i + 2) % size] * blendNeighbor2 +
               heat[(i + 3) % size] * blendNeighbor3)
              / blendTotal;

  // Randomly ignite new sparks down in the flame kernel
  for (int i = 0; i < sparks; i++) {
    if (random(255) < sparking) {
      int y = size - 1 - random(sparkHeight);
      int t = heat[y] + random(160, 255);
      heat[y] = min(255, t);
    }
  }

  // Finally convert heat to a color
  for (int i = 0; i < size; i++) {
    byte t = (byte)heat[i];
    uint32_t color = heatColor(t);
    int j = reversed ? (size - 1 - i) : i;
    strip->setPixelColor(j, color);
    if (mirrored) {
      int j2 = !reversed ? (2 * size - 1 - i) : size + i;
      strip->setPixelColor(j2, color);
    }
  }
}

uint32_t FireAnimation::heatColor(byte temperature) {
  uint8_t t192 = scale8_video(temperature, 191);
  uint8_t heatramp = t192 & 0x3F;  // 0..63
  heatramp <<= 2;                  // 0 .. 252
  if ( t192 & 0x80) {
    return ((uint32_t)255 << 16) | ((uint32_t)255 <<  8) | heatramp;
  } else if ( t192 & 0x40 ) {
    return ((uint32_t)255 << 16) | ((uint32_t)heatramp <<  8);
  } else {
    return ((uint32_t)heatramp << 16);
  }
}