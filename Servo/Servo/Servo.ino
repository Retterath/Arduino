#include <Servo.h>
int servoPin=9;
int servoPos=0;//In degrees
int sensorPin=A2;
//Servo commands are not included in arduino lib.
//In order to interract with it we need to create an 
//Object for it.

Servo myServo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(sensorPin));
 
}
