#include <Adafruit_NeoPixel.h>
#include <FastLED.h>

#define PIN1 3          // Pin to which the first LED strip is connected
#define NUMPIXELS1 185  // Number of LEDs in the first strip

#define PIN2 5          // Pin to which the second LED strip is connected
#define NUMPIXELS2 180  // Number of LEDs in the second strip

#define RELAY_PIN1 7  // D7 pin for relay 1
#define RELAY_PIN2 8  // D8 pin for relay 2

#define DIM_FACTOR 1  // Dimming factor (10% brightness)
#define MATRIX_PIN 6
#define RELAY_ON_DURATION 100  // Duration for which the relay will be turned on in milliseconds (10 seconds)

#define MATRIX_WIDTH 8
#define MATRIX_HEIGHT 8
#define SPEED 50  // Speed of movement (lower value means faster movement)

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
CRGB leds[MATRIX_WIDTH * MATRIX_HEIGHT];

// Function to set a pixel color with dimming
void setDimmedPixelColor(Adafruit_NeoPixel& strip, int pixel, uint8_t r, uint8_t g, uint8_t b) {
  strip.setPixelColor(pixel, strip.Color((uint8_t)(g * DIM_FACTOR), (uint8_t)(r * DIM_FACTOR), (uint8_t)(b * DIM_FACTOR)));  // GRB order
}

unsigned long previousMillis = 0;  // Variable to store the last time the relay was turned on


void setup() {
  pinMode(RELAY_PIN1, OUTPUT);
  strip1.begin();  // Initialize the first strip
  strip1.show();   // Initialize all pixels to 'off'
  strip2.begin();  // Initialize the second strip
  strip2.show();   // Initialize all pixels to 'off'
  FastLED.addLeds<WS2812B, MATRIX_PIN, GRB>(leds, MATRIX_WIDTH * MATRIX_HEIGHT);
  FastLED.setBrightness(100);
  FastLED.clear();
  FastLED.show();
  digitalWrite(RELAY_PIN1, LOW);  // Start with relay off

  delay(500);
}
const uint8_t mWidth = 10;
const uint8_t mHeight = 25;
const uint8_t NUM_LEDS = mWidth * mHeight;




void loop() {
  

  for (int i = 0; i < NUMPIXELS1; i++) {
    if (i < NUMPIXELS1) {
      setDimmedPixelColor(strip1, i, 0, 0, 255);
    }
    if (i < NUMPIXELS2) {
      setDimmedPixelColor(strip2, i, 0, 0, 255);
    }
    strip1.show();
    strip2.show();
    delay(20);
  }

  // Set all pixels to yellow (10% brightness) one by one for both strips
  for (int i = 0; i < NUMPIXELS1; i++) {
    if (i < NUMPIXELS1) {
      setDimmedPixelColor(strip1, i, 240, 180, 0);
    }
    if (i < NUMPIXELS2) {
      setDimmedPixelColor(strip2, i, 180, 240, 0);
    }
    strip1.show();
    strip2.show();
    delay(20);
  }

  // Set all pixels to red (10% brightness) one by one for both strips
  for (int i = 0; i < NUMPIXELS1; i++) {
    if (i < NUMPIXELS1) {
      setDimmedPixelColor(strip1, i, 255, 0, 0);
    }
    if (i < NUMPIXELS2) {
      setDimmedPixelColor(strip2, i, 0, 255, 0);
    }
    strip1.show();
    strip2.show();
    delay(20);
  }

  // Set all pixels to white (10% brightness) one by one for both strips
  for (int i = 0; i < NUMPIXELS1; i++) {
    if (i < NUMPIXELS1) {
      setDimmedPixelColor(strip1, i, 255, 255, 255);
    }
    if (i < NUMPIXELS2) {
      setDimmedPixelColor(strip2, i, 255, 255, 255);
    }
    strip1.show();
    strip2.show();
    delay(20);
  }

  // Set all pixels to orange (10% brightness) one by one for both strips
  for (int i = 0; i < NUMPIXELS1; i++) {
    if (i < NUMPIXELS1) {
      setDimmedPixelColor(strip1, i, 255, 100, 0);
    }
    if (i < NUMPIXELS2) {
      setDimmedPixelColor(strip2, i, 255, 100, 0);
    }
    strip1.show();
    strip2.show();
    delay(20);
  }

  patternRainbow();
  patternMosaic();
  patternRandomFlash();
  patternChasingLights();
  patternFallingRain();
  patternDiagonalSweep();
  patternBreathingLight();
  patternCheckerboard();

  patternLightning();
  patternGradientFill();
  patternColorWipe();

  patternMeteorShower();
  patternFireEffect();
  patternSparkles();
  patternColorFade();
  patternBlue();
  delay(1000);
  patternYellow();
  delay(1000);
  patternRed();
  delay(1000);
  patternWhite();
  delay(1000);
  patternOrange();
  delay(1000);

  patternNoisePattern();
  patternFireworks();
  patternRippleEffect();
  patternHeartbeat();
  patternSpiral();
  patternPulsingCircle();

}

