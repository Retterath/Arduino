int yellowPin = 3;
int redPin = 2;
int buzzPin = 4;
int randSeedPin = A5;

int buttonPin = 5;
int buttonVal;
int highScore = 2001;

String userMode;

int initDelayTime = 1500;
int maxDelayTime = 3000;
int elapsed;
int randDelay;

String welcomeMsg = "---Welcome to reaction test game!---";
String highscoreMsg = "-HIGHSCORE: ";
String modeMsg = "Please select mode <buzzer/light>: ";
String readyMsg = "Get ready!";
String errorMsg = "Incorrect input! Try again!";
String gameOverMsg = "You pressed the button too early! Try again!";
String gameOverLateMsg = "You didn't press the button! Try again!";
String scoreMsg = "Your score is: ";
String newMsg = "NEW HIGHSCORE!";

void setup() {
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  pinMode(randSeedPin, INPUT); 

  Serial.begin(2000000);
}

int lightGame() {
  digitalWrite(yellowPin, HIGH);
  randDelay = random(maxDelayTime);
  for (int i = 0; i < initDelayTime+randDelay; i++) {
    buttonVal = digitalRead(buttonPin);
    if (buttonVal == 1) {
      digitalWrite(yellowPin, LOW);
      return -1;
    }
    delay(1);
  }

  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);
  elapsed = 0;
  
  for (int i = 0; i < 2000; i++) {
    buttonVal = digitalRead(buttonPin);
    if (buttonVal == 1) {
      digitalWrite(redPin, LOW);
      return elapsed;
    }

    elapsed++;
    delay(1);
  }

  digitalWrite(redPin, LOW);
  return 2001;
}

int buzzerGame() {
  randDelay = random(maxDelayTime);
  for (int i = 0; i < initDelayTime+randDelay; i++) {
    buttonVal = digitalRead(buttonPin);
    if (buttonVal == 1) {
      return -1;
    }
    delay(1);
  }

  digitalWrite(buzzPin, HIGH);
  elapsed = 0;

  for (int i = 0; i < 2000; i++) {
    buttonVal = digitalRead(buttonPin);
    if (buttonVal == 1) {
      digitalWrite(buzzPin, LOW);
      return elapsed;
    }

    elapsed++;
    delay(1);
  }

  digitalWrite(buzzPin, LOW);
  return 2001;
}

void evaluateScore(int userTime) {
  if (userTime == -1) {
        Serial.println(gameOverMsg);
      }
  else if (userTime == 2001) {
        Serial.println(gameOverLateMsg);
      }
  else {
        Serial.print(scoreMsg);
        Serial.print(userTime);
        Serial.println(" ms.");

        if (userTime < highScore) {
          Serial.println(newMsg);
          highScore = userTime;
        }
       }
}

void loop() {
  randomSeed(analogRead(randSeedPin));
  
  Serial.println(welcomeMsg);
  Serial.print(highscoreMsg);
  Serial.println(highScore == 2001 ? "none" : String(highScore));
  Serial.println();

  bool inputIncorrect = true;
  while (inputIncorrect) {
    Serial.println(modeMsg);

    while (Serial.available() == 0) {
      
    }

    userMode = Serial.readString();
    userMode.toLowerCase();

    if (userMode == "buzzer") {
      Serial.println(readyMsg);
      int userTime = buzzerGame();

      evaluateScore(userTime);
      inputIncorrect = false;
    }
    else if (userMode == "light") {
      Serial.println(readyMsg);
      int userTime = lightGame();

      evaluateScore(userTime);
      inputIncorrect = false;
    }
    else {
      Serial.println(errorMsg);
    }
  } 
}
