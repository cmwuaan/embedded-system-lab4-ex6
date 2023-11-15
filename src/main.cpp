#include <Arduino.h>

const int analogPin = A0;
const int ledCount = 12;

int ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(analogPin, INPUT);
  for (int i = 0; i < ledCount; i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(analogPin);
  sensorValue = map(sensorValue, 0, 1023, 0, ledCount);

  for (int i = 0; i < ledCount; i++)
  {
    digitalWrite(ledPin[i], i < sensorValue ? HIGH : LOW);
  }
}