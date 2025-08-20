#include "Servo_Arr.hpp"
#include "IO_helper.hpp"

const int ARM = 5;
Servo_Arr arm{ ARM };
const int arm_pin[ARM] = { 4, 5, 6, 7, 8 };

//마이크로초
const int speed = 5000;

// limit[위치][모드] = {{앞쪽/서는방향한계, 뒤쪽/눕는방향한계}...}
const int limit[ARM][2] = { {0, 155}, {30, 180}, {150, 0}, {180, 30}, {170 , 90} };

void setup()
{
    Serial.begin(9600);
    arm.attach(arm_pin);
}

void init()
{
    const int angle[Arm] = {90, 90, 90, 90, 90};
    arm.move_arr(angle, speed);
}

void move()
{
    const int angle[Arm] = {90, 90, 90, 90, 90};
    arm.move_arr(angle, speed);
}

void loop()
{
    switch(receive_char('?'))
    {
        case 'i':
            init();
            break;
        case 'a':
            move();
            break;
    }
}














