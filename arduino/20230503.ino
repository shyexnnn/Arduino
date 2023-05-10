#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int trig = 13;
int echo = 8;
int ledPin = 2;

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  unsigned long duration = pulseIn(echo, HIGH);
  float distance = ((float)(340 * duration) / 10000) / 2;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.println(distance);
  lcd.print("cm");
  delay(200);
  Serial.print(distance);
  Serial.println("cm");
  delay(100);

  if(distance>14)
  {
    digitalWrite(ledPin, 1);
  }
  else
  {
    digitalWrite(ledPin, 0);
  }
}
