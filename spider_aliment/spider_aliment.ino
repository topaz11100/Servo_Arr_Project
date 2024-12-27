#include "Servo_Vector.h"
#include "IO_helper.h"

const int motor_count = 8;

Servo_vector spider{motor_count};
const int spider_pin[motor_count] = {4,5,6,7,8,9,10,11};
const int speed = 500;
int angle[motor_count] = {90,90,90,90,90,90,90,90};

Protocol p{',', motor_count};

void setup()
{
  Serial.begin(9600);
  spider.attach(spider_pin);
  spider.move_arr(angle, speed);
}

void loop()
{
  String input = receive_String('\n');
  if (input.equals("")) return;
  p.strip(input);
  p.fillintarr(angle);
  spider.move_arr(angle, speed);
}















































