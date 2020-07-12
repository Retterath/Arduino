int potentiometerPin=A3;
int potentiometerVal;
int buzzerPin=8;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzzerPin,OUTPUT);
pinMode(potentiometerPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potentiometerVal=analogRead(potentiometerPin);
Serial.println(potentiometerVal);
while(potentiometerVal>1000){
  digitalWrite(buzzerPin,HIGH);
  potentiometerVal=analogRead(potentiometerPin);
  Serial.println(potentiometerVal);
  }
  digitalWrite(buzzerPin,LOW);
}
