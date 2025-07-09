#pragma once

#include "Arduino.h"

#include "buttons.h"
#include "camera.h"
#include "config.h"
#include "gyro_and_angle.h"
#include "robot_update.h"
#include "tssop.h"
#include "gyro_and_angle.h"

void detect_ball()
{
    for (int i = 0; i < 16; i++)
    {
      digitalWrite(ADDR_P1, ir_addr[i][0]);
      digitalWrite(ADDR_P2, ir_addr[i][1]);
      digitalWrite(ADDR_P3, ir_addr[i][2]);
      digitalWrite(ADDR_P4, ir_addr[i][3]);
      delayMicroseconds(10);
      //int adc_data = analogRead(BALL_SEN_SIGNAL_1);
      //ball_data[i] = adc_data > 600 ? 0 : 1;
      ball_data[i] = !digitalRead(BALL_SEN_SIGNAL_1);
    }

    for (int i = 0; i < 16; i++)
    {
      digitalWrite(ADDR_P1, ir_addr[i][0]);
      digitalWrite(ADDR_P2, ir_addr[i][1]);
      digitalWrite(ADDR_P3, ir_addr[i][2]);
      digitalWrite(ADDR_P4, ir_addr[i][3]);
      delayMicroseconds(10);
      //int adc_data = analogRead(BALL_SEN_SIGNAL_2);
      //ball_data[i + 16] = adc_data > 600 ? 0 : 1;
      ball_data[i + 16] = !digitalRead(BALL_SEN_SIGNAL_2);
    }

    double x = 0;
    double y = 0;
    for (int i = 0; i < 32; i++)
    {
      x += ball_data[i] * sin((d_alpha * i) / 57.3);
      y += ball_data[i] * cos((d_alpha * i) / 57.3);
    }

    /*if (robot_role == 'G')
    {
      x_soft = k_ball * x + x_soft * (1 - k_ball);
      y_soft = k_ball * y + y_soft * (1 - k_ball);
      ball_angle = -1 * (lead_to_degree_borders(atan2(x_soft, y_soft) * 57.3));
      ball_distance = sqrt(x_soft * x_soft + y_soft * y_soft);
      dash_clowns = millis();
    }
    else
    {*/
      ball_angle = -1 * lead_to_degree_borders(atan2(x, y) * 57.3)-null_ball_angle;
      //ball_distance_soft = k_distance *sqrt(x * x + y * y) + ball_distance_soft*(1 - k_distance);
      //ball_distance = ball_distance_soft;
      ball_distance = sqrt(x * x + y * y);
      
    //}
    if (ball_angle == -null_ball_angle and ball_distance == 0) ball_angle = 0;
    if(robot_role == 'F')
    {
      if (abs(ball_angle) > 160) ball_distance = ball_distance*2;
    }
}