void patternRainbow() {
  uint16_t i, j;
  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip1.numPixels(); i++) {
      strip1.setPixelColor(i, Wheel((i + j) & 255));
    }
    for (i = 0; i < strip2.numPixels(); i++) {
      strip2.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip1.show();
    strip2.show();
    delay(20);
  }
}

void patternSparkles() {
  for (int i = 0; i < 50; i++) {
    int pixel1 = random(NUMPIXELS1);
    int pixel2 = random(NUMPIXELS2);
    setDimmedPixelColor(strip1, pixel1, random(255), random(255), random(255));
    setDimmedPixelColor(strip2, pixel2, random(255), random(255), random(255));
    strip1.show();
    strip2.show();
    delay(50);
    setDimmedPixelColor(strip1, pixel1, 0, 0, 0);
    setDimmedPixelColor(strip2, pixel2, 0, 0, 0);
  }
}

void patternColorFade() {
  for (int r = 0; r <= 255; r++) {
    for (int g = 0; g <= 255; g++) {
      for (int b = 0; b <= 255; b++) {
        for (int i = 0; i < NUMPIXELS1; i++) {
          setDimmedPixelColor(strip1, i, r, g, b);
        }
        for (int i = 0; i < NUMPIXELS2; i++) {
          setDimmedPixelColor(strip2, i, r, g, b);
        }
        strip1.show();
        strip2.show();
        delay(10);
      }
    }
  }
}

void patternFireEffect() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, random(128), random(255), 0);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, random(128), random(255), 0);
  }

  strip1.show();
  strip2.show();
  delay(10);
}


void patternScrollingText() {
  // Implement scrolling text logic here
}


void patternMosaic() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    int r = random(3);  // Generate random number between 0 and 2
    CRGB color;
    if (r == 0) {
      color = CRGB::Blue;  // Set color to blue
    } else if (r == 1) {
      color = CRGB::Red;  // Set color to red
    } else {
      color = CRGB::White;  // Set color to white
    }
    setDimmedPixelColor(strip1, i, color.r, color.g, color.b);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    int r = random(3);  // Generate random number between 0 and 2
    CRGB color;
    if (r == 0) {
      color = CRGB::Blue;  // Set color to blue
    } else if (r == 1) {
      color = CRGB::Red;  // Set color to red
    } else {
      color = CRGB::White;  // Set color to white
    }
    setDimmedPixelColor(strip2, i, color.r, color.g, color.b);
  }
  strip1.show();
  strip2.show();
  delay(2000);
}

void patternChasingLights() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, 255, 0, 0);
    strip1.show();
    delay(50);
    setDimmedPixelColor(strip1, i, 0, 0, 0);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, 0, 255, 0);
    strip2.show();
    delay(50);
    setDimmedPixelColor(strip2, i, 0, 0, 0);
  }
}

void patternMeteorShower() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, 255, 255, 255);
    if (i > 2) {
      setDimmedPixelColor(strip1, i - 3, 0, 0, 0);
    }
    strip1.show();
    delay(100);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, 255, 255, 255);
    if (i > 2) {
      setDimmedPixelColor(strip2, i - 3, 0, 0, 0);
    }
    strip2.show();
    delay(100);
  }
}

