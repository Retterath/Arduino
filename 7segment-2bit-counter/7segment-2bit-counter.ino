const int digitTwo = 11;
const int digitOne = 10;

const int pinOne = 2;
const int pinTwo = 3;
const int pinThree = 4;
const int pinFour = 5;
const int pinFive = 6;
const int pinSix = 7;
const int pinNine = 8;
const int pinTen = 9;

void reset() {
  digitalWrite(pinTen, LOW);
  digitalWrite(pinNine, LOW);
  digitalWrite(pinOne, LOW);
  digitalWrite(pinFour, LOW);
  digitalWrite(pinThree, LOW);
  digitalWrite(pinSix, LOW);
  digitalWrite(pinFive, LOW);
  digitalWrite(pinTwo, LOW);
}

void lightUpSegments(int numberToShow) {
  if (numberToShow == 1) {
    digitalWrite(pinNine, HIGH);
    digitalWrite(pinOne, HIGH);
  }
  else if (numberToShow == 2) {
    digitalWrite(pinNine, HIGH);
    digitalWrite(pinTen, HIGH);
    digitalWrite(pinThree, HIGH);
    digitalWrite(pinFive, HIGH);
    digitalWrite(pinFour, HIGH);
  }
  else if (numberToShow == 3) {
    digitalWrite(pinTen, HIGH);
    digitalWrite(pinNine, HIGH);
    digitalWrite(pinFive, HIGH);
    digitalWrite(pinOne, HIGH);
    digitalWrite(pinFour, HIGH);
  }
  else if (numberToShow == 4) {
    digitalWrite(pinSix, HIGH);
    digitalWrite(pinFive, HIGH);
    digitalWrite(pinNine, HIGH);
    digitalWrite(pinOne, HIGH);
  }
  else if (numberToShow == 5) {
    digitalWrite(pinTen, HIGH);
    digitalWrite(pinSix, HIGH);
    digitalWrite(pinFive, HIGH);
    digitalWrite(pinOne, HIGH);
    digitalWrite(pinFour, HIGH);
  }
  else if (numberToShow == 6) {
    digitalWrite(pinTen, HIGH);
    digitalWrite(pinSix, HIGH);
    digitalWrite(pinThree, HIGH);
    digitalWrite(pinOne, HIGH);
    digitalWrite(pinFour, HIGH);
    digitalWrite(pinFive, HIGH);
  }
  else if (numberToShow == 7) {
    digitalWrite(pinTen, HIGH);
    digitalWrite(pinNine, HIGH);
    digitalWrite(pinOne, HIGH);
  }
  else if (numberToShow == 8) {
    digitalWrite(pinTen, HIGH);
    digitalWrite(pinNine, HIGH);
    digitalWrite(pinOne, HIGH);
    digitalWrite(pinFour, HIGH);
    digitalWrite(pinThree, HIGH);
    digitalWrite(pinSix, HIGH);
    digitalWrite(pinFive, HIGH);
  }
  else if (numberToShow == 9) {
    digitalWrite(pinTen, HIGH);
    digitalWrite(pinNine, HIGH);
    digitalWrite(pinOne, HIGH);
    digitalWrite(pinFour, HIGH);
    digitalWrite(pinSix, HIGH);
    digitalWrite(pinFive, HIGH);
  }
  else if (numberToShow == 0) {
    digitalWrite(pinTen, HIGH);
    digitalWrite(pinNine, HIGH);
    digitalWrite(pinOne, HIGH);
    digitalWrite(pinFour, HIGH);
    digitalWrite(pinThree, HIGH);
    digitalWrite(pinSix, HIGH);
  }
}

void displayNumber(int numberToShow) {
  int firstVal = numberToShow % 10;
  int secondVal = numberToShow / 10;
  
  lightUpSegments(firstVal);
  digitalWrite(digitOne, HIGH);
  delay(10);
  digitalWrite(digitOne, LOW);
  reset();

  if (secondVal != 0) {
    lightUpSegments(secondVal);
    digitalWrite(digitTwo, HIGH);
    delay(10);
    digitalWrite(digitTwo, LOW);
    reset();
  }
}


void setup() {
  pinMode(digitTwo, OUTPUT);
  pinMode(digitOne, OUTPUT);

  pinMode(pinOne, OUTPUT);
  pinMode(pinTwo, OUTPUT);
  pinMode(pinThree, OUTPUT);
  pinMode(pinFour, OUTPUT);
  pinMode(pinFive, OUTPUT);
  pinMode(pinSix, OUTPUT);
  pinMode(pinNine, OUTPUT);
  pinMode(pinTen, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 99; i++) {
    for (int j = 0; j <= (i > 9 ? 20 : 40); j++) {
      displayNumber(i);
    }
  }
}
