#include <Servo.h>

//로봇의 다리는 4개이다
//예제1 로봇을 구동하기 위한 서보모터의 개수를 알아보고 정의해보자
/*
Servo servo1_k;
Servo servo1_f;
Servo servo2_k;
Servo servo2_f;
Servo servo3_k;
Servo servo3_f;
Servo servo4_k;
Servo servo4_f;
*/

//속도 조절
int speed=100;

void setup(){
  //예제2 각 서보모터를 원하는 핀에 연결하자
  /*
  servo1_k.attach(4);
  servo1_f.attach(8);
  servo2_k.attach(5);
  servo2_f.attach(9);
  servo3_k.attach(6);
  servo3_f.attach(10);
  servo4_k.attach(7);
  servo4_f.attach(11);
  */
  Serial.begin(9600);
}

void loop(){
  /*
  로봇을 움직여보자
  로봇이 걸으려면? 다리가 움직여야한다
  다리를 어떻게? 다리를 지난 장에 썼던 walk_one_leg알고리즘을 이용해 움직이면 된다.
  예제3 저번에 사용했던 walk_one_leg알고리즘을 이용해 로봇을 앞으로 걷게 움직여보자
  해당 내용을 함수 walk에 완성한다.
  */

  //walk(speed);
  
  /*
  잘 되는가?
  잘 걷지 못하는 원인은 여러가지가 있다.
  1. 발이 땅에 닿지 않아 몸을 당기지 못함
  2. 발이 땅에 닿으나 다른 발들도 닿아 별 효과없음
  3. 바닥이 미끄러움
  4. 속도가 너무 느림
  1,2 번의 해결책은 걷는 발이 땋에 닿으면 다른 발들을 약간 들어주는 것이다.
  그리고 대각선 방향의 다리를 동시에 움직이면 더 잘걸을 수 있음이 알려져있다.
  예제4 문제점들을 해결하고 더 잘 걷게 해보자
  */
  //walk2(speed);
}
//예제3
void walk(int speed){
  /*
  walk_one_leg_1(speed);
  walk_one_leg_3(speed);
  walk_one_leg_2(speed);
  walk_one_leg_4(speed);
  */
}
//walk_one_leg
void walk_one_leg_1(int speed){
  /*
  servo1_f.write(30);
  delay(speed);
  servo1_k.write(0);
  delay(speed);
  servo1_f.write(140);
  delay(speed);
  servo1_k.write(90);
  delay(speed);
  */
}
void walk_one_leg_2(int speed){
  /*
  servo2_f.write(130);
  delay(speed);
  servo2_k.write(10);
  delay(speed);
  servo2_f.write(55);
  delay(speed);
  servo2_k.write(90);
  delay(speed);
  */
}
void walk_one_leg_3(int speed){
  /*
  servo3_f.write(50);
  delay(speed);
  servo3_k.write(170);
  delay(speed);
  servo3_f.write(130);
  delay(speed);
  servo3_k.write(90);
  delay(speed);
  */
}
void walk_one_leg_4(int speed){
  /*
  servo4_f.write(130);
  delay(speed);
  servo4_k.write(170);
  delay(speed);
  servo4_f.write(45);
  delay(speed);
  servo4_k.write(90);
  delay(speed);
  */
}

//예제4
void walk2(int speed){
  /*
  walk_1_3(speed);
  walk_2_4(speed);
  */
}
void walk_1_3(int speed){
  /*
  servo1_f.write(30);
  delay(speed);
  servo1_k.write(0);
  delay(speed);
  servo3_f.write(50);
  delay(speed);
  servo3_k.write(170);
  delay(speed);

  servo2_f.write(90);
  servo4_f.write(90);

  servo1_f.write(140);
  delay(speed);
  servo1_k.write(90);
  delay(speed);
  servo3_f.write(130);
  delay(speed);
  servo3_k.write(90);
  delay(speed);
  */
}
void walk_2_4(int speed){
  /*
  servo2_f.write(130);
  delay(speed);
  servo2_k.write(10);
  delay(speed);
  servo4_f.write(130);
  delay(speed);
  servo4_k.write(170);
  delay(speed);

  servo2_f.write(90);
  servo4_f.write(90);

  servo2_f.write(55);
  delay(speed);
  servo2_k.write(90);
  delay(speed);
  servo4_f.write(45);
  delay(speed);
  servo4_k.write(90);
  delay(speed);
  */
}
































