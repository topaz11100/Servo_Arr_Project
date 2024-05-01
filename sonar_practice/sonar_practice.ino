// 초음파 센서로 거리재기

//핀 번호 지정
int trig = 6;
int echo = 7;

//포탑 돌릴 모터
Servo turret;

//속도
int speed = 10;
 
void setup(){
  Serial.begin(9600);       // 시리얼 속도 설정
  pinMode(echo, INPUT);   // echoPin 입력    
  pinMode(trig, OUTPUT);  // trigPin 출력    
}
 
void loop(){
  /*
  예제1 앞에서 배운 초음파 관련 코드를 이용해
  float형 거리를 반환하는 함수 distance와 이를 이용해 
  시리얼 모니터에 거리를 띄워보자
  
  float dis = distance();
  Serial.print("distance : ");
  Serial.println(dis);
  */
  /*
  예제2
  포탑을 돌려가며 각도와 거리를 측정해보자
  for(int i=90; i<=180; i+=1)
  {
    turret.write(i);
    Serial.println("angle : " + String(turret.read())
                  + "distance : " + String(distance()));
  }
  for(int i=180; i>=0; i-=1)
  {
   turret.write(i);
   Serial.println("angle : " + String(turret.read())
                  + "distance : " + String(distance()));
  }
  for(int i=0; i<=90; i+=1)
  {
   turret.write(i);
   Serial.println("angle : " + String(turret.read())
                  + "distance : " + String(distance()));
  }
  */
}
float distance(){
  /*
  float result;
  long duration;
  digitalWrite(trig, HIGH);         
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  dis = ((float)(340 * duration) / 1000) / 2;
  return dis;
  */ 
} 
















