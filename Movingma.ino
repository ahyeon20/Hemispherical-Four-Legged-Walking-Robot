

void update_currentjoint()
{
  Serial.println("updating");
  //실제 사용하는 각도값
  Joint.FR_1 = Joint.FR_1_current - *Joint.FR_1_angle; // 0
  Joint.FR_2 = Joint.FR_2_current - *Joint.FR_2_angle; //180
  Joint.FR_3 = Joint.FR_3_current - *Joint.FR_3_angle; //0

  Joint.BR_1 = Joint.BR_1_current - *Joint.BR_1_angle; //180
  Joint.BR_2 = Joint.BR_2_current - *Joint.BR_2_angle; //180
  Joint.BR_3 = Joint.BR_3_current + *Joint.BR_3_angle; //0

  Joint.FL_1 = Joint.FL_1_current - *Joint.FL_1_angle; //180
  Joint.FL_2 = Joint.FL_2_current + *Joint.FL_2_angle; //0
  Joint.FL_3 = Joint.FL_3_current + *Joint.FL_3_angle;

  Joint.BL_1 = Joint.BL_1_current + *Joint.BL_1_angle; //0
  Joint.BL_2 = Joint.BL_2_current + *Joint.BL_2_angle; //0
  Joint.BL_3 = Joint.BL_3_current + *Joint.BL_3_angle;

  Joint.FR_1_current = Joint.FR_1;
  Joint.FR_2_current = Joint.FR_2;
  Joint.FR_3_current = Joint.FR_3;

  Joint.BR_1_current = Joint.BR_1;
  Joint.BR_2_current = Joint.BR_2;
  Joint.BR_3_current = Joint.BR_3;

  Joint.FL_1_current = Joint.FL_1;
  Joint.FL_2_current = Joint.FL_2;
  Joint.FL_3_current = Joint.FL_3;

  Joint.BL_1_current = Joint.BL_1;
  Joint.BL_2_current = Joint.BL_2;
  Joint.BL_3_current = Joint.BL_3;
  return Joint;

}


float angle1, angle2, angle3;

void banown() {

  /*
    ServoBL1.startEaseToD(180, Millis);
    ServoBL2.startEaseToD(100, Millis);
    ServoBL3.startEaseToD(30, Millis);

    ServoFL1.startEaseToD(180, Millis);
    ServoFL2.startEaseToD(100, Millis);
    ServoFL3.startEaseToD(30, Millis);

    ServoFR1.startEaseToD(150, Millis);
    ServoFR2.startEaseToD(100, Millis);
    ServoFR3.startEaseToD(30, Millis);
  */
  delay(1000);

  Serial.print("end");
}


int post = 0;
int angle_90 = 1023;

int angle_20 = 227;
//30=341
int angle_30 = 341;
int angle_45 = 512;
int angle_12 = 136;
int angle_50 = 568;

/*
dxl.setGoalPosition(DXL_IDS[0], angle_90);
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[0], angle_90);
  dxl.setGoalPosition(DXL_IDS[1], angle_90 - angle_30);
  delay(500);

  
  dxl.setGoalPosition(DXL_IDS[0], angle_90 - angle_30);
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  delay(500);*/

void testforward(){
  Serial.println("f");

  dxl.setGoalPosition(DXL_IDS[2], angle_90);
  dxl.setGoalPosition(DXL_IDS[3], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[2], angle_90 - angle_30);
  dxl.setGoalPosition(DXL_IDS[3], angle_90);
  delay(500);


  dxl.setGoalPosition(DXL_IDS[0], angle_90);
  dxl.setGoalPosition(DXL_IDS[1], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[0], angle_90 - angle_30);
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[0], angle_90);
  dxl.setGoalPosition(DXL_IDS[1], angle_90); 
  dxl.setGoalPosition(DXL_IDS[2], angle_90); 
  dxl.setGoalPosition(DXL_IDS[3], angle_90); 
  
  dxl.setGoalPosition(DXL_IDS[4], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90); 
  dxl.setGoalPosition(DXL_IDS[6], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[7], angle_90);

  delay(500);
  dxl.setGoalPosition(DXL_IDS[4], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[4], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[6], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[7], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[6], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[7], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[0], angle_90 + angle_30);
  dxl.setGoalPosition(DXL_IDS[1], angle_90); 
  dxl.setGoalPosition(DXL_IDS[2], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[3], angle_90); 
  
  dxl.setGoalPosition(DXL_IDS[4], angle_90); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90); 
  dxl.setGoalPosition(DXL_IDS[6], angle_90); 
  dxl.setGoalPosition(DXL_IDS[7], angle_90);
  delay(500);
 
}

