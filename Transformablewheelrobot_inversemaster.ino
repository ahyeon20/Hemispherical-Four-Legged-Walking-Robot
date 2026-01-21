//보행모드 제어 코드
#include <Wire.h>
#include <Arduino.h>
#include <Servo.h>

#define ENABLE_EASE_CUBIC //서보 동작에 부드러운 움직임 적용
#define DISABLE_COMPLEX_FUNCTIONS

#include "ServoEasing.hpp"
#include "RobotConfigurationmaster.h"
#include <DynamixelShield.h>

#define DEBUG_SERIAL Serial2  // 하드웨어 시리얼 사용

//2축 모터 아이디; 다리1,2번 조인트임.
const uint8_t DXL_IDS[] = {1, 2, 3, 4, 5, 6, 7, 8};
const float DXL_PROTOCOL_VERSION = 2.0;
DynamixelShield dxl;
Servo myservo;

#define recvCH1 38  // THROTTLE(오른쪽 스틱 상하) 연결 
#define recvCH2 40  // AILE(오른쪽 스틱 좌우) 연결
#define recvCH3 42  // ELEV(왼쪽 스틱 상하) 연결
#define recvCH4 44  // RUDO(왼쪽 스틱 좌우) 연결 
#define recvCH5 46  // SA switch와 연결
#define recvCH6 48 // SD switch와 연결

//수신기의 6개 채널 변수선언
long valueCH1;
long valueCH2;
long valueCH3;
long valueCH4;
long valueCH5;
long valueCH6;

//캘리브레이션 변수
long maxValue = 0;
long minValue = 0;      
long sensorMin = 20000;     
long sensorMax = 0;       
long time_s;

long valueCH_1; 
long valueCH2_L;
long valueCH2_R;
long valueCH3_B;
long valueCH3_F;
long valueCH_4;
long valueCH_5;
long valueCH_6;

long ch1 = 1497;
long ch2 = 1493;
long ch3 = 1860;
long ch4 = 1493;
long ch5 = 1497;
long ch6 = 1497;

volatile byte receivedData = 0;  // 수신한 데이터를 저장하는 변수
bool newDataAvailable = false;  // 새로운 데이터가 들어왔는지 확인하는 플래그

int pos = 0;
String a, str1, str2, str3;
int val0 = 0;
int length, first, second, str1length;
float val1, val2, val3;


using namespace ControlTableItem;



const int Millis = 300;//서보모터가 목표 각도까지 움직이는 게 걸리는 시간



typedef struct quadrobot { //각 조인트 값 정의

  float FR_1, FR_2, FR_3; //오른쪽 앞다리(FR) 관절
  float BR_1, BR_2, BR_3; //오른쪽 뒷다리(BR)
  float BL_1, BL_2, BL_3; //왼쪽 뒷다리 (BL)
  float FL_1, FL_2, FL_3; //왼쪽 앞다리 (FL)


  float FR_1_initial = 1023; // 0 50
  float FR_2_initial = 1023; //180 20
  float FR_3_initial = 90; //0 115

  float BR_1_initial = 1023; //180
  float BR_2_initial = 1023; //180
  float BR_3_initial = 90; //0

  float BL_1_initial = 1023; //0
  float BL_2_initial = 1023; //0
  float BL_3_initial = 90;

  float FL_1_initial = 1023; //180
  float FL_2_initial = 1023; //0
  float FL_3_initial = 90;
  //현재 조인트값 정의
  float FR_1_current = FR_1_initial;
  float FR_2_current = FR_2_initial;
  float FR_3_current = FR_3_initial;

  float BR_1_current = BR_1_initial;
  float BR_2_current = BR_2_initial;
  float BR_3_current = BR_3_initial;

  float BL_1_current = BL_1_initial;
  float BL_2_current = BL_2_initial;
  float BL_3_current = BL_3_initial;

  float FL_1_current = FL_1_initial;
  float FL_2_current = FL_2_initial;
  float FL_3_current = FL_3_initial;

  //추가될 값 정의
  float *FR_1_angle = 0;
  float *FR_2_angle = 0;
  float *FR_3_angle = 0;

  float *BR_1_angle = 0;
  float *BR_2_angle = 0;
  float *BR_3_angle = 0;

  float *BL_1_angle = 0;
  float *BL_2_angle = 0;
  float *BL_3_angle = 0;

  float *FL_1_angle = 0;
  float *FL_2_angle = 0;
  float *FL_3_angle = 0;
  // 0으로 변환

  // 스텝간 움직인 수를 체크하기 위함
  int count = 0;

  //전체적인 모드에 관한 조인트 각도 선언
  // char walking[13] = {'0', '180', '0', '180', '180', '0', '180', '0', '0', '0', '0', '0'};


} quadrobot;

quadrobot Joint;

