#include <M5Atom.h>

CRGB colors[] = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Purple};
int colorIndex = 0;
unsigned long previousMillis = 0;
const long interval = 1000; 

void setup() {
  M5.begin(true, false, true);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    M5.dis.fillpix(colors[colorIndex]);

    colorIndex = (colorIndex + 1) % (sizeof(colors) / sizeof(colors[0]));
  }
}
