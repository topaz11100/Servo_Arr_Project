#include "Servo_Arr.hpp"
#include "IO_helper.hpp"
#include "base_part.hpp"

const int motor = 8;
const int trig  = 10;
const int echo  = 11;
const int speed = 200;
const int attach_pin[motor] = {4,5,6,7,8,9,10,11};

Servo_Arr robot(motor);
Ultrasonic dist;

void setup()
{
    Serial.begin(9600);
    robot.attach(attach_pin);
    dist.init(trig, echo);
}

void lay()
{
    int angle[motor] = { , , , 
                         , , ,  };
    robot.move_arr(angle, speed);
}

void stand()
{
    int angle[motor] = { , , , 
                         , , ,  };
    robot.move_arr(angle, speed);
}

void walk()
{
    int angle0[motor] = { , , , 
                         , , ,  };
    robot.move_arr(angle0, speed);
    int angle1[motor] = { , , , 
                         , , ,  };
    robot.move_arr(angle1, speed);
}

void rotate()
{
    int angle0[motor] = { , , , 
                         , , ,  };
    robot.move_arr(angle0, speed);
    int angle1[motor] = { , , , 
                         , , ,  };
    robot.move_arr(angle1, speed);
}

void hello()
{

}

void loop()
{
    char r = receive_char('?');
    switch(r)
    {
        case 'w':
            walk();
            break;
        case 'h':
            hello();
            break;
        case 'd':
            Serial.println(dist.distance());
        default:
            break;
    }
}













