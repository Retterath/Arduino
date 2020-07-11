int potentiometerPin=A1;
int LEDpin=6;
int potentiometer;
float LEDvalue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potentiometerPin,INPUT);
  pinMode(LEDpin,OUTPUT);
}

void loop() {
  
  potentiometer=analogRead(potentiometerPin);
  LEDvalue=(255./1023.)*potentiometer;
  analogWrite(LEDpin,LEDvalue);
  Serial.println(LEDvalue);
}
