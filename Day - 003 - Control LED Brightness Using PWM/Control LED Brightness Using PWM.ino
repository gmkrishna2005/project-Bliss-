const int ledPin = 5;

const int freq = 5000;
const int resolution = 8;

void setup() {
  ledcAttach(ledPin, freq, resolution);
}

void loop() {

  // Increase brightness
  for (int duty = 0; duty <= 255; duty+=5) {
    ledcWrite(ledPin, duty);
    delay(3);
  }

  // Decrease brightness
  for (int duty = 255; duty >= 0; duty-=5) {
    ledcWrite(ledPin, duty);
    delay(3);
  }
}
