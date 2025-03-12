char degree = 176;
const int sensor = A1;

void setup()
{
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int tmp = analogRead(sensor);
  float voltage = (tmp * 5.0) / 1024;
  
  float tmpCel = (voltage - 0.5) * 100.0;
  
  Serial.print("Celcius: ");
  Serial.print(tmpCel);
  Serial.println(degree);
  delay(1000); 
}