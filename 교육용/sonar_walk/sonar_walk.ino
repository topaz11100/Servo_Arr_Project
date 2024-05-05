#include <Servo.h>
//센서 핀 번호 지정
int trig = 12;
int echo = 13;

//포탑 돌릴 모터
Servo turret;

//다리 모터
Servo servo1_k;
Servo servo1_f;
Servo servo2_k;
Servo servo2_f;
Servo servo3_k;
Servo servo3_f;
Servo servo4_k;
Servo servo4_f;

//속도
int speed = 200;
 
void setup(){
  Serial.begin(9600);       // 시리얼 속도 설정
  pinMode(echo, INPUT);   // echoPin 입력    
  pinMode(trig, OUTPUT);  // trigPin 출력
  servo1_k.attach(4);
  servo1_f.attach(8);
  servo2_k.attach(5);
  servo2_f.attach(9);
  servo3_k.attach(6);
  servo3_f.attach(10);
  servo4_k.attach(7);
  servo4_f.attach(11);
  turret.attach(3);
}
 
void loop(){
  /*
  잘 걷다가 장애물을 만나면 어떻게 해야할까?
  장애물을 피해야 할 것이다
  다양한 방법이 있겠지만 앞으로 계속가면서 피하는 방법중 하나는
  1. 걸어간다
  2. 초음파센서로 장애물이있는지 탐지한다
  3. 있으면 주위를 둘러보며 장애물이 없는 곳을 판단한다
  3.1 기준은 초음파로 잰 거리가 가장 멀 때로 하자
  4. 그 방향으로 가기 위해 포탑을 원위치 하고 몸을 돌린다
  5. 거리가 3.1값과 같을때까지 돌린다
  6. 1번으로 간다
  일 것이다 위를 차례로 구현해보자
  */

  //1번
  //advanced_walk(speed);
  

  //2번
  //float dis = distance();
  
  

  /*
  3번 2번 값을 유심히 본 뒤, 장애물 판단기준을 정하자
  
  if(dis < 100){
    //예제1 위의 3.1을 구현해보자 detect함수로 구현하며, 잰 거리의 최대값을 반환하자 함수안 예제도 확인해보자
    float mark = detect();

    //4,5번
    //예제2 나머지를 구현하자 escape함수로 구현하자
    escape(mark, speed);
  }
  */
}

//예제1
float detect(){
  /*
  float result = 0;
  int angle = 0;
  float temp;
  for(int i=0; i<=180; i+=1){
    turret.write(i);
    temp = distance();
    if(result < temp){ //먼 쪽으로 피함
      result = temp;
      angle = i;
    }
  }
  //예제 포탑이 바라보는 방향이 맞는지 확인해보자
  turret.write(angle);
  return result;
  */
}

//예제2
void escape(float dis, int speed){
  /*
  //바라보고있는쪽이 90이상이면 반시계, 아니면 시계 방향 회전
  bool anticlock = turret.read()>90;
  turret.write(90);
  float temp = distance();
  if(anticlock){
    //센서 오차 감안, 범위 안에 들어오도록 회전
    while(!(dis-10<temp)){
      advanced_anticlock_rotate(speed);
      temp = distance();
    }
  }
  else{
    while(!(dis-10<temp)){
      advanced_clock_rotate(speed);
      temp = distance();
    }
  }
  */
}

//초음파 거리
float distance(){
  
  float result;
  long duration;
  digitalWrite(trig, HIGH);         
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  result = ((float)(340 * duration) / 1000) / 2;
  Serial.println("distance : " + String(result));
  return result;
  
} 


//걷기
void advanced_walk(int speed){
  
  walk_1_3(speed);
  walk_2_4(speed);
  
}
void walk_1_3(int speed){
  
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
  
}
void walk_2_4(int speed){
  
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
  
}

//회전부
void advanced_clock_rotate(int speed){
  
  clock_rotate_1_3(speed);
  clock_rotate_2_4(speed);
  
}

void advanced_anticlock_rotate(int speed){
  
  anticlock_rotate_1_3(speed);
  anticlock_rotate_2_4(speed);
  
}

void clock_rotate_1_3(int speed){
  
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
  
}

void anticlock_rotate_1_3(int speed){
  
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
  
}

void clock_rotate_2_4(int speed){
  
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
  
}
void anticlock_rotate_2_4(int speed){
  
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
  
}














