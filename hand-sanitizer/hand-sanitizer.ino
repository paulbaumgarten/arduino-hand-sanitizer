const int trigPin = 4;
const int echoPin = 5;
const int ledPin = 3;
const int pumpPin = 12;
const int pumpOnMilliseconds = 400;
const int pumpOnMilliseconds2 = 500;

long duration;
int distance;
unsigned long lastPumpTime = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 10) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(pumpPin, HIGH);
    if (lastPumpTime + 5000 < millis()) {
       delay(pumpOnMilliseconds);
    } else {
       delay(pumpOnMilliseconds2);
    }
    digitalWrite(ledPin, LOW);
    digitalWrite(pumpPin, LOW);
    lastPumpTime = millis();
    delay(1500);    
  } else {
     delay(200);
  }
}
