#include<Servo.h>
Servo servoBase;

void setup()
{
  servoBase.attach(A1);
  servoBase.write(0);
}

void loop()
{
  for (int i = 0; i <= 180; i += 10){
    servoBase.write(i);
    delay(2000);
  }  
}