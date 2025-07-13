#include <Servo.h>

Servo motor[8];

//마이크로초
const int speed = 500;

// limit[위치][모드] = {{앞쪽/서는방향한계, 뒤쪽/눕는방향한계}...}
const int limit[8][2] = { { 0, 155 }, { 30, 180 }, { 150, 0 }, { 180, 30 }, { 180, 90 }, { 0, 90 }, { 180, 90 }, { 0, 90 } };
// 발의경우 뒷 원소 밖의 범위는 올라오는 각도이다

const int trigPin = 12;
const int echoPin = 13;

void setup()
{
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    init_motor();
}
void init_motor()
{
    for (int i = 0; i < 8; i += 1)
    {
        motor[i].attach(i + 4);
    }
    init_position();
}
void init_position()
{
    int init[8] = { (limit[0][0] + limit[0][1]) / 2, (limit[1][0] + limit[1][1]) / 2, (limit[2][0] + limit[2][1]) / 2, (limit[3][0] + limit[3][1]) / 2,
                    (limit[4][0] + limit[4][1]) / 2, (limit[5][0] + limit[5][1]) / 2, (limit[6][0] + limit[6][1]) / 2, (limit[7][0] + limit[7][1]) / 2 };
    move_arr(init);
}

bool is_same_arr(int arr[])
{
    for (int i = 0; i < 8; i += 1)
    {
        if (motor[i].read() != arr[i]) return false;
    }
    return true;
}
void move_arr(int arr[])
{
    while (!(is_same_arr(arr)))
    {
        for (int i = 0; i < 8; i += 1)
        {
            int temp = motor[i].read();
            if (temp > arr[i]) motor[i].write(temp - 1);
            else if (temp < arr[i]) motor[i].write(temp + 1);
        }
        delayMicroseconds(speed);
    }
}
void move_one(int num, int angle)
{
    while (true)
    {
        int temp = motor[num].read();
        if (temp > angle) motor[num].write(temp - 1);
        else if (temp < angle) motor[num].write(temp + 1);
        else return;
        delayMicroseconds(speed);
    }
}
void loop()
{
    char received = receive();
    if (received == 'w') walk();
    else if (received == 's') squat();
    else if (received == 'i') init_position();
    else if (received == 'c') rotate(0);
    else if (received == 'z') rotate(1);
    else if (received == 'h') hello();
    else if (received == 't') collision_hello(200);
    else if (received == 'd') Serial.println(distance());
}
char receive()
{
    if (Serial.available()) return Serial.read();
    return '?';
}

void lay()
{
    int temp[8] = { motor[0].read(), motor[1].read(), motor[2].read(), motor[3].read(),
                    limit[4][1], limit[5][1], limit[6][1], limit[7][1] };
    move_arr(temp);
}
void stand()
{
    int temp[8] = { motor[0].read(), motor[1].read(), motor[2].read(), motor[3].read(),
                    limit[4][0], limit[5][0], limit[6][0], limit[7][0] };
    move_arr(temp);
}
void squat()
{
    lay();
    delay(speed / 3);
    stand();
}
void walk()
{
    int posi1[8] = { limit[0][0], motor[1].read(), limit[2][0], motor[3].read(),
                    limit[4][1], limit[5][1] - 10, limit[6][1], limit[7][1] - 10 };
    move_arr(posi1);

    int posi2[8] = { (limit[0][0] + limit[0][1]) / 2, motor[1].read(), (limit[2][0] + limit[2][1]) / 2, motor[3].read(),
                    (limit[4][0] + limit[4][1]) / 2, motor[5].read(), (limit[6][0] + limit[6][1]) / 2, motor[7].read() };
    move_arr(posi2);

    int posi3[8] = { motor[0].read(), limit[1][0], motor[2].read(), limit[3][0],
                    limit[4][1] + 10, limit[5][1], limit[6][1] + 10, limit[7][1] };
    move_arr(posi3);

    int posi4[8] = { motor[0].read(), (limit[1][0] + limit[1][1]) / 2, motor[2].read(), (limit[3][0] + limit[3][1]) / 2,
                    motor[4].read(), (limit[5][0] + limit[5][1]) / 2, motor[6].read(), (limit[7][0] + limit[7][1]) / 2 };
    move_arr(posi4);
}
// mode 0 : 시계 / mode 1 : 반시계
void rotate(int mode) {
    int posi1[8] = { limit[0][mode], motor[1].read(), limit[2][1 - mode], motor[3].read(),
                    limit[4][1], limit[5][1] - 10, limit[6][1], limit[7][1] - 10 };
    move_arr(posi1);

    int posi2[8] = { (limit[0][0] + limit[0][1]) / 2, motor[1].read(), (limit[2][0] + limit[2][1]) / 2, motor[3].read(),
                    (limit[4][0] + limit[4][1]) / 2, motor[5].read(), (limit[6][0] + limit[6][1]) / 2, motor[7].read() };
    move_arr(posi2);

    int posi3[8] = { motor[0].read(), limit[1][mode], motor[2].read(), limit[3][1 - mode],
                    limit[4][1] + 10, limit[5][1], limit[6][1] + 10, limit[7][1] };
    move_arr(posi3);

    int posi4[8] = { motor[0].read(), (limit[1][0] + limit[1][1]) / 2, motor[2].read(), (limit[3][0] + limit[3][1]) / 2,
                    motor[4].read(), (limit[5][0] + limit[5][1]) / 2, motor[6].read(), (limit[7][0] + limit[7][1]) / 2 };
    move_arr(posi4);
}

void hello() {
    init_position();
    move_one(4, 30);
    move_one(0, limit[0][0]);
    delay(speed / 2);
    for (int i = 0; i < 2; i += 1) {
        move_one(0, 45);
        delay(speed / 2);
        move_one(0, 0);
        delay(speed / 2);
    }
    init_position();
}

float distance()
{
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	long duration = pulseIn(echoPin, HIGH);
	float result = ((float)(340 * duration) / 1000) / 2;
	return result;
}
void collision_hello(int thre)
{
    while (true)
    {
        if (distance() <= thre)
        {
            hello();
            return;
        }
        walk();
    }
}
