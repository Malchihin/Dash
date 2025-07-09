#pragma once

#include "Arduino.h"
#include "global.h"

int16_t lead_to_degree_borders(int angle)
{
  if (angle > 180) angle -= 360;
  else if (angle < -180) angle += 360;
  return angle;

}

int16_t gyro_data() {
  static int16_t angle = 0;

  if (Serial1.available() >= 2)
  {
    //// // Serial.println('+');
    byte prev_sense = Serial1.read();
    
    /*Serial.print(prev_sense);
    Serial.print(" ");
     Serial.println(sense);*/
    if (prev_sense == 255)
    {
      byte sense = Serial1.read();
      angle = lead_to_degree_borders((byte)sense * 2);
    }
  }
//Serial.println(angle);
  return angle;
}

void turn(int num)
{
  motor1(num);
  motor2(num);
  motor3(num);
  motor4(-num);
}

int turn_angle (int angle) {
  //gyro_data();
  float err_angle = angle - robot_local_angle;
  int u = err_angle * kP + (err_angle - err_old_angle)*kD + err_i_angle;
  /*// Serial.print(err_angle);
  // Serial.print (' ');
  // // Serial.println(u);*/
  err_old_angle = err_angle;
  err_i_angle += err_angle*kI;
  if (u > 60) u = 60; 
  
  return u;
}

void calibration_imu()
{
  for (; (millis() - timer) < 10000;);
  // digitalWrite(LED_CALIBRATION, 1);
}
