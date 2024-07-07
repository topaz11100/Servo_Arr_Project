#include <Servo.h>

/* 

   (모터주소, 연결핀)
   __________ __________ _________________
  |(4,8)__(0,4)              (3,7) _(7,11)|
  |__|       |       ^        |        |__|
             |       앞       |
             |                |
             |                |
   _________ |                | __________
  |(5,9)__(1,5)__            (2,6)__(6,10)|
  |__|                                 |__|

*/

//다리 하나는 관절 두개로 이루어져있다
//따라서 서보모터 두개로 다리 하나를 제어할 수 있다
//무릎을 servo1, 발을 servo2라 해보자
Servo m0;
Servo m1;
Servo m2;
Servo m3;
Servo m4;
Servo m5;
Servo m6;
Servo m7;

//속도 조절
int speed = 500;

void setup(){
  
  m0.attach(4);
  m1.attach(5);
  m2.attach(6);
  m3.attach(7);
  m4.attach(8);
  m5.attach(9);
  m6.attach(10);
  m7.attach(11);
  
  Serial.begin(9600);
}
void loop(){
  char received = receive();
  if      (received == 'a') hello();
  else if (received == 'w') walk_one_leg();
  read_motor();
}
//예제2
void read_motor(){
  
  Serial.print("m0:");
  Serial.print(m0.read());
  Serial.print("  m4:");
  Serial.print(m4.read());
  Serial.print("  m1:");
  Serial.print(m1.read());
  Serial.print("  m5:");
  Serial.print(m5.read());
  Serial.print("  m2:");
  Serial.print(m2.read());
  Serial.print("  m6:");
  Serial.print(m6.read());
  Serial.print("  m3:");
  Serial.print(m3.read());
  Serial.print("  m7:");
  Serial.println(m7.read());

}
void init_position(){
  m0.write(75);
  m4.write(135);
  delay(speed);
}
void hello(){
  m0.write(0);
  m4.write(0);
  delay(speed);
  for (int i=0; i<3; i+=1){
    for (int j=0; j<40; j+=1){m0.write(j); delay(10);}
    for (int j=40; j>0; j-=1){m0.write(j); delay(10);}
  }
  init_position();
}
//예제4
void walk_one_leg(){
  //발들어
  m4.write(90);
  delay(speed);
  //앞으로
  m0.write(0);
  delay(speed);
  //발내려
  m4.write(180);
  delay(speed);
  //잡아끌어
  m0.write(90);
  delay(speed);
}

char receive(){
  if ( Serial.available() ) return Serial.read();
  return '?';
}





















