#include <Servo.h>

Servo m0;
Servo m1;
Servo m2;
Servo m3;
Servo m4;
Servo m5;
Servo m6;
Servo m7;

void setup() {
  Serial.begin(9600);
  init_motor();
}
void init_motor() {
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
  m0.write(90);
  m1.write(90);
  m2.write(90);
  m3.write(90);
  m4.write(90);
  m5.write(90);
  m6.write(90);
  m7.write(90);
}
void read_motor() {
  Serial.print("m0:" + String( m0.read() ) + "  ");
  Serial.print("m1:" + String( m1.read() ) + "  ");
  Serial.print("m2:" + String( m2.read() ) + "  ");
  Serial.print("m3:" + String( m3.read() ) + "  ");
  Serial.print("m4:" + String( m4.read() ) + "  ");
  Serial.print("m5:" + String( m5.read() ) + "  ");
  Serial.print("m6:" + String( m6.read() ) + "  ");
  Serial.println("m7:" + String( m7.read() ));
}
void loop(){
  read_motor();

  String received = Serial.readString();
  if (received.length() == 0) return;

  int stamp = received.indexOf(' ');
  int temp1 = received.substring(0, stamp).toInt();
  int angle = received.substring(stamp + 1).toInt();

  if      (temp1 == 0) m0.write(angle);
  else if (temp1 == 1) m1.write(angle);
  else if (temp1 == 2) m2.write(angle);
  else if (temp1 == 3) m3.write(angle);
  else if (temp1 == 4) m4.write(angle);
  else if (temp1 == 5) m5.write(angle);
  else if (temp1 == 6) m6.write(angle);
  else if (temp1 == 7) m7.write(angle);
}





































