const int irPin = 27;
const int ledPin = 32;

void setup() {

  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(115200);
}

void loop() {

  int sensorValue = digitalRead(irPin);

  if (sensorValue == LOW) {      // Object detected
    digitalWrite(ledPin, HIGH);
    Serial.println("Obstacle Detected");
  } 
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("No Obstacle");
  }

  delay(200);
}