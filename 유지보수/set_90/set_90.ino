#include "Servo.h"
  
Servo s0;
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;
Servo s7;

void setup()
{
    Serial.begin(9600);
    s0.attach(4);
    s1.attach(5);
    s2.attach(6);
    s3.attach(7);
    s4.attach(8);
    s5.attach(9);
    s6.attach(10);
    s7.attach(11);
}

void loop()
{
    s0.write(90);
    s1.write(90);
    s2.write(90);
    s3.write(90);
    s4.write(90);
    s5.write(90);
    s6.write(90);
    s7.write(90);

    Serial.println("set at 90");
}















































