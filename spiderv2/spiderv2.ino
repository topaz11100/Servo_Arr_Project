/* 

   (모터주소, 연결핀)
   __________ __________ _________________
  |(4,8)__(0,4)              (3,7) _(7,11)|
  |__|       |       ^        |        |__|
             |       앞       |
             |                |
             |                |
   _________ |                | __________
  |(5,9)__(1,5)__            (2,6)__(6,10)|
  |__|                                 |__|

*/

#include <Servo.h>

Servo motor[8];

const int speed = 1;

// limit[위치][모드] = {{앞쪽/서는방향한계, 뒤쪽/눕는방향한계}...}
// 측정필요
const int limit[8][2] =  { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, 
                           { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }};

void init_motor() {
  int init[8] = {(limit[0][0]+limit[0][1])/2,  (limit[1][0]+limit[1][1])/2,  (limit[2][0]+limit[2][1])/2,  (limit[3][0]+limit[3][1])/2,
                 (limit[4][0]+limit[4][1])/2,  (limit[5][0]+limit[5][1])/2,  (limit[6][0]+limit[6][1])/2,  (limit[7][0]+limit[7][1])/2 };
  for (int i = 0; i < 8; i += 1) {
    motor[i].attach(i + 4);
  }
  move_arr(init, speed);
}

void read_motor() {
  for (int i = 0; i < 8; i += 1) {
    String temp = String(i) + "th motor angle " + String(motor[i].read());
    Serial.println(temp);
  }
}

void lay(int speed) {
  int temp[8] = { 0, 0, 0, 0,
                  limit[4][1], limit[5][1], limit[6][1], limit[7][1] };
  move_arr(temp, speed);
}

void stand(int speed) {
  int temp[8] = { 0, 0, 0, 0,
                  limit[4][0], limit[5][0], limit[6][0], limit[7][0] };
  move_arr(temp, speed);
}

void move_arr(int arr[], int speed) {
  bool check[8] = { false, false, false, false, false, false, false, false };
  while (!(check[0] && check[1] && check[2] && check[3]
        && check[4] && check[5] && check[6] && check[7])) {
    for (int i = 0; i < 8; i += 1) {
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
    for (int i = 0; i < 2; i += 1) {
      int temp = motor[num + 4*i].read();
      if      (temp > arr[i]) motor[num + 4*i].write(temp - 1);
      else if (temp < arr[i]) motor[num + 4*i].write(temp + 1);
      else    check[i] = true;
      delay(speed);
    }
  }
}

void move_angle(int num, int angle, int speed) {
  while (true) {
    int temp = motor[num].read();
    if      (temp > angle) motor[num].write(temp - 1);
    else if (temp < angle) motor[num].write(temp + 1);
    else return;
    delay(speed);
  }
}

void walk(int speed){
  int forward[8] = {limit[0][0],limit[1][0],limit[2][0],limit[3][0],
                    limit[4][0],limit[5][0],limit[6][0],limit[7][0]};
  int back[8]    = {limit[0][1],limit[1][1],limit[2][1],limit[3][1],
                    limit[4][1],limit[5][1],limit[6][1],limit[7][1]};
  move_arr(forward,speed);
  stand(speed);
  move_arr(back,speed);
  lay(speed);
}

void walk2(int speed){
  lay(speed);
  stand(speed);
}

char receive() {
  if (Serial.available()) {
    char temp = Serial.read();
    Serial.println("Received char : " + temp);
    return temp;
  }
}

void setup() {
  Serial.begin(9600);
  init_motor();
}
void loop() {
  char received = receive();
  switch(received){
    case 'w':
      walk(speed);
      break;
    case 'e':
      walk2(speed);
      break;
  }
  read_motor();
}