void patternHeartbeat() {
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < NUMPIXELS1; j++) {
      setDimmedPixelColor(strip1, j, i, 0, 0);
    }
    for (int j = 0; j < NUMPIXELS2; j++) {
      setDimmedPixelColor(strip2, j, i, 0, 255);
    }
    strip1.show();
    strip2.show();
    delay(5);
  }
  for (int i = 255; i >= 0; i--) {
    for (int j = 0; j < NUMPIXELS1; j++) {
      setDimmedPixelColor(strip1, j, i, 0, 0);
    }
    for (int j = 0; j < NUMPIXELS2; j++) {
      setDimmedPixelColor(strip2, j, i, 0, 0);
    }
    strip1.show();
    strip2.show();
    delay(5);
  }
}

void patternCheckerboard() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    if ((i / 10) % 2 == 0) {
      setDimmedPixelColor(strip1, i, 0, 255, 0);
    } else {
      setDimmedPixelColor(strip1, i, 0, 0, 255);
    }
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    if ((i / 10) % 2 == 0) {
      setDimmedPixelColor(strip2, i, 0, 255, 0);
    } else {
      setDimmedPixelColor(strip2, i, 0, 0, 255);
    }
  }
  strip1.show();
  strip2.show();
  delay(500);
}

void patternBreathingLight() {
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < NUMPIXELS1; j++) {
      setDimmedPixelColor(strip1, j, 0, 0, i);
    }
    for (int j = 0; j < NUMPIXELS2; j++) {
      setDimmedPixelColor(strip2, j, 0, 0, i);
    }
    strip1.show();
    strip2.show();
    delay(5);
  }
  for (int i = 255; i >= 0; i--) {
    for (int j = 0; j < NUMPIXELS1; j++) {
      setDimmedPixelColor(strip1, j, 0, 0, i);
    }
    for (int j = 0; j < NUMPIXELS2; j++) {
      setDimmedPixelColor(strip2, j, 0, 0, i);
    }
    strip1.show();
    strip2.show();
    delay(5);
  }
}

void patternRandomFlash() {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < NUMPIXELS1; j++) {
      setDimmedPixelColor(strip1, j, random(255), random(255), random(255));
    }
    for (int j = 0; j < NUMPIXELS2; j++) {
      setDimmedPixelColor(strip2, j, random(255), random(255), random(255));
    }
    strip1.show();
    strip2.show();
    delay(100);
  }
}

void patternDiagonalSweep() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, 255, 255, 255);
    strip1.show();
    delay(10);
    setDimmedPixelColor(strip1, i, 0, 0, 0);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, 255, 255, 255);
    strip2.show();
    delay(10);
    setDimmedPixelColor(strip2, i, 0, 0, 0);
  }
}

void patternColorWipe() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, 255, 0, 0);
    strip1.show();
    delay(50);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, 255, 0, 0);
    strip2.show();
    delay(50);
  }
}

void patternSpiral() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, 255, 0, 0);
    strip1.show();
    delay(100);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, 0, 255, 0);
    strip2.show();
    delay(100);
  }
}

void patternNoisePattern() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, random(255), random(255), random(255));
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, random(255), random(255), random(255));
  }
  strip1.show();
  strip2.show();
  delay(500);
}

void patternRadarSweep() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, 255, 0, 0);
    if (i > 2) {
      setDimmedPixelColor(strip1, i - 3, 0, 0, 0);
    }
    strip1.show();
    delay(100);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, 0, 255, 0);
    if (i > 2) {
      setDimmedPixelColor(strip2, i - 3, 0, 0, 0);
    }
    strip2.show();
    delay(100);
  }
}

void patternGradientFill() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, i, 255 - i, 0);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, i, 255 - i, 0);
  }
  strip1.show();
  strip2.show();
  delay(100);
}

void patternLightning() {
  for (int i = 0; i < 5; i++) {
    int flash = random(NUMPIXELS1);
    for (int j = 0; j < NUMPIXELS1; j++) {
      setDimmedPixelColor(strip1, j, 255, 255, 255);
    }
    for (int j = 0; j < NUMPIXELS2; j++) {
      setDimmedPixelColor(strip2, j, 255, 255, 255);
    }
    strip1.show();
    strip2.show();
    delay(50);
    for (int j = 0; j < NUMPIXELS1; j++) {
      setDimmedPixelColor(strip1, j, 0, 0, 0);
    }
    for (int j = 0; j < NUMPIXELS2; j++) {
      setDimmedPixelColor(strip2, j, 0, 0, 0);
    }
    strip1.show();
    strip2.show();
    delay(50);
  }
}


