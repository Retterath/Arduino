int lightPin=A0;
int lightVal;
int dv=250;

int redLED=7;
int greenLED=8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin,INPUT);
  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal=analogRead(lightPin);
  Serial.println(lightVal);
  delay(dv);
  if(lightVal>500){
    digitalWrite(redLED,HIGH);
    delay(dv);
    digitalWrite(redLED,LOW);
  }
  else if(lightVal<500){
    digitalWrite(greenLED,HIGH);
    delay(dv);
    digitalWrite(greenLED,LOW);
  }
}
