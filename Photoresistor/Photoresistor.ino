const int sensorPin = 0;
const int ledPin = 9;
int lightLevel;
int calibratedlightLevel; // used to store the scaled / calibrated lightLevel
int maxThreshold = 0;     // used for setting the "max" light level
int minThreshold = 1023;   // used for setting the "min" light level

void setup()
{
  pinMode(ledPin, OUTPUT);    // Set up the LED pin to be an output.
  Serial.begin(9600);
}

void loop()
{
  lightLevel = analogRead(sensorPin);  // reads the voltage on the sensorPin
  Serial.print(lightLevel);
  //autoRange();  // autoRanges the min / max values you see in your room.

  calibratedlightLevel = map(lightLevel, 0, 1023, 0, 255);  // scale the lightLevel from 0 - 1023 range to 0 - 255 range.
                                                  // the map() function applies a linear scale / offset.
                                                  // map(inputValue, fromMin, fromMax, toMin, toMax);
  Serial.print("\t"); 		  // tab character
  Serial.print(calibratedlightLevel);   // println prints an CRLF at the end (creates a new line after)

  analogWrite(ledPin, calibratedlightLevel);    // set the led level based on the input lightLevel.
}
void autoRange()
{
  if (lightLevel < minThreshold)  // minThreshold was initialized to 1023 -- so, if it's less, reset the threshold level.
    minThreshold = lightLevel;

  if (lightLevel > maxThreshold)  // maxThreshold was initialized to 0 -- so, if it's bigger, reset the threshold level.
    maxThreshold = lightLevel;

  lightLevel = map(lightLevel, minThreshold, maxThreshold, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
}
