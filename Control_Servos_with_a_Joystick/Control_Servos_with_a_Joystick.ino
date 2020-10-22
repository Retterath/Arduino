#include <Servo.h>
Servo XServo;
int Xpin = A0;
int Ypin = A1;
int SPin = 2;
int Xval, Yval, Sval, WriteValX;
int XSpin=9;
int dt=200;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  pinMode(SPin,INPUT);
  pinMode(XSpin,OUTPUT);
  digitalWrite(SPin,HIGH);
  XServo.attach(XSpin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(SPin);
  WriteValX = (180./1023.)*Xval;
  XServo.write(WriteValX);
  delay(dt);
  Serial.print("X Value = ");
  Serial.print(Xval);
  Serial.print(" Y Value = ");
  Serial.print(Yval);
  Serial.print(" Switch State is ");
  Serial.println(Sval);
}