void patternFallingRain() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, 0, 0, 255);
    if (i > 2) {
      setDimmedPixelColor(strip1, i - 3, 0, 0, 0);
    }
    strip1.show();
    delay(50);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, 0, 0, 255);
    if (i > 2) {
      setDimmedPixelColor(strip2, i - 3, 0, 0, 0);
    }
    strip2.show();
    delay(50);
  }
}

void patternPulsingCircle() {
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < NUMPIXELS1; j++) {
      setDimmedPixelColor(strip1, j, i, 0, 0);
    }
    for (int j = 0; j < NUMPIXELS2; j++) {
      setDimmedPixelColor(strip2, j, i, 0, 0);
    }
    strip1.show();
    strip2.show();
    delay(20);
  }
  for (int i = 255; i >= 0; i--) {
    for (int j = 0; j < NUMPIXELS1; j++) {
      setDimmedPixelColor(strip1, j, i, 0, 0);
    }
    for (int j = 0; j < NUMPIXELS2; j++) {
      setDimmedPixelColor(strip2, j, i, 0, 0);
    }
    strip1.show();
    strip2.show();
    delay(20);
  }
}

void patternFireworks() {
  for (int i = 0; i < 50; i++) {
    int pixel1 = random(NUMPIXELS1);
    int pixel2 = random(NUMPIXELS2);
    setDimmedPixelColor(strip1, pixel1, 255, 255, 255);
    setDimmedPixelColor(strip2, pixel2, 255, 255, 255);
    strip1.show();
    strip2.show();
    delay(100);
    setDimmedPixelColor(strip1, pixel1, 0, 0, 0);
    setDimmedPixelColor(strip2, pixel2, 0, 0, 0);
  }
}

void patternRippleEffect() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    int ripple = abs((i % 20) - 10) * 25;
    setDimmedPixelColor(strip1, i, ripple, ripple, 255);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    int ripple = abs((i % 20) - 10) * 25;
    setDimmedPixelColor(strip2, i, ripple, ripple, 255);
  }
  strip1.show();
  strip2.show();
  delay(100);
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


void patternBlue() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, 0, 0, 255);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, 0, 0, 255);
  }
  for (int i = 0; i < MATRIX_WIDTH * MATRIX_HEIGHT; i++) {
    leds[i] = CRGB(0, 0, 255);
  }
  strip1.show();
  strip2.show();
  FastLED.show();
}

void patternYellow() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, 240, 180, 0);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, 240, 180, 0);
  }
  for (int i = 0; i < MATRIX_WIDTH * MATRIX_HEIGHT; i++) {
    leds[i] = CRGB(240 * DIM_FACTOR, 180 * DIM_FACTOR, 0 * DIM_FACTOR);
  }
  strip1.show();
  strip2.show();
  FastLED.show();
}

void patternRed() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, 255, 0, 0);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, 0, 255, 0);
  }
  for (int i = 0; i < MATRIX_WIDTH * MATRIX_HEIGHT; i++) {
    leds[i] = CRGB(255 * DIM_FACTOR, 0 * DIM_FACTOR, 0 * DIM_FACTOR);
  }
  strip1.show();
  strip2.show();
  FastLED.show();
}

void patternWhite() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, 255, 255, 255);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, 255, 255, 255);
  }
  for (int i = 0; i < MATRIX_WIDTH * MATRIX_HEIGHT; i++) {
    leds[i] = CRGB(255 * DIM_FACTOR, 255 * DIM_FACTOR, 255 * DIM_FACTOR);
  }
  strip1.show();
  strip2.show();
  FastLED.show();
}

void patternOrange() {
  for (int i = 0; i < NUMPIXELS1; i++) {
    setDimmedPixelColor(strip1, i, 255, 100, 0);
  }
  for (int i = 0; i < NUMPIXELS2; i++) {
    setDimmedPixelColor(strip2, i, 100, 255, 0);
  }
  for (int i = 0; i < MATRIX_WIDTH * MATRIX_HEIGHT; i++) {
    leds[i] = CRGB(255 * DIM_FACTOR, 100 * DIM_FACTOR, 0 * DIM_FACTOR);
  }
  strip1.show();
  strip2.show();
  FastLED.show();
}
