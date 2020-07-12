int number;
int buzzerPin=8;
String msg="Please Input your number: ";
int delayTime=1000;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzzerPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg);
while(Serial.available()==0){
  
}
number=Serial.parseInt();
if(number>10){
  digitalWrite(buzzerPin,HIGH);
  delay(delayTime);
  digitalWrite(buzzerPin,LOW);
}
}