void setup() {//지금 모터드라이버 꽃는 부분을 3개씩 묶어놔서 (0,1,2) (4,5,6) (8,9,10) (12,13,14)로 나눠져있으니 참고
  Serial.begin(57600);     // 컴퓨터와의 시리얼 통신
  Wire.begin();              // I2C 슬레이브 초기화, 주소 1

  DEBUG_SERIAL.begin(57600);

  dxl.begin(57600); //Dynamixel 모터통신

  myservo.attach(26);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  setSpeedForAllServos(100);


  for (int i = 0; i < 8; i++) {
    dxl.ping(DXL_IDS[i]);
    dxl.torqueOff(DXL_IDS[i]);
    dxl.setOperatingMode(DXL_IDS[i], OP_POSITION);
    dxl.torqueOn(DXL_IDS[i]);
  }


  dxl.setGoalPosition(DXL_IDS[0], Joint.FR_1_initial);
  dxl.setGoalPosition(DXL_IDS[1], Joint.FR_2_initial);
  dxl.setGoalPosition(DXL_IDS[2], Joint.BR_1_initial);
  dxl.setGoalPosition(DXL_IDS[3], Joint.BR_2_initial);
  dxl.setGoalPosition(DXL_IDS[4], Joint.BL_1_initial);
  dxl.setGoalPosition(DXL_IDS[5], Joint.BL_2_initial);
  dxl.setGoalPosition(DXL_IDS[6], Joint.FL_1_initial);
  dxl.setGoalPosition(DXL_IDS[7], Joint.FL_2_initial);
  delay(1000);

  // 서보 속도 설정 (단위: 도/초)
  setSpeedForAllServos(100);
  // 필요에 따라 값을 조정하세요

  float zero = 0;// 변수주소로 넣어줘야 잘 구동됨.
  Joint.FR_1_angle = &zero;
  Joint.FR_2_angle = &zero;
  Joint.FR_3_angle = &zero;

  Joint.BR_1_angle = &zero;
  Joint.BR_2_angle = &zero;
  Joint.BR_3_angle = &zero;

  Joint.FL_1_angle = &zero;
  Joint.FL_2_angle = &zero;
  Joint.FL_3_angle = &zero;

  Joint.BL_1_angle = &zero;
  Joint.BL_2_angle = &zero;
  Joint.BL_3_angle = &zero;

  Serial.println("start");
  update_currentjoint();
  

  pinMode(recvCH1, INPUT);
  pinMode(recvCH2, INPUT);
  pinMode(recvCH3, INPUT);
  pinMode(recvCH4, INPUT);
  pinMode(recvCH5, INPUT);
  pinMode(recvCH6, INPUT);

}

//키보드조작
/*
  void executeCommand(char command) {
  switch (command) {
    case 'w':
      forward();
      Serial.println("Moving forward");
      break;
    case 's':
      backward();
      break;
    case 'a':
      left();
      break;
    case 'd':
      right();
      break;
    case 'x':
      movestop();
      break;
    case 'r':
      e2leggedstand();
      break;
    case 'b':
      banown();
      break;

  }
  }
*/



void loop() {

  float delta1 = the1 - Last_the1;
  float delta2 = the2 - Last_the2;
  float delta3 = the3 - Last_the3;
  


  //delay(100);
  noInterrupts();

  // HIGH일 때 duration의 길이를 정수값으로 변환
  valueCH1 = pulseIn(recvCH1, HIGH); // 1090~1880까지 연속적으로 변화
  valueCH2 = pulseIn(recvCH2, HIGH); // 1090~1880까지 연속적으로 변화
  valueCH3 = pulseIn(recvCH3, HIGH); // 1090~1880까지 연속적으로 변화
  valueCH4 = pulseIn(recvCH4, HIGH); // 1090~1880까지 연속적으로 변화
  valueCH5 = pulseIn(recvCH5, HIGH); // 1090, 1880 두가지 값으로 변화
  valueCH6 = pulseIn(recvCH6, HIGH); // 1090, 1880 두가지 값으로 변화



  Serial.print("CH1: "); Serial.print(valueCH1); Serial.print("\t");
  Serial.print("CH2: "); Serial.print(valueCH2); Serial.print("\t");
  Serial.print("CH3: "); Serial.print(valueCH3); Serial.print("\t");
  Serial.print("CH4: "); Serial.print(valueCH4); Serial.print("\t");
  Serial.print("CH5: "); Serial.print(valueCH5); Serial.print("\t");
  Serial.print("CH6: "); Serial.println(valueCH6);
  interrupts();

  if ((valueCH5 > 1600) && (valueCH6 > 1600)) {
    // ELEV로 전진/후진 조절
    if (valueCH1 > 1600) {

      testcombine();
    }
    else if(valueCH1 < 1300){
      standard();
    }

  }
  if ((valueCH5 > 1600) && (valueCH6 < 1300)) {
    // ELEV로 전진/후진 조절
    if (valueCH1 > 1600) {

      testforward();
    }

    else if (valueCH1 < 1300) {
      testbackward();

    }

    // AILE로 좌우 방향 조절
    if (valueCH2 > 1600) {
      testleft();
    }
    else if (valueCH2 < 1300) {
      testright();
    }

  }

  if ((valueCH5 < 1300) && (valueCH6 > 1600)) {
    if (valueCH1 > 1600) {

      testcw();
    }

    else if (valueCH1 < 1300) {
      testccw();

    }

  }

  if ((valueCH5 < 1300) && (valueCH6 < 1300)) {
    // ELEV로 전진/후진 조절
    if (valueCH1 > 1600) {

      testrollingforward();
    }

    else if (valueCH1 < 1300) {
      testrollingback();

    }



  }
  Last_the1 = the1;
  Last_the2 = the2;
  Last_the3 = the3;
}
