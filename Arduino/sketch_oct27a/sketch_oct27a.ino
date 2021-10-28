#include <FastLED.h>

#define NUM_LEDS 60
#define LED_PIN 2

CRGB leds [NUM_LEDS] ;


void setup () {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness (50);
  
}

void loop () {
  leds[0] = CRGB::Red;
  leds[2] = CRGB::Green;
  leds[3] = CRGB::Blue;
  FastLED.show () ;
}
