#pragma once

#include "Arduino.h"
#include "config.h"
#include "global.h"

#include "motors.h"
#include "gyro_and_angle.h"
#include "strategy.h"

float sign(float num);

void move_angle_speed (double angle, int speed_m, double angle_turn, double correctionAngle = 0)
{
  if (robot_role == 'F')
  {
    double angle1 = angle - 135 - correctionAngle;
    double angle3 = angle + 135 - correctionAngle;
    double angle2 = angle - 45 - correctionAngle;
    double angle4 = angle + 45 - correctionAngle;

    int speed1 = speed_m * cos(angle1 / 57.3) + turn_angle(angle_turn);
    int speed3 = -speed_m * cos(angle3 / 57.3) + turn_angle(angle_turn);
    int speed2 = -speed_m * cos(angle2 / 57.3) + turn_angle(angle_turn);
    int speed4 = -speed_m * cos(angle4 / 57.3) - turn_angle(angle_turn);
    
    motor1(speed1);
    motor3(speed3);
    motor2(speed2);
    motor4(speed4);
  }

  else
  {
    double angle1 = angle - 135;
    double angle3 = angle + 135;
    double angle2 = angle - 45;
    double angle4 = angle + 45;

    int speed1 = -speed_m * cos(angle1 / 57.3) - turn_angle(angle_turn);
    int speed3 = speed_m * cos(angle3 / 57.3) - turn_angle(angle_turn);
    int speed2 = speed_m * cos(angle2 / 57.3) - turn_angle(angle_turn);
    int speed4 = speed_m * cos(angle4 / 57.3) + turn_angle(angle_turn);
    
    motor1(speed1);
    motor3(speed3);
    motor2(speed2);
    motor4(speed4);
  }
}

void move_point(int x_point, int y_point)
{
  int err_x = x_point-x_robot;
  int err_y = y_point-y_robot;
 
  // if (abs(err_y) < 3) err_y = 0;
  if (err_y < 0)
  {
    angle_y_point = 180;
    u_y_point = -(err_y * Kp_point + (err_y - err_old_y_point) * Kd_point + err_i_y_point);
  }
  else
  {
    angle_y_point = 0;
    u_y_point = err_y * Kp_point + (err_y - err_old_y_point) * Kd_point + err_i_y_point;
  }

  // if (abs(err_x) < 3) err_x = 0;
  if (err_x > 0)
  {
    angle_x_point = -90;
    u_x_point = Kp_point * err_x + (err_x - err_old_x_point) * Kd_point + err_i_x_point;
  }
  else
  {
    angle_x_point = 90;
    u_x_point = -(Kp_point * err_x + (err_x - err_old_x_point) * Kd_point + err_i_x_point);
  }
  // u_x = Kp_line_goal_ball * err_x + (err_x - err_old_x) * Kd_line_goal_ball + err_i_x;
  // angle_x =lead_to_degree_borders(angle_y + 90*sign(u_x)) ;
  float xy = sqrt(u_y_point * u_y_point + u_x_point * u_x_point);
  xy = constrain(xy, -220, 220);
  if (angle_y_point == 0)
    angle_xy_point = lead_to_degree_borders(sign(angle_x_point) * lead_to_degree_borders(90 - (atan2(u_y_point, u_x_point) * 57.3)));
  else
    angle_xy_point = lead_to_degree_borders(sign(angle_x_point) * lead_to_degree_borders((atan2(u_y_point, u_x_point) * 57.3) + 90));
  // angle_xy = lead_to_degree_borders(90 - atan2(u_y, u_x) * 57.3);
  // }


  err_old_y_point = err_y;
  err_old_x_point = err_x;
  err_i_y_point += Ki_point * err_y;
  err_i_x_point += Ki_point * err_x;
 
  angle_forward = angle_xy_point;
  speed_forward = constrain(xy, -130, 130);

  /*Serial.print(angle_xy_point);
  Serial.print(" ");
  Serial.println(xy);*/

  //move_angle_speed(angle_forward, speed_forward, 0, robot_local_angle);
}