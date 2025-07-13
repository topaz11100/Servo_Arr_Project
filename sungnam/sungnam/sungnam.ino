#include "Servo_Arr.hpp"
#include "IO_helper.hpp"
#include "base_part.hpp"

const int motor = 8;
const int trig  = 13;
const int echo  = 12;
const int speed = 500;
const int robot_pin[motor] = {4,5,6,7,8,9,10,11};

Servo_Arr robot{motor};
Ultrasonic dist;

// limit[위치][모드] = {{앞쪽/서는방향한계, 뒤쪽/눕는방향한계}...}
const int limit[8][2] = {{0,  155}, {30, 180}, {150,  0}, {180, 30},
                          {90,  0}, {90, 180},  {90,  0}, {90, 180}};

void setup()
{
    Serial.begin(9600);
    robot.attach(robot_pin);
    init_position();
    dist.init(trig, echo);
}

void init_position()
{
    int init[8] = { (limit[0][0] + limit[0][1]) / 2,  (limit[1][0] + limit[1][1]) / 2,  (limit[2][0] + limit[2][1]) / 2,  (limit[3][0] + limit[3][1]) / 2,
                    (limit[4][0] + limit[4][1]) / 2,  (limit[5][0] + limit[5][1]) / 2,  (limit[6][0] + limit[6][1]) / 2,  (limit[7][0] + limit[7][1]) / 2 };
    robot.move_arr(init, speed);
}
void lay()
{
    int temp[8] = { robot.angle_at(0), robot.angle_at(1), robot.angle_at(2), robot.angle_at(3),
                    limit[4][1], limit[5][1], limit[6][1], limit[7][1] };
    robot.move_arr(temp, speed);
}
void stand()
{
    int temp[8] = { robot.angle_at(0), robot.angle_at(1), robot.angle_at(2), robot.angle_at(3),
                    limit[4][0], limit[5][0], limit[6][0], limit[7][0] };
    robot.move_arr(temp, speed);
}
void squat()
{
    lay();
    delay(speed >> 2);
    stand();
    init_position();
}
void walk()
{
    init_position();
    int posi1[8] = { limit[0][0],  robot.angle_at(1),  limit[2][0],  robot.angle_at(3),
                     limit[4][1],  limit[5][1] - 20,   limit[6][1],  limit[7][1] - 20 };
    robot.move_arr(posi1, speed);

    int posi2[8] = { (limit[0][0] + limit[0][1]) / 2,  robot.angle_at(1),  (limit[2][0] + limit[2][1]) / 2,  robot.angle_at(3),
                      limit[4][0],  robot.angle_at(5),  limit[6][0],  robot.angle_at(7) };
    robot.move_arr(posi2, speed);

    int posi3[8] = { robot.angle_at(0),  limit[1][0],  robot.angle_at(2), limit[3][0],
                     limit[4][1] + 20,   limit[5][1],  limit[6][1] + 20,  limit[7][1] };
    robot.move_arr(posi3, speed);

    int posi4[8] = { robot.angle_at(0),  (limit[1][0] + limit[1][1]) / 2,  robot.angle_at(2),  (limit[3][0] + limit[3][1]) / 2,
                     robot.angle_at(4),  limit[5][0],  robot.angle_at(6),  limit[7][0] };
    robot.move_arr(posi4, speed);
    init_position();
}
// mode 0 : 시계 / mode 1 : 반시계
void rotate(int mode)
{
    init_position();
    int posi1[8] = { limit[0][mode],  robot.angle_at(1),  limit[2][1 - mode],  robot.angle_at(3),
                     limit[4][1],  limit[5][1] - 20,   limit[6][1],  limit[7][1] - 20 };
    robot.move_arr(posi1, speed);

    int posi2[8] = { (limit[0][0] + limit[0][1]) / 2,  robot.angle_at(1),  (limit[2][0] + limit[2][1]) / 2,  robot.angle_at(3),
                      limit[4][0],  robot.angle_at(5),  limit[6][0],  robot.angle_at(7) };
    robot.move_arr(posi2, speed);

    int posi3[8] = { robot.angle_at(0),  limit[1][mode],  robot.angle_at(2), limit[3][1 - mode],
                     limit[4][1] + 20,   limit[5][1],  limit[6][1] + 20,  limit[7][1] };
    robot.move_arr(posi3, speed);

    int posi4[8] = { robot.angle_at(0),  (limit[1][0] + limit[1][1]) / 2,  robot.angle_at(2),  (limit[3][0] + limit[3][1]) / 2,
                     robot.angle_at(4),  limit[5][0],  robot.angle_at(6),  limit[7][0] };
    robot.move_arr(posi4, speed);
    init_position();
}

void hello()
{
    robot.move_one(4, 180, speed);
    int temp[4] = {0, 60, 0, 60};
    for (int i = 0; i < 4; i += 1)
    {
        robot.move_one(0, temp[i], speed);
        delay(speed/5);
    }
    init_position();
}

void walk_until_cossision(int thre)
{
    while (dist.distance() > thre)
        walk();
    hello();
}

void loop()
{
    char r = Rx::recv_char('?');
    switch(r)
    {
        case 'w':
            walk();
            break;
        case 'a':
            rotate(0);
            break;
        case 'd':
            rotate(1);
            break;
        case 's':
            squat();
            break;
        case 'u':
            Serial.println(dist.distance());
            break;
        case 'h':
            hello();
            break;
        case 'i':
            init_position();
            break;
        case 'z':
            walk_until_cossision(150);
            break;
        default:
            break;
    }
}













