//아두이노는 직렬통신(시리얼)기ㅏ능을 지원해 pc와 통신을 할 수 있다
void setup(){
  // 시리얼 통신 시작 && 속도 설정
  Serial.begin(9600);
}
 
void loop(){

  /* 
  아두이노 ide의 시리얼 모니터 를 이용해
  1. 아두이노에서 pc로 온 값을 볼 수 있다
  2. pc에서 아두이노로 값을 보낼 수 있다
  */

  /*
  아두이노에서 pc로 값을 보낼때는
  Serial.print()
  Serial.println()을 주로 사용한다.
  입력에는 숫자, 문자열이 들어갈 수 있다
  두개 이상의 변수를  쓰고 싶은 경우 문자열이 아닌 변수에
  String()  함수를 적용해 문자열로 바꿔야 한다
  */

  /*
  Serial.print(10);
  Serial.println("hello world");
  int test = 333;
  Serial.println("test = " + String(test));
  */

  /*
  아두이노로 pc에서 보낸 값을 확인할때는
  Serial.read() 를 많이 사용한다.
  Serial.read()는 아두이노가 받은 문자를 한 글자 출력한다 -> char형
  시리얼 모니터를 이용해 값을 보내고 확인해보자
  */

  /*
  if(Serial.available()){
    char result = Serial.read();
    Serial.println("받은 문자 = " + String(result));
  }
  */
  
  //예제1 pc가 준 값을 한 개의 문자로 반환하는 receive함수를 작성하고 반환값을 loop에서 표시해보자
  /*
  char received = receive();
  Serial.println("reveived char = " + String(received));
  */
} 
char receive() {
  /*
  if (Serial.available()) {
    char temp = Serial.read();
    Serial.println("Received char : " + String(temp));
    return temp;
  }
  */
}














