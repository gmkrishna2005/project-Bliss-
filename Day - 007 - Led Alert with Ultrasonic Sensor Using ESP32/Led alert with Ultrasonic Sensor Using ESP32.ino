const int trigPin = 25;
const int echoPin = 27;
const int ledpin = 12;

long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledpin, OUTPUT);

  Serial.begin(115200);
}

void loop() {

  // Send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Measure echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= 20) {
    digitalWrite(ledpin, HIGH);
  } else {
    digitalWrite(ledpin, LOW);
  }

  delay(200);
}