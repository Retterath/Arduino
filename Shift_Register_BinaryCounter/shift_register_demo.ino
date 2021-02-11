int latchPin =  11;
int clockPin = 9;
int dataPin = 12;
int dt=250;

byte LED1s=0b01010101;
byte LED2s=0b11111111;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED1s);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED2s);
  digitalWrite(latchPin, HIGH);
  delay(dt);
}
