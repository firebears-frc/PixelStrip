#include "SmoothFireAnimation.h"

void SmoothFireAnimation::reset(PixelStrip *strip) {
  strip->begin();
  if (strip->numPixels() > heatSize) {
    if (heatSize > 0) free(heat);
    heatSize = strip->numPixels();
    heat = new float[heatSize] { 0.0 };
  }
  lastDraw = millis();
}

void SmoothFireAnimation::draw(PixelStrip *strip) {
  int size = mirrored ? strip->numPixels() / 2 : strip->numPixels();

  strip->clear();
  float elapsedSeconds = (millis() - lastDraw) / 1000.0;
  float cooldown = 1.0f * randomFloat() * cooling * elapsedSeconds;
  lastDraw = millis();

  for (int i = 0; i < size; i++)  {
    heat[i] = max(0.0f, heat[i] - cooldown);
    int neighborIndex = (i == 0) ? size - 1 : i - 1;
    float spreadAmount = min(0.25f, heat[neighborIndex]) * spreadRate * elapsedSeconds;
    spreadAmount = min(heat[neighborIndex], spreadAmount);
    heat[i] += spreadAmount;
    heat[neighborIndex] -= spreadAmount;
    if (i <= sparkHeight && randomFloat() < sparkProbability * elapsedSeconds) {
      heat[i] = sparkHeat;
    }
  }

  for (int i = 0; i < size; i++) {
    byte t = (byte)(240 * min(1.0f, heat[i]));
    uint32_t color = heatColor(t);
    int j = reversed ? (size - 1 - i) : i;
    strip->setPixelColor(j, color);
    if (mirrored) {
      int j2 = !reversed ? (2 * size - 1 - i) : size + i;
      strip->setPixelColor(j2, color);
    }
  }
}

float SmoothFireAnimation::randomFloat() {
  return random(65536) / 65536.0;
}

uint32_t SmoothFireAnimation::heatColor(byte temperature) {
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