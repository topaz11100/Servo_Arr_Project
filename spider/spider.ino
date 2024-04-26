/* 

   (모터주소, 연결핀)
   __________ __________ _________________
  |(f[0],8)__(l[0],4)  (l[3],7) _(f[4],11)|
  |__|       |       ^        |        |__|
             |       앞       |
             |                |
             |                |
   _________ |                | __________
  |(f[1],9)__(l[1],5)__(l[2],6)__(f[3],10)|
  |__|                                 |__|

*/

#include <Servo.h>

Servo leg[4];
Servo foot[4];

const int speed = 1;

// _limit[위치][모드] = {{앞쪽/서는방향한계, 뒤쪽/눕는방향한계}...}
// 측정필요
const int leg_limit[4][2] =  { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };
const int foot_limit[4][2] = { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

void init_motor() {
  for (int i = 0; i < 4; i += 1) {
    leg[i].attach(i + 4);
    foot[i].attach(i + 8);
  }
}

void read_motor() {
  for (int i = 0; i < 4; i += 1) {
    String temp = String(i) + "th motor angle " +
                  "leg : " + String(leg[i].read()) + " "
                  "foot : " + String(foot[i].read());
    Serial.println(temp);
  }
}

void lay(int speed) {
  int temp[4] = { foot_limit[0][1], foot_limit[1][1], foot_limit[2][1], foot_limit[3][1] };
  move_arr(foot, temp, speed);
}

void stand(int speed) {
  int temp[4] = { foot_limit[0][0], foot_limit[1][0], foot_limit[2][0], foot_limit[3][0] };
  move_arr(foot, temp, speed);
}

void move_arr(Servo motor[], int arr[], int speed) {
  bool check[4] = { false, false, false, false };
  while (!(check[0] && check[1] && check[2] && check[3])) {
    for (int i = 0; i < 4; i += 1) {
      int temp = motor[i].read();
      if      (temp > arr[i]) motor[i].write(temp - 1);
      else if (temp < arr[i]) motor[i].write(temp + 1);
      else    check[i] = true;
      delay(speed);
    }
  }
}

void move_legfoot(int num, int arr[], int speed) {
  bool check[2] = { false, false };
  while(!(check[0] && check[1])) {
    int temp[2] = { leg[num].read(), foot[num].read() };

    if      (temp[0] > arr[0]) leg[num].write(temp[0] - 1);
    else if (temp[0] < arr[0]) leg[num].write(temp[0] + 1);
    else    check[0] = true;

    if      (temp[1] > arr[1]) leg[num].write(temp[1] - 1);
    else if (temp[1] < arr[1]) leg[num].write(temp[1] + 1);
    else    check[1] = true;

    delay(speed);
  }
}

void move_angle(Servo motor, int angle, int speed) {
  while (true) {
    int temp = motor.read();
    if      (temp > angle) motor.write(temp - 1);
    else if (temp < angle) motor.write(temp + 1);
    else return;
    delay(speed);
  }
}

void test(int speed){
  int forward[4] = {leg_limit[0][0], leg_limit[0][1], leg_limit[0][2], leg_limit[0][3]};
  int back[4] =    {leg_limit[0][0], leg_limit[0][1], leg_limit[0][2], leg_limit[0][3]};
  move_arr(leg, forward, speed);
  stand(speed);
  move_arr(leg, back, speed);
  lay(speed);
}

void setup() {
  Serial.begin(9600);
  init_motor();
}

char receive() {
  if (Serial.available()) {
    char temp = Serial.read();
    Serial.println("Received char : " + temp);
    return temp;
  }
}

void loop() {
  char received = receive();
  
  test(speed);
  
  read_motor();
}
