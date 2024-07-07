#include <Servo.h>

Servo m0;
Servo m1;
Servo m2;
Servo m3;
Servo m4;
Servo m5;
Servo m6;
Servo m7;

int speed = 100;

void setup(){
  m0.attach(4);
  m1.attach(5);
  m2.attach(6);
  m3.attach(7);
  m4.attach(8);
  m5.attach(9);
  m6.attach(10);
  m7.attach(11);

  m0.write(90);
  m1.write(90);
  m2.write(90);
  m3.write(90);
  m4.write(90);
  m5.write(90);
  m6.write(90);
  m7.write(90);

  Serial.begin(9600);
}

void loop(){
  char received = receive();
  if      (received == 'a'){
    move(0);
  }
  else if (received == 'b'){
    move(180);
  }
}
char receive(){
  if(Serial.available()) return Serial.read();
  return '?';
}

void move(int angle){
  m0.write(angle);
  delay(speed);
  m1.write(angle);
  delay(speed);
  m2.write(angle);
  delay(speed);
  m3.write(angle);
  delay(speed);
  m4.write(angle);
  delay(speed);
  m5.write(angle);
  delay(speed);
  m6.write(angle);
  delay(speed);
  m7.write(angle);
  delay(speed);
  m0.write(90);
  delay(speed);
  m1.write(90);
  delay(speed);
  m2.write(90);
  delay(speed);
  m3.write(90);
  delay(speed);
  m4.write(90);
  delay(speed);
  m5.write(90);
  delay(speed);
  m6.write(90);
  delay(speed);
  m7.write(90);
  delay(speed);
}



































