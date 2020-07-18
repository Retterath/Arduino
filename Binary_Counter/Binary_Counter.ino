int whiteLED = 2; 
int redLED = 4;
int greenLED = 6;
int blueLED = 8; 
int yellowLED = 10;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
}

int* calculateBinary(int num) {
    static int number[5];
    int currentNum = num;

    for (int i = 4; i >= 0; i--)
    {
        int quoti = currentNum / 2;
        int remainder = currentNum % 2;

        number[i] = remainder;
        currentNum = quoti;
    }
    return number;
}

void displayBinary(int* binary) {
    digitalWrite(whiteLED, *binary ? HIGH : LOW);
    digitalWrite(blueLED, *(binary + 1) ? HIGH : LOW);
    digitalWrite(greenLED, *(binary + 2) ? HIGH : LOW);
    digitalWrite(redLED, *(binary + 3) ? HIGH : LOW);
    digitalWrite(yellowLED, *(binary + 4) ? HIGH : LOW);
}

void loop() {
    for (int i = 0; i < 32; i++) {
        int* binary = calculateBinary(i);
        displayBinary(binary);

        delay(700);
    }

    delay(1000);
}
