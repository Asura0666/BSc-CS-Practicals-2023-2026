// C++ code
//
int sensorState = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
	sensorState = digitalRead(2);
  	
  if(sensorState == HIGH) {
	digitalWrite(LED_BUILTIN, HIGH);
  } else {
	digitalWrite(LED_BUILTIN, LOW);
  }
  
  delay(10);
}