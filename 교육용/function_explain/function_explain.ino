void setup(){
  Serial.begin(9600);  
}

void loop(){
  hello_name("han");
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

void hello_world(){
  Serial.println("hello, world");
}

void hello_name(String name){
  Serial.println(name);
}
































