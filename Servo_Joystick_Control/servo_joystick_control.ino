#include <Servo.h>
Servo XServo;
Servo YServo;

int xpin = A0;
int ypin = A1;
int spin = 2;
int xServoPin = 9;
int yServoPin = 10;
int buzzerPin = 7;

int writeValX;
int writeValY;

int dTime = 250;

int xVal;
int yVal;
int sVal;

void setup() {
  //Serial.begin(9600);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(spin, INPUT);
  digitalWrite(spin, HIGH);
  
  pinMode(xServoPin, OUTPUT);
  pinMode(yServoPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  XServo.attach(xServoPin);
  YServo.attach(yServoPin);
}

void loop() {
  xVal = analogRead(xpin); 
  yVal = analogRead(ypin); 
  sVal = digitalRead(spin);
  
  writeValX = 180.0/1023.0*xVal;
  writeValY = 180.0/1023.0*yVal;

  XServo.write(writeValX);
  YServo.write(writeValY);

  //delay(dTime);

  //Serial.print("X");
  //Serial.println(writeValX);
  //Serial.print("Y");
  //Serial.println(writeValY);
  //Serial.print("S");
  //Serial.println(sVal);
  
  if (sVal == 0) {
    digitalWrite(buzzerPin, HIGH);
    //XServo.write(45);
    //YServo.write(46);
  }
  else {
    digitalWrite(buzzerPin, LOW);
  }
  
}
