// 초음파 센서로 거리재기

//핀 번호 지정
int trig = 12;
int echo = 13;
 
void setup(){
  Serial.begin(9600);       // 시리얼 속도 설정
  pinMode(echo, INPUT);   // echoPin 입력    
  pinMode(trig, OUTPUT);  // trigPin 출력                                                                                                                                                       
}
 
void loop(){
  /*
  초음파 센서는 trig에서 발생한 초음파가 echo에 닿았는지 알게 해주어
  센서와 물체의 거리를 측정해줍니다
  거리 * 2 = trig에서 발생한 초음파가 echo에 닿을때까지 걸린 시간 * 음속
  */
  long duration, distance; //측정을 위한 변수들

  //trig를 진동시켜 초음파 발생
  digitalWrite(trig, HIGH);         
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  // 따라서 초음파가 되돌아온 시간이 저장된다.
  duration = pulseIn(echo, HIGH);

  //음속은 340m/s이다 1000으로 나눴으므로 단위는 mm이다.
  distance = ((float)(340 * duration) / 1000) / 2; 
 
  // 물체와 초음파 센서간 거리를 표시
  Serial.print("Distance:");        
  Serial.print(distance);
  Serial.println("mm\n");
}  
















