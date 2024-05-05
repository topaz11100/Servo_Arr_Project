#include <Servo.h>

//서로 다른 서보모터를 추가할 수 있다.
Servo servo1;
// 예제1 다른 서보모터를 servo2라는 이름으로 추가해보자.
//Servo servo2; 

void setup(){
  //서보모터를 핀과 연결
  servo1.attach(12);
  //예제2 나머지 서보모터를 원하는 핀과 연결해보자
  //servo2.attach(11);

  //통신 시작
  Serial.begin(9600);
}

void loop(){
  //다른 서보모터에서도 write, read함수를 사용할 수 있다.

  //예제3 한 서보모터는 0도 다른 서보모터는 90도로 맞추자
  //servo1.write(0);
  //servo2.write(90);

  //예제4 반복문 하나로 한 모터는 0~180, 다른 모터는 180~0으로 움직여보자
  for(int i=0; i<=180; i+=1){
    //servo1.write(i);
    //servo2.write(180-i);
    //delay(10);
  }

  //예제5 두 모터가 위치한 각도를 알아보자
  //Serial.print(servo1.read());
  //Serial.print(":");
  //Serial.println(servo2.read());

  //예제6 모터1을 0~180움직이고 모터1가 완전히 움직인 후에 
  //모터2가 180~0으로 움직이도록 func을 완성해보자  
}
void func(int speed){
  /*
  for(int i=0; i<=180; i+=1){
    servo1.write(i);
    delay(speed);
  }
  for(int i=180; i>=180; i-=1){
    servo2.write(i);
    delay(speed);
  }
  */
}
//마지막 예제 : 모터의 개수를 3개 이상으로 위의 예제를 다시 풀어보자



































