#include <Parts_base.h>
#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

Servo_vector spider{8};
const int spider_pin[8] = {4,5,6,7,8,9,10,11};

Servo turret;
const int turret_pin = 3;

//마이크로초
const int speed = 500;

// limit[위치][모드] = {{앞쪽/서는방향한계, 뒤쪽/눕는방향한계}...}
const int limit[8][2] = { {0, 155}, {30, 180}, {150, 0}, {180, 30},
	                        {180 , 90}, {0, 90}, {180, 90}, {0, 90} };

void setup()
{
  Serial.begin(115200);
  init_spider();
  lox.begin();
}
void init_spider()
{
  spider.attach(spider_pin);
  turret.attach(turret_pin);
  init_position();
}
void init_position()
{
  int init[8] = {(limit[0][0]+limit[0][1])/2,  (limit[1][0]+limit[1][1])/2,  (limit[2][0]+limit[2][1])/2,  (limit[3][0]+limit[3][1])/2,
                 (limit[4][0]+limit[4][1])/2,  (limit[5][0]+limit[5][1])/2,  (limit[6][0]+limit[6][1])/2,  (limit[7][0]+limit[7][1])/2 };
  spider.move_arr(init, speed);
  turret.write(90);
}
void loop()
{
  
  char received = receive_char('?');
  if      (received == 'w') walk();
  else if (received == 's') squat();
  else if (received == 'i') init_position();
  else if (received == 'c') rotate(0);
  else if (received == 'z') rotate(1);
  else if (received == 'h') hello();
  else if (received == 'm') swim();
  else if (received == 't') tank_walk(300);
  else if (received == 'v') avoid_walk(200);
  else if (received == '1') install();
  else if (received == '2') turret_rotation_test();
  else if (received == '3') init_init();
  
  Serial.print("Distance (mm): ");
  Serial.println(distance());
  /*
  init_init();
  delay(500);
  walk();
  walk();
  walk();
  init_position();
  delay(500);
  hello();
  init_position();
  delay(500);
  squat();
  delay(500);
  squat();
  delay(500);
  squat();
  delay(500);
  init_position();
  delay(500);
  rotate(0);
  rotate(0);
  rotate(0);
  init_position();
  delay(500);
  rotate(1);
  rotate(1);
  rotate(1);
  delay(500);
  turret_rotation_test();
  turret_rotation_test();
  delay(500);
  swim();
  swim();
  delay(500);
  */

  //Serial.print("Distance (mm): ");
  //Serial.println(distance());
}

void init_init()
{
  int temp[8] = {0,180,0,180,
                  90,90,90,90};
  spider.move_arr(temp, speed);
  delay(5000);
  init_position();
}

void install()
{
  int temp[8] = {90, 90, 90, 90,
                 90, 90, 90, 90};
  spider.move_arr(temp, speed);
}

void lay()
{
  int temp[8] = { spider[0].read(), spider[1].read(), spider[2].read(), spider[3].read(),
                  limit[4][1], limit[5][1], limit[6][1], limit[7][1] };
  spider.move_arr(temp, speed);
}
void stand()
{
  int temp[8] = { spider[0].read(), spider[1].read(), spider[2].read(), spider[3].read(),
                  limit[4][0], limit[5][0], limit[6][0], limit[7][0] };
  spider.move_arr(temp, speed);
}
void squat()
{
  lay();
  delay(speed/3);
  stand();
}
void walk()
{
  int posi1[8]={ limit[0][0],  spider[1].read(),  limit[2][0],  spider[3].read(),
                 limit[4][1],  limit[5][1]-20,   limit[6][1],  limit[7][1]-20 };
  spider.move_arr(posi1, speed);

  int posi2[8] = {(limit[0][0]+limit[0][1])/2,  spider[1].read(),  (limit[2][0]+limit[2][1])/2,  spider[3].read(),
                  limit[4][0],  spider[5].read(),  limit[6][0],  spider[7].read() };
  spider.move_arr(posi2, speed);

  int posi3[8]={ spider[0].read(),  limit[1][0],  spider[2].read(), limit[3][0],
                 limit[4][1]+20,   limit[5][1],  limit[6][1]+20,  limit[7][1] };
  spider.move_arr(posi3, speed);

  int posi4[8] = {spider[0].read(),  (limit[1][0]+limit[1][1])/2,  spider[2].read(),  (limit[3][0]+limit[3][1])/2,
                  spider[4].read(),  limit[5][0],  spider[6].read(),  limit[7][0] };
  spider.move_arr(posi4, speed);
}
// mode 0 : 시계 / mode 1 : 반시계
void rotate(int mode)
{
  int posi1[8]={ limit[0][mode],  spider[1].read(),  limit[2][1-mode],  spider[3].read(),
                 limit[4][1],  limit[5][1]-20,   limit[6][1],  limit[7][1]-20 };
  spider.move_arr(posi1, speed);

  int posi2[8] = {(limit[0][0]+limit[0][1])/2,  spider[1].read(),  (limit[2][0]+limit[2][1])/2,  spider[3].read(),
                  limit[4][0],  spider[5].read(),  limit[6][0],  spider[7].read() };
  spider.move_arr(posi2, speed);

  int posi3[8]={ spider[0].read(),  limit[1][mode],  spider[2].read(), limit[3][1-mode],
                 limit[4][1]+20,   limit[5][1],  limit[6][1]+20,  limit[7][1] };
  spider.move_arr(posi3, speed);

  int posi4[8] = {spider[0].read(),  (limit[1][0]+limit[1][1])/2,  spider[2].read(),  (limit[3][0]+limit[3][1])/2,
                  spider[4].read(),  limit[5][0],  spider[6].read(),  limit[7][0] };
  spider.move_arr(posi4, speed);
}

