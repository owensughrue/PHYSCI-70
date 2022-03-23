/*
 AnalogRead
 
*/

int ledPin = 10;
int ledPin2 = 8;

int readValue = 0;
int ledValue = 0;
int readValue2 = 0;
int ledValue2 = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop()
{
  readValue = analogRead(A0);
  readValue2 = analogRead(A0);
  
  ledValue = map(readValue, 0, 1024, 0, 255);
  ledValue2 = map(readValue2, 0, 1024, 0, 255);
  analogWrite(ledPin, ledValue);
  analogWrite(ledPin2, ledValue2);
}
