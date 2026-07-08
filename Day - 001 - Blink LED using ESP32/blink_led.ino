void setup() {
  pinMode(T5, OUTPUT);
}

void loop() {
  digitalWrite(T5, HIGH);
  delay(1000);

  digitalWrite(T5, LOW);
  delay(1000);
}