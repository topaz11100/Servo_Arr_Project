#include <Servo.h>

Servo servo1_k;
Servo servo1_f;
Servo servo2_k;
Servo servo2_f;
Servo servo3_k;
Servo servo3_f;
Servo servo4_k;
Servo servo4_f;

int speed=100;

void setup(){
  
  servo1_k.attach(4);
  servo1_f.attach(8);
  servo2_k.attach(5);
  servo2_f.attach(9);
  servo3_k.attach(6);
  servo3_f.attach(10);
  servo4_k.attach(7);
  servo4_f.attach(11);
  
  Serial.begin(9600);
}

void loop(){
  /*
  축하합니다 로봇을 움직이기 위해 필요한 것을 다 배웠습니다
  여러분만의 로봇을 만들어보세요
  도전과제
  걷기, 뒤로걷기, 앉았다일어나기, 헤엄치기 등등
  */
}






















