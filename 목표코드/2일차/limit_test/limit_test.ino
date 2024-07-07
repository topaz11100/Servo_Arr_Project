#include <Servo.h>

Servo motor[8];

void setup() {
  Serial.begin(9600);
  init_motor();
}
void init_motor() {
  for (int i = 0; i < 8; i += 1) {
    motor[i].attach(i + 4);
  }
  init_position();
}
void init_position(){
  for(int i=0; i<8; i+=1){
    motor[i].write(90);
  }
}
void read_motor() {
  for (int i = 0; i < 8; i += 1) {
    String temp = "m" + String(i) + ":" + String(motor[i].read()) + "  ";
    Serial.print(temp);
  }
}
void loop(){
  String received = Serial.readString();
  int l = received.length();
  if (l == 0) return;
  Serial.println(received);
  int stamp = received.indexOf(' ');
  motor[received.substring(0, stamp).toInt()].write(received.substring(stamp + 1).toInt());
}




































