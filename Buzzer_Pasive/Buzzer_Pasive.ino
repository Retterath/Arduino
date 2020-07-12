int buzzPin=8;
int pot=A1;
int potval;
float result;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin,OUTPUT);
pinMode(pot,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
potval=analogRead(pot);
result=(9940./1023.)*potval+60;
digitalWrite(buzzPin,HIGH);
delayMicroseconds(result);
digitalWrite(buzzPin,LOW);
delayMicroseconds(result);
}
