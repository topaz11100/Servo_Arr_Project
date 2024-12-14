#include "Servo_vector.h"
#include "IO_helper.h"

const int motor_count = 8;

Servo_vector spider{motor_count};
const int spider_pin[motor_count] = {4,5,6,7,8,9,10,11};
const int speed = 500;

Protocol p{',', motor_count};
int angle[motor_count] = {90,90,90,90,90,90,90,90};

void setup()
{
  Serial.begin(9600);
  spider.attach(spider_pin);
  spider.move_arr(angle, speed);
}

void fill_angle()
{
  for(int i = 0; i < motor_count; i++)
  {
    angle[i] = p[i].toInt();
  }
}

void loop()
{
  String input = receive_String('\n');
  p.strip(input);
  fill_angle();
  spider.move_arr(angle, speed);
}















































