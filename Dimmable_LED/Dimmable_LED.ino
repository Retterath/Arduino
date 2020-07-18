int potentiometerPin = A1;
int LEDpin = 6;

int potentiometerVal;
float LEDvalue;

void setup() {
  Serial.begin(9600);
  
  pinMode(potentiometerPin,INPUT);
  pinMode(LEDpin,OUTPUT);
}

void loop() { 
  potentiometerVal=analogRead(potentiometerPin);
  LEDvalue=(255./1023.)*potentiometer;
  
  analogWrite(LEDpin,LEDvalue);
  Serial.println(LEDvalue);
}
