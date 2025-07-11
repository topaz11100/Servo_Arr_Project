#include "Servo_Arr.hpp"
#include "IO_helper.hpp"

const int MOTOR = 8;
const int SPEED = 1000;
const int PIN[MOTOR] = {4,5,6,7,8,9,10,11};

Servo_Arr robot{MOTOR};
// (문자열)(구분자) * size
Protocol p{MOTOR, '/'};

int angle[MOTOR] = {90,90,90,90,90,90,90,90};

void setup()
{
    Serial.begin(9600);
    robot.attach(PIN);
    robot.move_arr(angle, SPEED);
}

void loop()
{
    //형식 문자열 받아 파싱 후 각도에 저장
    String input = receive_String('\n');
    if (!p.receive(input)) return;
    p.store_int_arr(angle);

    //콘솔 표시
    Serial.print("ANGLE = ");
    for (int i = 0; i < MOTOR; i += 1)
    {
        Serial.print(String(angle[i]) + " ");
    }
    Serial.println();
    
    //각도로 서보 실행
    robot.move_arr(angle, SPEED);
}















































