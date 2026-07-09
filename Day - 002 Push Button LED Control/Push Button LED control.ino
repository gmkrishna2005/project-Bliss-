const int ledPin = 4;
const int buttonPin = 5;

bool ledState = LOW;        // LED is in OFF state
bool lastButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(ledPin, ledState);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  // Detect button press (HIGH -> LOW)
  if (lastButtonState == HIGH && buttonState == LOW) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }

  lastButtonState = buttonState;
}