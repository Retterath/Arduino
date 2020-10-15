#include <Stepper.h>
int stepsPerRevolution = 2048; //2048
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int motSpeed = 5;
int dt = 50;

int buttonPin = 2;
int buttonVal;

int rotationStep = 1;

void setup() {
  myStepper.setSpeed(motSpeed);
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
 }

void loop() {
  myStepper.step(rotationStep);
  buttonVal = digitalRead(buttonPin);
  Serial.println(buttonVal);

  if (buttonVal == 0) {
    rotationStep = -rotationStep;
    while (buttonVal == 0) {
      myStepper.step(rotationStep);
      buttonVal = digitalRead(buttonPin);
    }
  }
}
