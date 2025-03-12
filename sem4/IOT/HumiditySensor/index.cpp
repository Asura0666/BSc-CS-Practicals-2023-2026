// C++ code

const int analogIn = A1;        // Pin connected to the humidity sensor
int humiditySensorOutput = 0;    // Variable to store the sensor output

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
}

void loop() {
  humiditySensorOutput = analogRead(analogIn);  // Read the sensor output
  int humidityPercentage = map(humiditySensorOutput, 0, 1023, 10, 70);  // Map the sensor value to percentage
  
  Serial.print("Humidity: ");  // Print the humidity label
  Serial.print(humidityPercentage);  // Print the humidity percentage
  Serial.println("%");  // Print the "%" symbol and go to a new line
  
  delay(5000);  // Wait for 5 seconds before taking the next reading
}
