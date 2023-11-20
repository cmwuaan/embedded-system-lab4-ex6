#include <Arduino.h>

#define sensorAnalogPin A0

byte ledPins[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
byte pinCount;
int analogValue = 0;
int soundMaxLevel = 0;
int delayTime = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinCount = sizeof(ledPins);
  for (int i = 0; i < pinCount; i++)
  {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  analogValue = analogRead(sensorAnalogPin);
  delay(10);
  Serial.println(analogValue);
  if (analogValue > soundMaxLevel)
  {
    soundMaxLevel = analogValue;
  }
  int ledIndex = map(analogValue, 0, soundMaxLevel, 0, pinCount);
  for (int i = 0; i < pinCount; i++)
  {
    if (i < ledIndex)
    {
      digitalWrite(ledPins[i], HIGH);
      if (i > 7)
      {
        delay(300);
      }
      else if (i <= 7 && i > 3)
      {
        delay(150);
      }
      else
      {
        delay(50);
      }

      digitalWrite(ledPins[i], LOW);
    }
    else
    {
      digitalWrite(ledPins[i], LOW);
    }
  }
}