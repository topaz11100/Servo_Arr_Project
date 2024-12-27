#include "Servo_Vector.h"

const int motor_count = 8;

Servo_vector spider{motor_count};
const int spider_pin[motor_count] = {4,5,6,7,8,9,10,11};
const int speed = 1500;

const int a0[8] = {0,0,0,0,0,0,0,0};
const int a180[8] = {180,180,180,180,180,180,180,180};
  
void setup()
{
  spider.attach(spider_pin);
}

void loop()
{
  spider.move_arr(a0, speed);
  delay(10);
  spider.move_arr(a180, speed);
  delay(10);
}















































