#include <Parts_base.h>

Servo_vector dog{ 4 };
const int dog_pin[4] = {4,5,6,7};

Strip s{',', 3};

const int speed = 3000;

//앞쪽, 뒤쪽
const int limit[4][2] = { { 0, 180}, { 180, 0}, { 0,180 }, { 180, 0} };

void setup()
{
  Serial.begin(9600);
  dog.attach(dog_pin);
  install_position();
}

void install_position(){
  int init[4] = {90,90,
                 90,90};
  dog.move_arr(init, speed);
}

void walk()
{
  int t1[4] = { (limit[0][0] + 90) / 2 , (limit[1][1] + 90) / 2,
                (limit[2][1] + 90) / 2 , (limit[3][0] + 90) / 2};
  dog.move_arr(t1, speed);

  //delay(50);

  //install_position();

  //delay(50);

  int t2[4] = {(limit[0][1] + 90) / 2 , (limit[1][0] + 90) / 2,
               (limit[2][0] + 90) / 2 , (limit[3][1] + 90) / 2};
  dog.move_arr(t2, speed);

  //delay(50);

  install_position();
}

void loop() {
  char r = receive_char('?');
  if      (r == '0') install_position();
  else if (r == '1') walk();
}















