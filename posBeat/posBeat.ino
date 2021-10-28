#include <FastLED.h>
#define NUM_LEDS 60
#define LED_PIN 2

CRGB leds [NUM_LEDS];



void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness (50);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t posBeat = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
  uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);
  uint8_t colBeat = beatsin8(45, 0, 255, 0, 0);
  leds[(posBeat + posBeat2) / 2] = CHSV(colBeat, 255, 255);
  fadeToBlackBy(leds, NUM_LEDS, 10);
  FastLED.show();
}
