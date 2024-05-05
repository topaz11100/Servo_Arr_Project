#include <Servo.h>

Servo servo1_k;
Servo servo1_f;
Servo servo2_k;
Servo servo2_f;
Servo servo3_k;
Servo servo3_f;
Servo servo4_k;
Servo servo4_f;

//속도 조절
int speed=200;

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
  로봇을 회전시켜보자
  지난시간에 썼던 walk_one_leg을 이용해 로봇을 회전시키려면 어떻게 해야할까
  예제1 walk_one_leg을 다리 하나에만 적용후 실행결과를 잘 살펴보자
  walk_one_leg_1(speed);
  */
  /*
  다리 하나에 적용시 몸이 약간 회전하는 모습을 볼 수 있다
  뒤로 걷도록 하면 회전 방향이 바뀔 것이다
  예제2 walk_one_leg를 변형해 뒤로 가게 보이는 back_one_leg함수를 만든 뒤 회전 결과가 반대인지 관찰한다
  back_one_leg_1(speed);
  */

  /*
  예제3 walk_one_leg와 back_one_leg를 적절히 활용해 시계방향으로 회전해보자
  clock_rotate 함수 내용을 완성하자
  */
  //clock_rotate(speed);
  

  /*
  예제4 반시계방향으로 회전해보자
  anticlock_rotate 함수 내용을 완성하자
  */
  //anticlock_rotate(speed);-
  

  /*
  예제5 걸을때처럼 두 다리를 동시에 움직여 좀더 나은 회전을 해보자
  이때 넘어진다면 다리의 각도를 조정해 넘어지지 않게 해보자
  */
  //advanced_clock_rotate(speed);
  //advanced_anticlock_rotate(speed);
  
  
}
//예제1
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
//예제2
void back_one_leg_1(int speed){
  /*
  servo1_f.write(30);
  delay(speed);
  servo1_k.write(90);
  delay(speed);
  servo1_f.write(140);
  delay(speed);
  servo1_k.write(0);
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
void back_one_leg_2(int speed){
  /*
  servo2_f.write(130);
  delay(speed);
  servo2_k.write(90);
  delay(speed);
  servo2_f.write(55);
  delay(speed);
  servo2_k.write(10);
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
void back_one_leg_3(int speed){
  /*
  servo3_f.write(50);
  delay(speed);
  servo3_k.write(90);
  delay(speed);
  servo3_f.write(130);
  delay(speed);
  servo3_k.write(170);
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
void back_one_leg_4(int speed){
  /*
  servo4_f.write(130);
  delay(speed);
  servo4_k.write(90);
  delay(speed);
  servo4_f.write(45);
  delay(speed);
  servo4_k.write(170);
  delay(speed);
  */
}

//예제3
void clock_rotate(int speed){
  /*
  walk_one_leg_1(speed);
  walk_one_leg_2(speed);
  back_one_leg_3(speed);
  back_one_leg_4(speed);
  */
}
//예제4
void anticlock_rotate(int speed){
  /*
  walk_one_leg_3(speed);
  walk_one_leg_4(speed);
  back_one_leg_1(speed);
  back_one_leg_2(speed);
  */
}
//예제5
void advanced_clock_rotate(int speed){
  /*
  clock_rotate_1_3(speed);
  clock_rotate_2_4(speed);
  */
}

void advanced_anticlock_rotate(int speed){
  /*
  anticlock_rotate_1_3(speed);
  anticlock_rotate_2_4(speed);
  */
}

void clock_rotate_1_3(int speed){
  /*
  servo1_f.write(30);
  delay(speed);
  servo1_k.write(0);
  delay(speed);
  servo3_f.write(50);
  delay(speed);
  servo3_k.write(10);
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

void anticlock_rotate_1_3(int speed){
  /*
  servo1_f.write(30);
  delay(speed);
  servo1_k.write(90);
  delay(speed);
  servo3_f.write(50);
  delay(speed);
  servo3_k.write(90);
  delay(speed);

  servo2_f.write(90);
  servo4_f.write(90);

  servo1_f.write(140);
  delay(speed);
  servo1_k.write(0);
  delay(speed);
  servo3_f.write(130);
  delay(speed);
  servo3_k.write(10);
  delay(speed);
  */
}

void clock_rotate_2_4(int speed){
  /*
  servo2_f.write(130);
  delay(speed);
  servo2_k.write(10);
  delay(speed);
  servo4_f.write(130);
  delay(speed);
  servo4_k.write(90);
  delay(speed);

  servo1_f.write(90);
  servo3_f.write(90);

  servo2_f.write(55);
  delay(speed);
  servo2_k.write(90);
  delay(speed);
  servo4_f.write(45);
  delay(speed);
  servo4_k.write(170);
  delay(speed);
  */
}
void anticlock_rotate_2_4(int speed){
  /*
  servo2_f.write(130);
  delay(speed);
  servo2_k.write(170);
  delay(speed);
  servo4_f.write(130);
  delay(speed);
  servo4_k.write(170);
  delay(speed);

  servo1_f.write(90);
  servo3_f.write(90);

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

//추가예제 자신만의 방법으로 로봇을 회전시켜보자
































