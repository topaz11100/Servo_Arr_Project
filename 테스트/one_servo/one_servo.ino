#include <Servo.h>

Servo m;

void setup(){
  Serial.begin(9600);
  m.attach(11);
}

void loop(){
  switch(receive()){
    case 'a':
      m.write(0);
      delay(500);
      break;
    case 'b':
      m.write(100);
      delay(500);
      break;
  }
}
char receive(){
  if(Serial.available()){
    char a = Serial.read();
    return a;
  }
}



































