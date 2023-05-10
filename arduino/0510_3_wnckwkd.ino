#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int trig = 13;
int echo = 8;
Servo myservo;
int servo =9;
int i=90;
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach(servo);
  myservo.write(0);
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
  if(distance<=10){
    myservo.write(i++);  }
}
