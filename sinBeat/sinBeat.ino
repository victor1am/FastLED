#define FASTLED_INTERNAL
#include <FastLED.h>

#define NUM_LEDS 60
#define LED_PIN 2

CRGB leds [NUM_LEDS];


void setup () {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness (50);
  Serial.begin(57600);
}

void loop() {
  uint8_t sinBeat = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
  uint8_t sinBeat2 = beatsin8(30, 0, NUM_LEDS - 1, 0, 85);
  uint8_t sinBeat3 = beatsin8(30, 0, NUM_LEDS - 1, 0, 170);

leds[sinBeat] = CRGB::Blue;
leds[sinBeat2] = CRGB::Red;
leds[sinBeat3] = CRGB::Green2;

fadeToBlackBy (leds, NUM_LEDS, 100);

EVERY_N_MILLISECONDS(10) {
  Serial.print(sinBeat);
  Serial.print(".");
  Serial.print(sinBeat2);
  Serial.print(".");  
  Serial.print(sinBeat3);
}
   FastLED.show(); 
 
 }

 