void hello()
{
  init_position();
  spider.move_one(4, 30, speed);
  spider.move_one(0, limit[0][0], speed);
  delay(speed/2);
  for(int i=0; i<2; i+=1){
    spider.move_one(0, 45, speed);
    delay(speed/2);
    spider.move_one(0, 0, speed);
    delay(speed/2);
  }
  init_position();
}

void swim()
{
  int forward[8] = {limit[0][0],limit[1][0],limit[2][0],limit[3][0],
                    limit[4][0],limit[5][0],limit[6][0],limit[7][0]};
  int back[8]    = {limit[0][1],limit[1][1],limit[2][1],limit[3][1],
                    limit[4][1],limit[5][1],limit[6][1],limit[7][1]};
  spider.move_arr(forward, speed);
  stand();
  delay(speed/2);
  spider.move_arr(back, speed);
  lay();
  delay(speed/2);
  init_position();
}

int distance()
{
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure);
  return measure.RangeMilliMeter;
  //예외는 센서 최대거리이상일때인데 그냥 최대거리반환하게하면된다
}

void tank_walk(float s)
{
  while (true)
  {
    if(distance() <= s)
    {
      hello();
      return;
    }
    else
    {
      walk();
    }
  }
}

void turret_rotation_test()
{
  for(int i=turret.read(); i>0; i-=1)
  {
    turret.write(i);
    //Serial.println(distance());
    delay(10);
  }
  for(int i=0; i<180; i+=1)
  {
    turret.write(i);
    //Serial.println(distance());
    delay(10);
  }
  for(int i=180; i >90; i-=1)
  {
    turret.write(i);
    //Serial.println(distance());
    delay(10);
  }
}

float find_far_assistant(long& result, long& max, long now_position)
{
  int temp = distance();
  if(max < temp)
  {
    max = temp;
    result = now_position;
  }
}

long avoid_max_turret_position()
{
  long result;
  long max = 0;
  for(long i=turret.read(); i>0; i-=1)
  {
    turret.write(i);
    find_far_assistant(result, max, i);
    delay(2);
  }
  for(long i=0; i<180; i+=1)
  {
    turret.write(i);
    find_far_assistant(result, max, i);
    delay(2);
  }
  for(long i=180; i == 90; i-=1)
  {
    turret.write(i);
    find_far_assistant(result, max, i);
    delay(2);
  }
  return max*1000 + result;
}

void avoid_walk(float s)
{
  while (true)
  {
    if(distance() <= s) break;
    walk();
  }
  long temp = avoid_max_turret_position();
  int pos = temp % 1000;
  int d = temp / 1000;
  Serial.print(pos);
  Serial.println(d);
  turret.write(90);
  while (true)
  {
    rotate(pos < 90);
    int temp = distance();
    Serial.println(temp);
    if(abs(temp - d) < 150) break;
  }
}














