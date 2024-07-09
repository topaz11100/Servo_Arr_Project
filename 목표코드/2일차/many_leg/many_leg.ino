#include <Servo.h>

Servo m0;
Servo m1;
Servo m2;
Servo m3;
Servo m4;
Servo m5;
Servo m6;
Servo m7;

int speed = 500;

void setup(){
  Serial.begin(9600);

  m0.attach(4);
  m1.attach(5);
  m2.attach(6);
  m3.attach(7);
  m4.attach(8);
  m5.attach(9);
  m6.attach(10);
  m7.attach(11);

  init_position();
}

void init_position(){
  m0.write(77);
  m1.write(105);
  m2.write(75);
  m3.write(105);
  m4.write(135);
  m5.write(45);
  m6.write(135);
  m7.write(45);
}

void loop(){
  char received = receive();
  if      (received == 'a') walk();
  else if (received == 'b') advanced_walk();
}
char receive(){
  if(Serial.available()) return Serial.read();
  return '?';
}

void walk(){
  walk_1();
  walk_3();
  walk_2();
  walk_4();
}
void walk_1(){
  m4.write(90);
  delay(speed);
  m0.write(0);
  delay(speed);
  m4.write(180);
  delay(speed);
  m0.write(77);
  delay(speed);
}
void walk_2(){
  m5.write(90);
  delay(speed);
  m1.write(30);
  delay(speed);
  m5.write(0);
  delay(speed);
  m1.write(105);
  delay(speed);
}
void walk_3(){
  m6.write(90);
  delay(speed);
  m2.write(150);
  delay(speed);
  m6.write(180);
  delay(speed);
  m2.write(75);
  delay(speed);
}
void walk_4(){
  m7.write(90);
  delay(speed);
  m3.write(180);
  delay(speed);
  m7.write(0);
  delay(speed);
  m3.write(105);
  delay(speed);
}

void advanced_walk(){

}
void walk_1_3(){

}
void walk_2_4(){
  
}
