void testbackward(){
  Serial.println("b");
  
  dxl.setGoalPosition(DXL_IDS[2], angle_90);
  dxl.setGoalPosition(DXL_IDS[3], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[2], angle_90 + angle_30);
  dxl.setGoalPosition(DXL_IDS[3], angle_90);
  delay(500);


  dxl.setGoalPosition(DXL_IDS[0], angle_90);
  dxl.setGoalPosition(DXL_IDS[1], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[0], angle_90 + angle_30);
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[0], angle_90);
  dxl.setGoalPosition(DXL_IDS[1], angle_90); 
  dxl.setGoalPosition(DXL_IDS[2], angle_90); 
  dxl.setGoalPosition(DXL_IDS[3], angle_90); 
  
  dxl.setGoalPosition(DXL_IDS[4], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90); 
  dxl.setGoalPosition(DXL_IDS[6], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[7], angle_90);

  delay(500);
  dxl.setGoalPosition(DXL_IDS[4], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[4], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[6], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[7], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[6], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[7], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[0], angle_90 - angle_30);
  dxl.setGoalPosition(DXL_IDS[1], angle_90); 
  dxl.setGoalPosition(DXL_IDS[2], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[3], angle_90); 
  
  dxl.setGoalPosition(DXL_IDS[4], angle_90); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90); 
  dxl.setGoalPosition(DXL_IDS[6], angle_90); 
  dxl.setGoalPosition(DXL_IDS[7], angle_90);
  delay(500);
}
void testright(){

  Serial.println("r");
  dxl.setGoalPosition(DXL_IDS[4], angle_90);
  dxl.setGoalPosition(DXL_IDS[5], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[4], angle_90 - angle_30);
  dxl.setGoalPosition(DXL_IDS[5], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[2], angle_90);
  dxl.setGoalPosition(DXL_IDS[3], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[2], angle_90 - angle_30);
  dxl.setGoalPosition(DXL_IDS[3], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[2], angle_90);
  dxl.setGoalPosition(DXL_IDS[3], angle_90); 
  dxl.setGoalPosition(DXL_IDS[4], angle_90); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90); 
  
  dxl.setGoalPosition(DXL_IDS[6], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[7], angle_90); 
  dxl.setGoalPosition(DXL_IDS[0], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[1], angle_90);

  delay(500);
  dxl.setGoalPosition(DXL_IDS[6], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[7], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[6], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[7], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[0], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[1], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[0], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[2], angle_90 + angle_30);
  dxl.setGoalPosition(DXL_IDS[3], angle_90); 
  dxl.setGoalPosition(DXL_IDS[4], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90); 
  
  dxl.setGoalPosition(DXL_IDS[6], angle_90); 
  dxl.setGoalPosition(DXL_IDS[7], angle_90); 
  dxl.setGoalPosition(DXL_IDS[0], angle_90); 
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  delay(500);

}
void testleft(){
  Serial.println("l");
  dxl.setGoalPosition(DXL_IDS[0], angle_90);
  dxl.setGoalPosition(DXL_IDS[1], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[0], angle_90 - angle_30);
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[6], angle_90);
  dxl.setGoalPosition(DXL_IDS[7], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[6], angle_90 - angle_30);
  dxl.setGoalPosition(DXL_IDS[7], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[6], angle_90);
  dxl.setGoalPosition(DXL_IDS[7], angle_90); 
  dxl.setGoalPosition(DXL_IDS[0], angle_90); 
  dxl.setGoalPosition(DXL_IDS[1], angle_90); 
  
  dxl.setGoalPosition(DXL_IDS[2], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[3], angle_90); 
  dxl.setGoalPosition(DXL_IDS[4], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90);

  delay(500);
  dxl.setGoalPosition(DXL_IDS[2], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[3], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[2], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[3], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[4], angle_90 - angle_30); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90 - angle_30);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[4], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[6], angle_90 + angle_30);
  dxl.setGoalPosition(DXL_IDS[7], angle_90); 
  dxl.setGoalPosition(DXL_IDS[0], angle_90 + angle_30); 
  dxl.setGoalPosition(DXL_IDS[1], angle_90); 
  
  dxl.setGoalPosition(DXL_IDS[2], angle_90); 
  dxl.setGoalPosition(DXL_IDS[3], angle_90); 
  dxl.setGoalPosition(DXL_IDS[4], angle_90); 
  dxl.setGoalPosition(DXL_IDS[5], angle_90);
  delay(500);
}
void testcw(){
  Serial.println("cw");

  dxl.setGoalPosition(DXL_IDS[0], angle_90);
  dxl.setGoalPosition(DXL_IDS[1], angle_90 - angle_45);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[0], angle_90 - angle_30);
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[2], angle_90);
  dxl.setGoalPosition(DXL_IDS[3], angle_90 - angle_45);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[2], angle_90 - angle_30);
  dxl.setGoalPosition(DXL_IDS[3], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[4], angle_90);
  dxl.setGoalPosition(DXL_IDS[5], angle_90 - angle_45);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[4], angle_90 - angle_30);
  dxl.setGoalPosition(DXL_IDS[5], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[6], angle_90);
  dxl.setGoalPosition(DXL_IDS[7], angle_90 - angle_45);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[6], angle_90 - angle_30);
  dxl.setGoalPosition(DXL_IDS[7], angle_90);
  delay(500);

  
  dxl.setGoalPosition(DXL_IDS[0], angle_90);
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  dxl.setGoalPosition(DXL_IDS[2], angle_90);
  dxl.setGoalPosition(DXL_IDS[3], angle_90);
  dxl.setGoalPosition(DXL_IDS[4], angle_90);
  dxl.setGoalPosition(DXL_IDS[5], angle_90);
  dxl.setGoalPosition(DXL_IDS[6], angle_90);
  dxl.setGoalPosition(DXL_IDS[7], angle_90);
  delay(500);
  
}
void testccw(){
  //임시
  Serial.println("ccw");
  dxl.setGoalPosition(DXL_IDS[0], angle_90);
  dxl.setGoalPosition(DXL_IDS[1], angle_90 - angle_45);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[0], angle_90 + angle_30);
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[2], angle_90);
  dxl.setGoalPosition(DXL_IDS[3], angle_90 - angle_45);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[2], angle_90 + angle_30);
  dxl.setGoalPosition(DXL_IDS[3], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[4], angle_90);
  dxl.setGoalPosition(DXL_IDS[5], angle_90 - angle_45);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[4], angle_90 + angle_30);
  dxl.setGoalPosition(DXL_IDS[5], angle_90);
  delay(500);

  dxl.setGoalPosition(DXL_IDS[6], angle_90);
  dxl.setGoalPosition(DXL_IDS[7], angle_90 - angle_45);
  delay(500);
  dxl.setGoalPosition(DXL_IDS[6], angle_90 + angle_30);
  dxl.setGoalPosition(DXL_IDS[7], angle_90);
  delay(500);

  
  dxl.setGoalPosition(DXL_IDS[0], angle_90);
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  dxl.setGoalPosition(DXL_IDS[2], angle_90);
  dxl.setGoalPosition(DXL_IDS[3], angle_90);
  dxl.setGoalPosition(DXL_IDS[4], angle_90);
  dxl.setGoalPosition(DXL_IDS[5], angle_90);
  dxl.setGoalPosition(DXL_IDS[6], angle_90);
  dxl.setGoalPosition(DXL_IDS[7], angle_90);
  delay(500);
}
void testrollingforward(){
  Serial.println("rf");
  /*
  //슬레이브는 딜레이랑 작동 반대로?
  //fr나오고fb들어가고,fl나오고,fr들어가고
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  delay(500);
   */
    //u2d2
  dxl.setGoalPosition(DXL_IDS[0], angle_12 - angle_12);
  dxl.setGoalPosition(DXL_IDS[1], angle_50 + angle_12);
  dxl.setGoalPosition(DXL_IDS[6], angle_12);
  dxl.setGoalPosition(DXL_IDS[7], angle_50);
  

  dxl.setGoalPosition(DXL_IDS[2], angle_12 - angle_12);
  dxl.setGoalPosition(DXL_IDS[3], angle_50 + angle_12);
  dxl.setGoalPosition(DXL_IDS[0], angle_12);
  dxl.setGoalPosition(DXL_IDS[1], angle_50);


  dxl.setGoalPosition(DXL_IDS[4], angle_12 - angle_12);
  dxl.setGoalPosition(DXL_IDS[5], angle_50 + angle_12);
  dxl.setGoalPosition(DXL_IDS[2], angle_12);
  dxl.setGoalPosition(DXL_IDS[3], angle_50);


  dxl.setGoalPosition(DXL_IDS[6], angle_12 - angle_12);
  dxl.setGoalPosition(DXL_IDS[7], angle_50 + angle_12);
  dxl.setGoalPosition(DXL_IDS[4], angle_12);
  dxl.setGoalPosition(DXL_IDS[5], angle_50);
  delay(500);
  
  Serial.println("Sending command: Move to 1");
  Wire.beginTransmission(8); // 슬레이브 주소 8
  Wire.write(1); // 명령: 1을 전송 (모터를 0 위치로 이동)
  Wire.endTransmission();
  

  

  /*
  dxl.setGoalPosition(DXL_IDS[0], angle_12 - angle_12);
  dxl.setGoalPosition(DXL_IDS[1], angle_50 + angle_12);
  dxl.setGoalPosition(DXL_IDS[6], angle_12);
  dxl.setGoalPosition(DXL_IDS[7], angle_50);
  delay(300);
  
  Serial.println("Sending command: Move to 1");
  Wire.beginTransmission(8); // 슬레이브 주소 8
  Wire.write(1); // 명령: 1을 전송 (모터를 0 위치로 이동)
  Wire.endTransmission();
  
  delay(300);  // 2초 대기

  dxl.setGoalPosition(DXL_IDS[2], angle_12 - angle_12);
  dxl.setGoalPosition(DXL_IDS[3], angle_50 + angle_12);
  dxl.setGoalPosition(DXL_IDS[0], angle_12);
  dxl.setGoalPosition(DXL_IDS[1], angle_50);
  delay(300);
  
  Serial.println("Sending command: Move to 2");
  Wire.beginTransmission(8);
  Wire.write(2); // 명령: 2를 전송 (모터를 300 위치로 이동)
  Wire.endTransmission();
  
  delay(300);  // 2초 대기

  dxl.setGoalPosition(DXL_IDS[4], angle_12 - angle_12);
  dxl.setGoalPosition(DXL_IDS[5], angle_50 + angle_12);
  dxl.setGoalPosition(DXL_IDS[2], angle_12);
  dxl.setGoalPosition(DXL_IDS[3], angle_50);
  delay(300);
  
  Serial.println("Sending command: Move to 3");
  Wire.beginTransmission(8);
  Wire.write(3); // 명령: 2를 전송 (모터를 300 위치로 이동)
  Wire.endTransmission();
  
  delay(300);  // 2초 대기

  dxl.setGoalPosition(DXL_IDS[6], angle_12 - angle_12);
  dxl.setGoalPosition(DXL_IDS[7], angle_50 + angle_12);
  dxl.setGoalPosition(DXL_IDS[4], angle_12);
  dxl.setGoalPosition(DXL_IDS[5], angle_50);
  delay(300);
  
  Serial.println("Sending command: Move to 4");
  Wire.beginTransmission(8);
  Wire.write(4); // 명령: 2를 전송 (모터를 300 위치로 이동)
  Wire.endTransmission();
   */

}
void testrollingback(){
  Serial.println("rb");
    //u2d2
  
  Serial.println("Sending command: Move to 5");
  Wire.beginTransmission(8); // 슬레이브 주소 8
  Wire.write(5); // 명령: 1을 전송 (모터를 0 위치로 이동)
  Wire.endTransmission();
  
  delay(500);  // 2초 대기

  dxl.setGoalPosition(DXL_IDS[6], angle_12 - angle_12);
  dxl.setGoalPosition(DXL_IDS[7], angle_50 - angle_12);
  dxl.setGoalPosition(DXL_IDS[4], angle_12);
  dxl.setGoalPosition(DXL_IDS[5], angle_50);
  
  dxl.setGoalPosition(DXL_IDS[4], angle_12 - angle_12);
  dxl.setGoalPosition(DXL_IDS[5], angle_50 - angle_12);
  dxl.setGoalPosition(DXL_IDS[2], angle_12);
  dxl.setGoalPosition(DXL_IDS[3], angle_50);
  
  dxl.setGoalPosition(DXL_IDS[2], angle_12 - angle_12);
  dxl.setGoalPosition(DXL_IDS[3], angle_50 - angle_12);
  dxl.setGoalPosition(DXL_IDS[0], angle_12);
  dxl.setGoalPosition(DXL_IDS[1], angle_50);

  dxl.setGoalPosition(DXL_IDS[0], angle_12 - angle_12);
  dxl.setGoalPosition(DXL_IDS[1], angle_50 - angle_12);
  dxl.setGoalPosition(DXL_IDS[6], angle_12);
  dxl.setGoalPosition(DXL_IDS[7], angle_50);

}
void testcombine() {
  Serial.println("com");
  //u2d2로 임의 결합상태일때 각도 확인
  dxl.setGoalPosition(DXL_IDS[0], 135);
  dxl.setGoalPosition(DXL_IDS[2], 162);
  dxl.setGoalPosition(DXL_IDS[4], 174);
  dxl.setGoalPosition(DXL_IDS[6], 34);
  
  dxl.setGoalPosition(DXL_IDS[1], 262);
  dxl.setGoalPosition(DXL_IDS[3], 462);
  dxl.setGoalPosition(DXL_IDS[5], 462);
  dxl.setGoalPosition(DXL_IDS[7], 322);

  
  //가운데모터
  myservo.write(60);
  // 서보 모터를 pos 각도로 회전
}
void standard(){
  //구형에서 바로 걷기하면 간섭날거같아서 기본형태로 돌아가는 코드 추가함
  dxl.setGoalPosition(DXL_IDS[1], angle_90);
  dxl.setGoalPosition(DXL_IDS[3], angle_90);
  dxl.setGoalPosition(DXL_IDS[5], angle_90);
  dxl.setGoalPosition(DXL_IDS[7], angle_90);

  dxl.setGoalPosition(DXL_IDS[0], angle_90);
  dxl.setGoalPosition(DXL_IDS[2], angle_90);
  dxl.setGoalPosition(DXL_IDS[4], angle_90);
  dxl.setGoalPosition(DXL_IDS[6], angle_90);
  
  //가운데 모터
  myservo.write(120);
}

