//실행 방법 ㅣ 시리얼 모니터에 각각의 모드에 해당하는 입력 넣기

//라이브러리
#include <Parts_base.h>
//초음파
Ultrasonic hc06;

//모터제어
Servo_vector spider{8};
const int spider_pin[8] = {4,5,6,7,8,9,10,11};

//속도  마이크로초
const int speed = 1500;

// limit[위치][모드] = {{앞쪽/서는방향한계, 뒤쪽/눕는방향한계}...}
const int limit[8][2] = { {0, 155}, {30, 180}, {150, 0}, {180, 30},
	                        {0 , 90}, {180, 90}, {0, 90}, {180, 90} };

//각도배열
//[몸통 좌상단, 몸통 좌하단, 몸통 우하단, 몸통 우상단,
// 발 좌상단, 발 좌하단, 발 우하단, 발 우상단]

void setup()
{
  //거미 초기화
  Serial.begin(9600);
  init_spider();
  hc06.init(12, 13);
  randomSeed(analogRead(0));
}

void init_spider()
{
  //핀 연결
  spider.attach(spider_pin); 
  init_position();
}

void init_position()
{
  //초기 상태
  int init[8] = {(limit[0][0]+limit[0][1])/2,  (limit[1][0]+limit[1][1])/2,  (limit[2][0]+limit[2][1])/2,  (limit[3][0]+limit[3][1])/2,
                 (2*limit[4][0]+limit[4][1])/3,  (2*limit[5][0]+limit[5][1])/3,  (2*limit[6][0]+limit[6][1])/3,  (2*limit[7][0]+limit[7][1])/3 };
  spider.move_arr(init, speed);
}

void loop()
{
  //시리얼 모니터에 값 입력해 구동
  char received = receive_char('?');
  if      (received == 'w') walk();         //걷기
  else if (received == 's') squat();        //스쿼트
  else if (received == 'i') init_position();//초기상태
  else if (received == 'c') rotate(0); // 반시계
  else if (received == 'z') rotate(1); // 시계
  else if (received == 'h') hello(); // 인사
  else if (received == 'm') swim(); // 수영
  else if (received == 't') tank_walk(230);  //거리가 인수 이하면 인사
  else if (received == 'v') avoid_walk(230,200); // 첫 인자 이하거리면, 첫인자+두번째인자 거리 될때까지 회전(방향 랜덤)
  else if (received == '1') install(); //90도 정렬
  
  //거리 표시
  Serial.print("Distance (mm): ");
  Serial.println(hc06.distance());
}

//모든 함수 공통
//각도 배열 설정
//move_arr로 실행

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
                 limit[4][1],  (limit[5][0] + limit[5][1])/2,   limit[6][1],  (limit[7][0] + limit[7][1])/2 };
  spider.move_arr(posi1, speed);

  

  int posi2[8] = {90,  spider[1].read(),  90,  spider[3].read(),
                  limit[4][0],  spider[5].read(),  limit[6][0],  spider[7].read() };
  spider.move_arr(posi2, speed);

  

  int posi3[8]={ spider[0].read(),  limit[1][0],  spider[2].read(), limit[3][0],
                (limit[4][0] + limit[4][1])/2,   limit[5][1],  (limit[6][0] + limit[6][1])/2, limit[7][1] };
  spider.move_arr(posi3, speed);

  

  int posi4[8] = {spider[0].read(),  (2*limit[1][0]+limit[1][1])/3,  spider[2].read(),  (2*limit[3][0]+limit[3][1])/3,
                  spider[4].read(),  limit[5][0],  spider[6].read(),  limit[7][0] };
  spider.move_arr(posi4, speed);

  

  init_position();
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

  init_position();
}

//인사
void hello()
{
  init_position();
  spider.move_one(4, 135, speed);
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

//수영
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


//벽만나면 인사
void tank_walk(float s)
{
  while (true)
  {
    if(hc06.distance() <= s)
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

//벽만나면 일정거리 이상일때까지 회전
void avoid_walk(float thre, float resi)
{
  while (true)
  {
    if(hc06.distance() <= thre) break;
    walk();
  }
  
  int mode = random(0, 2);

  while (true)
  {
    rotate(mode);
    if (hc06.distance() >= thre + resi)
    {
      break;
    }
  }
}















