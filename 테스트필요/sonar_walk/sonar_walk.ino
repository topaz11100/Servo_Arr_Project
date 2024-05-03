
//센서 핀 번호 지정
int trig = 6;
int echo = 7;

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
int speed = 100;
 
void setup(){
  Serial.begin(9600);       // 시리얼 속도 설정
  pinMode(echo, INPUT);   // echoPin 입력    
  pinMode(trig, OUTPUT);  // trigPin 출력    
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

  /*1번
  advanced_walk(speed);
  */

  /*2번
  float dis = distance();
  */

  /*
  3번 2번 값을 유심히 본 뒤, 장애물 판단기준을 정하자
  if(dis < 10){
    //예제1 위의 3.1을 구현해보자 detect함수로 구현하며, 잰 거리의 최대값을 반환하자 함수안 예제도 확인해보자
    float mark = detect(speed);

    //4,5번
    //예제2 나머지를 구현하자 escape함수로 구현하자
    //escape(dis, speed);
  }
  */
}

//예제1
float detect(int speed){
  /*
  float result = 0;
  int angle = 0;
  for(int i=90; i<=180; i+=1){
    turret.write(i);
    float dis = distance();
    if(result<dis){
      result = dis;
      angle = i;
    }
  }
  for(int i=180; i>=0; i-=1){
    turret.write(i);
    float dis = distance();
    if(result<dis){
      result = dis;
      angle = i;
    }
  }
  //예제 포탑이 바라보는 방향이 맞는지 확인해보자
  turret.write(angle);
  return result;
  */
}

//예제2
float escape(float dis, int speed){
  /*
  //바라보고있는쪽이 90이상이면 시계, 아니면 반시계
  if(turret.read()>90){
    //센서오차감안, 범위안에들어오도록 비교
    while(!(dis-1<distsnce() && distsnce()<dis+1)){
      advanced_anticlock_rotate(speed);
    }
  }
  else{
    while(!(dis-1<distsnce() && distsnce()<dis+1)){
      advanced_clock_rotate(speed);
    }
  }
  */
}

float distance(){
  
  float result;
  long duration;
  digitalWrite(trig, HIGH);         
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  dis = ((float)(340 * duration) / 1000) / 2;
  return dis;
  
} 

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


void advanced_clock_rotate(speed){
  
  clock_rotate_1_3(speed);
  clock_rotate_2_4(speed);
  
}

void advanced_anticlock_rotate(speed){
  
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
  servo3_k.write(90);
  delay(speed);

  servo2_f.write(90);
  servo4_f.write(90);

  servo1_f.write(140);
  delay(speed);
  servo1_k.write(90);
  delay(speed);
  servo3_f.write(130);
  delay(speed);
  servo3_k.write(170);
  delay(speed);
  
}

void anticlock_rotate_1_3(int speed){
  
  servo1_f.write(30);
  delay(speed);
  servo1_k.write(90);
  delay(speed);
  servo3_f.write(50);
  delay(speed);
  servo3_k.write(170);
  delay(speed);

  servo2_f.write(90);
  servo4_f.write(90);

  servo1_f.write(140);
  delay(speed);
  servo1_k.write(0);
  delay(speed);
  servo3_f.write(130);
  delay(speed);
  servo3_k.write(90);
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

  servo2_f.write(90);
  servo4_f.write(90);

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
  servo2_k.write(90);
  delay(speed);
  servo4_f.write(130);
  delay(speed);
  servo4_k.write(170);
  delay(speed);

  servo2_f.write(90);
  servo4_f.write(90);

  servo2_f.write(55);
  delay(speed);
  servo2_k.write(10);
  delay(speed);
  servo4_f.write(45);
  delay(speed);
  servo4_k.write(90);
  delay(speed);
  
}