/*
void forward()
{
  moveLeg("BR", 0, -50, 20);
  moveLeg("BR", 30, -20, -20);
  post = 1;
  while (post != 1) {}
  delay(100);
  moveLeg("FR", 0, -50, 20);
  moveLeg("FR", 30, -20, -20);
  post = 2;
  while (post != 2) {}
  delay(100);
  moveLeg("FL", 30, 80, -20);
  moveLeg("BL", 30, 80, -20);
  moveLeg("BR", 0, -50, -20);
  moveLeg("FR", 0, -50, -20);
  post = 3;
  while (post != 3) {}
  delay(100);
  moveLeg("BL", 0, 50, 20);
  moveLeg("BL", -30, 20, -20);
  post = 4;
  while (post != 4) {}
  delay(100);
  moveLeg("FL", 0, 50, 20);
  moveLeg("FL", -30, 20, -20);
  post = 5;
  while (post != 5) {}
  delay(100);
  moveLeg("FL", 0, 50, -20);
  moveLeg("BL", 0, 50, -20);
  moveLeg("BR", -30, -80, -20);
  moveLeg("FR", -30, -80, -20);
  post = 6;
  while (post != 6) {}
  delay(100);
}

void backward()
{

  moveLeg("FL", 30, 80, 20);
  moveLeg("BL", -30, 20, 20);
  moveLeg("BR", 0, -50, -20);
  moveLeg("FR", 0, -50, 20);

  delay(100);
  moveLeg("BL", 0, 50, -20);

  moveLeg("BL", 30, 80, 20);


  moveLeg("FL", 0, 50, 20);
  moveLeg("BL", 0, 50, 20);
  moveLeg("BR", 30, -20, -20);
  moveLeg("FR", 30, -20, 20);

  delay(100);
  moveLeg("FR", 0, -50, 60);


  moveLeg("FR", -30, -80, 20);


  delay(100);
  moveLeg("BR", 0, -50, -60);


  moveLeg("BR", -30, -80, -20);


  delay(100);
  moveLeg("FL", -30, 20, 20);
  moveLeg("BL", -30, 20, 20);
  moveLeg("BR", 0, -50, -20);
  moveLeg("FR", 0, -50, 20);

  delay(100);
  moveLeg("FL", 0, 50, -20);


  moveLeg("FL", 30, 80, 20);


}

void left() {
  moveLeg("BR", 0, -50, -20);

  moveLeg("FL", -20, 30, 20);
  moveLeg("BL", 0, 50, 20);

  moveLeg("FR", 20, -30, 20);


  delay(100);
  moveLeg("FL", 0, 50, -20);


  moveLeg("FL", 20, 70, 20);

  delay(100);
  moveLeg("FL", 0, 50, 20);
  moveLeg("BL", 20, 70, 20);
  moveLeg("BR", 20, -30, -20);
  moveLeg("FR", 0, -50, 20);

  delay(100);
  moveLeg("BR", 0, -50, -60);



  moveLeg("BR", -20, -70, -20);


  delay(100);
  moveLeg("BL", 0, 50, -20);



  moveLeg("BL", -20, 30, 20);


  delay(100);

  moveLeg("FL", -20, 30, 20);
  moveLeg("BL", 0, 50, 20);
  moveLeg("BR", 0, -50, -20);
  moveLeg("FR", -20, -70, 20);

  delay(100);
  moveLeg("FR", 0, -50, 60);

  moveLeg("FR", 20, -30, 20);


}

void right()
{
  moveLeg("BR", -20, -70, -20);

  moveLeg("FL", 0, 50, 20);
  moveLeg("BL", 20, 70, 20);

  moveLeg("FR", 0, -50, 20);


  delay(100);
  moveLeg("BR", 0, -50, -60);


  moveLeg("BR", 20, -30, -20);

  delay(100);
  moveLeg("FL", 20, 70, 20);
  moveLeg("BL", 0, 50, 20);
  moveLeg("BR", 0, -50, -20);
  moveLeg("FR", 20, -30, 20);

  delay(100);
  moveLeg("FL", 0, 50, -20);




  moveLeg("FL", -20, 30, 20);


  delay(100);
  moveLeg("FR", 0, -50, 60);




  moveLeg("FR", -20, -70, 20);


  delay(100);

  moveLeg("FL", 0, 50, 20);
  moveLeg("BL", -20, 30, 20);
  moveLeg("BR", -20, -70, -20);
  moveLeg("FR", 0, -50, 20);

  delay(100);
  moveLeg("BL", 0, 50, -20);

  moveLeg("BL", 20, 70, 20);


}

void cw() {
  moveBody(105, 75, 135, 135);
  //fr,br,bl,fl
  moveLeg("FL", -10, -60, 60);
  delay(500);
  moveLeg("FL", 0, 50, 20);
  delay(200);
  moveLeg("BL", -10, -60, 60);
  delay(200);
  moveLeg("BL", 0, 50, 20);
  delay(200);
  moveLeg("BR", -10, -60, -60);
  delay(200);
  moveLeg("BR", 0, -50, -20);
  delay(200);
  moveLeg("FR", -10, -60, 60);
  delay(200);
  moveLeg("FR", 0, -50, 20);
  delay(200);
}
void ccw() {
  moveBody(75, 45, 105, 105);

  moveLeg("FL", 10, 60, 60);
  delay(200);
  moveLeg("FL", 0, 50, 20);
  delay(200);

  moveLeg("BL", 10, 60, 60);
  delay(200);
  moveLeg("BL", 0, 50, 20);
  delay(200);

  moveLeg("BR", 10, 60, -60);
  delay(200);
  moveLeg("BR", 0, -50, -20);
  delay(200);

  moveLeg("FR", 10, 60, 60);
  delay(200);
  moveLeg("FR", 0, -50, 20);
  delay(200);
}

void movestop() {
  moveLeg("FL", 0, 50, 20);
  delay(200);
  moveLeg("BL", 0, 50, 20);
  delay(200);
  moveLeg("FR", 0, -50, 20);
  delay(200);
  moveLeg("BR", 0, -50, -20);
  delay(200);
}
void ball() {
  moveLeg("FL", 0, 0, 20);
  delay(200);
  moveLeg("BL", 0, 0, 20);
  delay(200);
  moveLeg("FR", 0, 0, 20);
  delay(200);
  moveLeg("BR", 0, 0, -20);
  delay(200);
}
int leg_up = 15;



void moveLeg(String a, float b, float c, float d )
{
  int leg;
  IKsolver(b, c, d);
  float angle1 = the1;
  float angle2 = the2;
  float angle3 = the3;

  if (a == "BR")
  {
    Serial.println("BR");
    //오른쪽 뒷다리

    Serial.println("a");
    //각 조인트에 각도 입력

    Joint.BR_1_angle = &angle1;
    Joint.BR_2_angle = &angle2;
    Joint.BR_3_angle = &angle3;
    //update_currentjoint();


    // 다리를 이동시키기 전 다리를 들어올리는 문구


    // 1번 조인트를 움직여 다리를 이동시키는 문구

    Serial.print("Millis:");
    Serial.println(Millis);
    *Joint.BR_1_angle = abs(*Joint.BR_1_angle - 0);
    *Joint.BR_2_angle = abs(*Joint.BR_2_angle + 0);
    *Joint.BR_3_angle = abs(*Joint.BR_3_angle + 0);
    dxl.setGoalPosition(DXL_IDS[2], *Joint.BR_1_angle);
    dxl.setGoalPosition(DXL_IDS[3], *Joint.BR_2_angle);


    Serial.println("movLeg done");
    Serial.println(*Joint.BR_1_angle);
    Serial.println(*Joint.BR_2_angle);
    Serial.println(*Joint.BR_3_angle);
    Serial.println("---------------");

  }
  else if (a == "FR")
  {
    Serial.println("FR");
    //오른쪽 앞다리
    //각 조인트에 각도 입력
    Joint.FR_1_angle = &angle1;
    Joint.FR_2_angle = &angle2;
    Joint.FR_3_angle = &angle3;
    //update_currentjoint();

    // 1번 조인트를 움직여 다리를 이동시키는 문구



    // 1번 조인트를 움직여 다리를 이동시키는 문구
    *Joint.FR_1_angle = abs(*Joint.FR_1_angle);
    *Joint.FR_2_angle = abs(*Joint.FR_2_angle + 0);
    dxl.setGoalPosition(DXL_IDS[1], *Joint.FR_1_angle); // Motor 1 Axis 1
    dxl.setGoalPosition(DXL_IDS[0], *Joint.FR_2_angle);
    *Joint.FR_3_angle = abs(*Joint.FR_3_angle + 0);


    Serial.println("movLeg donefr");
    Serial.println(*Joint.FR_1_angle);
    Serial.println(*Joint.FR_2_angle);
    Serial.println(*Joint.FR_3_angle);
    Serial.println("---------------");

  }
  else if (a == "BL")
  {
    Serial.println("BL");
    //왼쪽 뒷다리
    //각 조인트에 각도 입력
    Joint.BL_1_angle = &angle1;
    Joint.BL_2_angle = &angle2;
    Joint.BL_3_angle = &angle3;
    //update_currentjoint();

    // 다리를 이동시키기 전 다리를 들어올리는 문구
    *Joint.BL_1_angle = abs(*Joint.BL_1_angle + 0);
    *Joint.BL_2_angle = abs(*Joint.BL_2_angle - 0);
    *Joint.BL_3_angle = abs(*Joint.BL_3_angle + 0);

    // 1번 조인트를 움직여 다리를 이동시키는 문구


    dxl.setGoalPosition(DXL_IDS[4], *Joint.BL_1_angle); // Motor 3 Axis 1
    dxl.setGoalPosition(DXL_IDS[5], *Joint.BL_2_angle);


    Serial.println("movLeg done");
    Serial.println(*Joint.BL_1_angle);
    Serial.println(*Joint.BL_2_angle);
    Serial.println(*Joint.BL_3_angle);
    Serial.println("---------------");

  }
  else if (a == "FL")
  {
    Serial.println("FL");
    //왼쪽 앞다리
    //각 조인트에 각도 입력
    Joint.FL_1_angle = &angle1;
    Joint.FL_2_angle = &angle2;
    Joint.FL_3_angle = &angle3;
    //update_currentjoint();
    // 다리를 이동시키기 전 다리를 들어올리는 문구

    *Joint.FL_1_angle = abs(*Joint.FL_1_angle + 30);
    // 1번 조인트를 움직여 다리를 이동시키는 문구
    dxl.setGoalPosition(DXL_IDS[6], *Joint.FL_1_angle);
    *Joint.FL_2_angle = abs(*Joint.FL_2_angle - 30);
    dxl.setGoalPosition(DXL_IDS[7], *Joint.FL_2_angle);
    *Joint.FL_3_angle = abs(*Joint.FL_3_angle + 10);


    Serial.println("movLeg done");
    Serial.println(*Joint.FL_1_angle);
    Serial.println(*Joint.FL_2_angle);
    Serial.println(*Joint.FL_3_angle);
    Serial.println("---------------");

  }

  return Joint;
}

void moveBody(float a, float b, float c, float d)
{
  Joint.FR_1_angle = &a;
  Joint.BR_1_angle = &b;
  Joint.FL_1_angle = &d;
  Joint.BL_1_angle = &c;

  dxl.setGoalPosition(DXL_IDS[0], *Joint.FR_1_angle); // Motor 1 Axis 1
  dxl.setGoalPosition(DXL_IDS[2], *Joint.BR_1_angle); // Motor 2 Axis 1
  dxl.setGoalPosition(DXL_IDS[4], *Joint.BL_1_angle); // Motor 3 Axis 1
  dxl.setGoalPosition(DXL_IDS[6], *Joint.FL_1_angle); // Motor 4 Axis 1

  Serial.println("Joint.BL_1_angle:");
  Serial.println(*Joint.BL_1_angle);

}

void moveBody2(float a, float b, float c, float d)
{
  Joint.FR_2_angle = &a;
  Joint.BR_2_angle = &b;
  Joint.FL_2_angle = &d;
  Joint.BL_2_angle = &c;

  dxl.setGoalPosition(DXL_IDS[1], *Joint.FR_2_angle); // Motor 1 Axis 2
  dxl.setGoalPosition(DXL_IDS[3], *Joint.BR_2_angle); // Motor 2 Axis 2
  dxl.setGoalPosition(DXL_IDS[5], *Joint.BL_2_angle); // Motor 3 Axis 2
  dxl.setGoalPosition(DXL_IDS[7], *Joint.FL_2_angle); // Motor 4 Axis 2

  Serial.println("Joint.BL_2_angle:");
  Serial.println(*Joint.BL_2_angle);

}

void moveBody3(float a, float b, float c, float d)
{
  Joint.FR_3_angle = &a;
  Joint.BR_3_angle = &b;
  Joint.FL_3_angle = &d;
  Joint.BL_3_angle = &c;


  Serial.println("Joint.BL_3_angle:");
  Serial.println(*Joint.BL_3_angle);

}
*/
