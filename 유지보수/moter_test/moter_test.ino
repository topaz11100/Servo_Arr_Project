#include "Servo_Arr.hpp"

const int = MOTOR 8;
const int = SPEED 500;
const int PIN[MOTOR] = {4,5,6,7,8,9,10,11};

Servo_Arr robot{MOTOR};

const int a0[8] = {0,0,0,0,0,0,0,0};
const int a180[8] = {180,180,180,180,180,180,180,180};
  
void setup()
{
  robot.attach(PIN);
}

void loop()
{
  robot.move_arr(a0, SPEED);
  delay(100);
  robot.move_arr(a180, SPEED);
  delay(100);
}















































