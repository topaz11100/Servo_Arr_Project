#include "Servo_Arr.h"

#define MOTOR 8
#define speed 500

Servo_Arr spider{MOTOR};
const int spider_pin[MOTOR] = {4,5,6,7,8,9,10,11};

const int a0[8] = {0,0,0,0,0,0,0,0};
const int a180[8] = {180,180,180,180,180,180,180,180};
  
void setup()
{
  spider.attach(spider_pin);
}

void loop()
{
  spider.move_arr(a0, speed);
  delay(100);
  spider.move_arr(a180, speed);
  delay(100);
}















































