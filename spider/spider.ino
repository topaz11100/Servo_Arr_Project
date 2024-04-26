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
const int walk_arr[4] = {1,2,3,4};

void init_motor(){
  for(int i=0; i<4; i+=1){
    leg[i].attach(i+4);
    foot[i].attach(i+8);
  }
}

void read_motor(){
  for(int i=0; i<4; i+=1){
    String temp = String(i) + "th motor angle "
                  "leg : " + String(leg[i].read()) + " "
                  "foot : " + String(foot[i].read());
    Serial.println(temp);
  }
}

void lay(int speed){
  int temp[4] = {0,0,0,0};
  move_arr(foot, temp, speed);
}

void stand(int speed){
  int temp[4] = {180,180,180,180};
  move_arr(foot, temp, speed);
}

void move_arr(Servo motor[], int arr[], int speed){
  bool check[4] = {false, false, false, false};
  while (!(check[0]&&check[1]&&check[2]&&check[3])){
    for(int i=0; i<4; i+=1){
      int temp = motor[i].read();
      if     (temp > arr[i]) motor[i].write(temp - 1);
      else if(temp < arr[i]) motor[i].write(temp + 1);
      else check[i] = true;
      delay(speed);
    }
  }
}

void move_angle(Servo motor, int angle, int speed){
  while(true){
    int temp = motor.read();
    if(temp > angle) motor.write(temp - 1);
    else if(temp < angle) motor.write(temp + 1);
    else return;
    delay(speed);
  }
}

void test(int speed){
  move_angle(leg[2], 140, speed);
  move_angle(foot[2], 0, speed);
  move_angle(leg[2], 0, speed);
  move_angle(foot[2], 180, speed);
}

void setup() {
  Serial.begin(9600);
  init_motor();
}

char receive(){
  if(Serial.available()){
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
