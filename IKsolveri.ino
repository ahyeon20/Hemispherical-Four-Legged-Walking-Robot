
void IKsolver(float px, float py, float pz)
{
    theta1 = 0;
    theta2 = 0;

      // 관절1 각도 계산 (xy 평면에서의 각도)
    theta1 = atan2(py, px); 
  
    // xy 평면에서의 거리 (a1을 제외한 거리)
    float r = sqrt(pow(px, 2) + pow(py, 2)) - a1;
  
    // Pz와 r을 이용해 theta2 계산
    theta2 = atan2(pz, r);  // Pz를 r로 나누어 각도를 계산
  if (theta1 < 0){
    theta1 = abs(theta1);
  }
  if (theta2 < 0){
    theta2 = abs(theta2);
  }

    
  the1 = (theta1 * toDeg) * 4095 / 360;
  the2 = (theta2 * toDeg) * 4095 / 360;


  Serial.print("the1 =");
  Serial.print(the1);
  Serial.print("the2 =");
  Serial.print(the2);

}
