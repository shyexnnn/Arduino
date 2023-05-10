#include <Servo.h> // 서보 라이브러리를 불러옴

Servo myservo; // 서보를 제어할 서보 오브젝트를 만든다
int servo = 9;

void setup()
{
  myservo.attach(servo);
  myservo.write(0); // 0도로 세팅
}

void loop()
{
  myservo.write(90); // 90도
  delay(1000);
  myservo.write(0); // 0도
  delay(1000);
}
