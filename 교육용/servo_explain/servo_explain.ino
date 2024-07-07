#include <Servo.h>

//서보모터를 사용하기 위해 서보모터 객체 생성
Servo servo;

void setup(){
  //서보모터를 핀과 연결
  servo.attach(12);

  //통신 시작
  Serial.begin(9600);
}

void loop(){
  //서보모터를 지정한 각도로 위치시킴
  servo.write(0);
  //모터가 움직이는데 필요한 시간 보장
  delay(500);
  //서보모터의 각도는 0~180도임
  servo.write(180);

  //0도에서 180도로 순서대로 가려면 어떻게 해야할까?
  for(int i=0; i<180; i+=1){
    //servo.write(i);
    //delay(10);
  }

  //모터의 현재 위치를 읽을 수 있다
  int angle = servo.read();
  Serial.println(angle);

  //예제 1. 일정한 간격으로 45도와 135도를 원하는 만큼 반복하도록 func을 완성해보자
  int second = 500; //(원하는 간격)
  int iter = 3; //(원하는 반복 횟수)
  func(second, iter);
}
void func(int second, int iter){
  //for(int i=0; i<iter; i+=1){
    //servo.write(45);
    //delay(s);
    //servo.write(135);
    //delay(s);
  //}
}



































