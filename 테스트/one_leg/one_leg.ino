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
int speed = 1000;

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
  //예제2 각각의 모터 각도를 시리얼 모니터로 표시해주는 함수 read_motor()를 완성해보자
  read_motor();

  //예제3 모터를 다양한 각도로 옮겨보고 모터가 가질 수 있는 최대, 최소값
  //이동방향을 기록해보자 (위 값을 기록해야 걸을 때 수월하다)
  /*
  for(int i=0; i<=180; i+=1){
    servo1.write(i);
    servo2.write(i);
    delay(10);
  }
  */
  /*
  예제4  진짜 다리라고 생각하고 움직여보자
  사람의 다리는 어떻게 움직이는가?
  1. 발을 든다
  2. 무릎을 앞으로 옮긴다
  3. 발을 내린다
  4. 무릎을 땡겨 앞으로 움직인다
  다음과 같은 순서로 움직일 것이다
  따라서 위 알고리즘을 로봇에 적용하여
  1. 발의 모터를 위로 올린다
  2. 무릎 모터를 앞쪽으로 회전한다
  3. 발의 모터를 내린다
  4. 무릎 모터를 뒤로 회전해 몸이 앞으로 가게 한다.
  1,2,3,4를 차례로 수행하는 함수 walk_one_leg를 완성하고
  실제로 그렇게 되는지 만들어보자 위 과정에서 예제 3의 기록이 필요할 것이다
  */
  //walk_one_leg(speed);
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
//예제4
void walk_one_leg(int speed){
  
  m0.write(0);
  delay(speed);
  m4.write(150);
  delay(speed);
  m0.write(150);
  delay(speed);
  m4.write(0);
  delay(speed);

}























