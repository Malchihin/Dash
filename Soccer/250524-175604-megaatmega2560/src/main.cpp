#include "motors.h"
#include "buttons.h"
#include "camera.h"
#include "config.h"
#include "gyro_and_angle.h"
#include "robot_update.h"
#include "tssop.h"
#include "gyro_and_angle.h"
#include "dribler.h"

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);

  pinMode(M1_P1, OUTPUT);
  pinMode(M1_P2, OUTPUT);

  pinMode(M2_P1, OUTPUT);
  pinMode(M2_P2, OUTPUT);

  pinMode(M3_P1, OUTPUT);
  pinMode(M3_P2, OUTPUT);

  pinMode(M4_P1, OUTPUT);
  pinMode(M4_P2, OUTPUT);

  pinMode(ADDR_P1, OUTPUT);
  pinMode(ADDR_P2, OUTPUT);
  pinMode(ADDR_P3, OUTPUT);
  pinMode(ADDR_P4, OUTPUT);
  pinMode(BALL_SEN_SIGNAL_1, INPUT_PULLUP);
  pinMode(BALL_SEN_SIGNAL_2, INPUT_PULLUP);

  pinMode(SEN_LEADLE1, INPUT);
  pinMode(SEN_LEADLE2, INPUT);

  pinMode(BUT_DOWN, INPUT);
  pinMode(BUT_UP, INPUT);
  pinMode(BUT_ENTER, INPUT);

  pinMode(LED_CALIBRATION, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  pinMode(KICK_PIN1, OUTPUT);

  pinMode(CHARGE_PIN, INPUT);
  pinMode(CHARGE_LED_PIN, OUTPUT);
  dribler_config();

  timer = millis();
  timer_kick = millis();
  timer_ball = millis();
  timer_ball_capture = millis();
  timer_leadle1 =  millis();
  timer_leadle2 =  millis();


  if(robot_role == 'G') dribler = false;

  // calibration_imu();
}

void loop()
{
  // // // Serial.println(abs(lead_to_degree_borders(ball_angle + robot_local_angle)));
  //unsigned long time0 = micros();
  robot_update();
  coordinates_robot();
  /*// Serial.print(x_soft_c);
  // Serial.print(" ");
  // // Serial.println(y_soft_c);*/
  /*// Serial.print(enemy_distance);
    // Serial.print(" ");
    // Serial.print(our_distance);
    // Serial.print(" ");
    // Serial.print(x_robot);
    // Serial.print(" ");
    // Serial.print(y_robot);
    // Serial.print(" ");
    // Serial.print(if_notice_our);
    // Serial.print(" ");
    // Serial.print(if_notice_enemy);
    // Serial.print(" ");
    //// Serial.print(k);
    // // Serial.println(" ");*/
  /*// Serial.print(x_robot);
    // Serial.print(" ");
    // Serial.print(y_robot);
    // // Serial.println(" ");*/
   /*Serial.print(x_robot);
     Serial.print(" ");
    Serial.println(y_robot);*/
    // Serial.print(" ");
    // Serial.print(ball_distance);
    // Serial.print(" ");
    // // Serial.println(angle_forward);*/
  // // // Serial.println(sign(2));
  /*// Serial.print(analogRead(SEN_LEADLE1));
  // Serial.print(" ");*/
  /*Serial.print(analogRead(SEN_LEADLE2));
  Serial.print(" ");
  Serial.println(if_ball_in_leadle2);*/
  // // // Serial.println(x_robot);
  /*// Serial.print(ball_distance);
  // Serial.print(" ");
  // Serial.print(lead_to_degree_borders(robot_local_angle));
  // Serial.print(" ");
  // // Serial.println(millis() - timer_ball);*/
 //Serial.println((lead_to_degree_borders(robot_local_angle)));
//Serial.println(ball_distance);
 //Serial.println((lead_to_degree_borders(robot_local_angle)));
/*Serial.print(analogRead(SEN_LEADLE1));
Serial.println(" " + String(micros() - time0));*/
//Serial.println(if_ball_in_leadle1);

 /*Serial.print(ball_distance);
    Serial.print(' ');
    Serial.println(ball_angle);*/


  if (stop_motor == false)
  {
    forward();
    //dribler_power(1400);
    //dribler_power(1300);
    //if(robot_role == 'G')
      //forward();
      //ball_capture(190, -1);
    //move_point(100, 100);
    //else
      //forward();
    //move_angle_speed(0, 0, 0);
    /*ball_capture(190, 1);
    if (if_notice_enemy == true) move_angle_speed(angle_forward, speed_forward, e_a);
    else move_angle_speed(angle_forward, speed_forward, 0);*/
    //forward();
    
    
//ball_capture(190, -1);
    
    /*if (if_ball_in_leadle1 == true)
    {
      dribler_power(1300);
      speed_forward = 0;
  }
            
    else
      {   
        //Serial.println(ball_distance);
          ball_capture(190, -1);
          if (ball_distance >= 4.5) dribler_power(1300);
          else dribler_power(1000);
        
      }

    if (if_notice_enemy == true)  move_angle_speed(angle_forward, speed_forward, e_a);
    else move_angle_speed(angle_forward, speed_forward, 0);*/


    //goalkeeper();
    //turn(190);
    //dribler_power(1300);


  }


  else
  {
    dribler_power(1000);
    stop_m();
    timer_ball = millis();
  }
  //Serial.println(ball_distance);
    
 /*// Serial.print(enemy_distance);
    // Serial.print(" ");
     // Serial.print(e_a);
    // Serial.print(" ");
    // Serial.print(our_distance);
    // Serial.print(" ");
      // Serial.print(o_a);
    // Serial.print(" ");
    // Serial.print(x_robot);
    // Serial.print(" ");
    // Serial.print(y_robot);
    // // Serial.println(" ");*/

   /*Serial.println(" ");
     for (int i = 0; i < 32; i++)
     {
     Serial.print(ball_data[i]);
     Serial.print(" ");
     }
     Serial.println(" ");
     Serial.print(ball_distance);
     Serial.print(" ");
      Serial.println(ball_angle);*/
}
