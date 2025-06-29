#include "Servo_Arr.h"
#include "IO_helper.h"

#define MOTOR 8
#define speed 500

Servo_Arr spider{MOTOR};
const int spider_pin[MOTOR] = {4,5,6,7,8,9,10,11};

Protocol p{',', MOTOR};

int angle[MOTOR] = {90,90,90,90,90,90,90,90};

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















































