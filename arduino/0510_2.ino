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
  for(int pos = 0; pos <= 180; pos += 1) // 0도에서 180도로 이동
  { // 이동할때 각도는 1씩 이동
    myservo.write(pos); // 'pos' 변수의 위치로 서보를 이동
    delay(20); // 서보 명령 간에 20ms를 기다림
  }
  for(int pos = 180; pos >= 0; pos -= 1) // 180도에서 0도로 이동
  {
    myservo.write(pos); // 서보를 반대방향으로 이동
    delay(20); //서보 명령 간에 20ms를 기다림
  }
}
