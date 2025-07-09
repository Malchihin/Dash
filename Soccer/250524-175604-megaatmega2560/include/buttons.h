#pragma once

#include "Arduino.h"
#include "camera.h"
#include "config.h"
#include "gyro_and_angle.h"
#include "tssop.h"
#include "gyro_and_angle.h"

void change_goal()
{
  if (digitalRead(BUT_ENTER) == 0)
  {
    kick();
    if (our_goal == 'Y')
    {
      our_goal = 'B';
      digitalWrite(LED_YELLOW, 0);
      digitalWrite(LED_BLUE, 1);
    }
    else
    {
      our_goal = 'Y';
      digitalWrite(LED_BLUE, 0);
      digitalWrite(LED_YELLOW, 1);
    }
    delay(500);
  }
  if (our_goal == 'Y')
  {
    our_distance = yellow_distance;
    our_local_angle = yellow_local_angle;
    enemy_distance = blue_distance;
    enemy_local_angle = blue_local_angle;
    digitalWrite(LED_YELLOW, 1);
  }
  else
  {
    enemy_distance = yellow_distance;
    enemy_local_angle = yellow_local_angle;
    our_distance = blue_distance;
    our_local_angle = blue_local_angle;
    digitalWrite(LED_BLUE, 1);
  }
}


void but_motors ()
{
  static bool prev_button = 0;
  
  const bool button = !digitalRead(BUT_UP);

  const bool forward_front = prev_button == 0 && button == 1;
  const bool back_front = prev_button == 1 && button == 0;
  
  if(back_front){
    stop_motor = !stop_motor;
  }
 
  prev_button = button;    
}

void reset_imu()
{
  if (digitalRead(BUT_DOWN) == 0)

  {
null_angle = gyro_angle;
//Serial.println(null_angle);
  }
  // Serial.println(null_angle);
}
