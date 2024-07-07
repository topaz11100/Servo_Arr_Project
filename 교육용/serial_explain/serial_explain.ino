void setup(){
  // 시리얼 통신 기능을 사용하기 위한 명령어
  Serial.begin(9600);
}

void loop(){
  //serial.print("a");
  //serial.println("a");
  //예제 1 아래 함수의 반환값을 시리얼 모니터로 출력해보기
  /* code */
  char a = receive();
  Serial.println(a);
  //Serial.println(Serial.available());
  delay(10);
}

// 프로그래밍의 함수는 수학의 함수와 동일하다
// 공역 이름(정의역)
// 반환형 이름(입력변수)
// 자료형 복습 int, float, char
// 아무것도 반환하지 않으면 void

//예시
int plus_one(int a){
  return a+1;
}

float divide_2(int a){
  return a/2;
}

char A(){
  return 'A';
}

String hello(String name){
  return "hello, " + name;
}

char receive() {
  if (Serial.available()) {
    char temp = Serial.read();
    Serial.println("Received char : " + String(temp));
    return temp;
  }
}






























