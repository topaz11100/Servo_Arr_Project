#include "Servo_Arr.hpp"
#include "IO_helper.hpp"
#include "base_part.hpp"

#define motor 8
#define trig 10
#define echo 11
#define speed 200

Servo_Arr robot(motor);
Ultrasonic dist;

constexpr int attach_pin[motor] = {4,5,6,7,8,9,10,11};

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













