const int LED_PIN = 9;  // Use a digital pin for LED
const int SENSOR_PIN = A0;
const int SMOKE_THRESHOLD = 300;  // Adjust this based on actual readings

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue >= SMOKE_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);  // LED ON when smoke is detected
    Serial.println("Smoke Detected!");
  } else {
    digitalWrite(LED_PIN, LOW);   // LED OFF when no smoke
    Serial.println("No Smoke.");
  }

  delay(1000);
}
