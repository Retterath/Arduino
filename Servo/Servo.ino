#include <Servo.h>

int servoPin=9;
int servoPos=90; //In degrees
Servo myServo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  myServo.write(servoPos);
}
