#pragma once

#include "Arduino.h"

double _data, angK, distK;

//Для тсопов
float d_alpha = 11.25;
double ball_angle = 0;
float ball_distance = 0;
bool if_ball = false;

int ir_addr[16][4] = {
  {0, 0, 0, 0},
  {0, 0, 0, 1},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 1, 0, 0},
  {0, 1, 0, 1},
  {0, 1, 1, 0},
  {0, 1, 1, 1},
  {1, 0, 0, 0},
  {1, 0, 0, 1},
  {1, 0, 1, 0},
  {1, 0, 1, 1},
  {1, 1, 0, 0},
  {1, 1, 0, 1},
  {1, 1, 1, 0},
  {1, 1, 1, 1}
};

int ball_data[32];
const int  null_ball_angle = 13;
float ball_distance_soft;
float k_distance = 0.97;

//Дистанция до мяча при которой (или меньше) начинается объезд по окружности
const float min_dist_to_ball = 6;

//const int v_capture = 100;
//double angK;
//double distK;
//float _data;

//Для камеры
byte data_camera[5];
float yellow_local_angle, yellow_distance, blue_local_angle, blue_distance;
bool if_notice_yellow = false, if_notice_blue = false;
bool if_notice_our = false, if_notice_enemy = false;


//Для функции update
int32_t yaww, robot_local_angle, errOld, robot_speed;

//Для датчиков мяча в ковше
int sen_leadle = 0;

//Для расчета координат
//int blue_goal_y, blue_goal_x = 120;
//int yellow_goal_y, yellow_goal_x = 120;
int y_robot, x_robot;
float o_a, e_a, x_o, y_o, x_e, y_e;

int our_goal_y = 10, our_goal_x = 75, enemy_goal_y = 220, enemy_goal_x = 75;
float our_local_angle, our_distance, enemy_local_angle, enemy_distance;
//float k;


//Для гироскопа
int null_angle = 0;
int gyro_angle = 0;


//Определение наших ворот, роли роботa
char our_goal = 'Y';
char robot_role = 'G';

//Поворот
const float kP = 1.3;
const float kD = 23;
const float kI = 0;
int err_old_angle;
float err_i_angle = 0;
int u_angle;

//Для моторов
bool stop_motor = true;

//Время
int32_t timer;
int32_t timer_kick;
int32_t timer_ball;
int32_t timer_forward;
int32_t timer_ball_capture;
int32_t timer_leadle1;
int32_t timer_leadle2;
int32_t timer_move_point;

//Датчик мяча в ковше
bool if_ball_in_leadle1 = false;
bool if_ball_in_leadle2 = false;
int leadle1 = 0;
int leadle1_soft = 0;
float k_leadle1 = 0.8;

//Вратарь
double angle_rout_goalkeeper;
double angle_goalkeeper;
float speed_goalkeeper;
const float Kp_line_goal = 4.6;
const float Kd_line_goal = 12;
const float Ki_line_goal = 0.0038;
float err_old_y = 0;
int y_goalkepeer1 = 45;
int R = 51;
//int y_goalkepeer;
int x_goalkepeer;
const float Kp_line_goal_ball = 4.6;
const float Kd_line_goal_ball = 12;
const float Ki_line_goal_ball = 0.0038;
float err_i_y = 0;
float err_i_x = 0;
float err_old_x = 0;
double angle_x;
double angle_y;
float u_y, u_x;
double angle_xy;
int err_x, err_y;
const int x2 = 88;
const int x1 = 150;
const int y1 = 45;
double xy;
int x_robot_point1;
double angle2_robot_point;

double x_soft = 0, y_soft = 0;
double k_ball = 0.2;
uint32_t dash_clowns = 0;

double k_coordinates = 0.9;
double x_soft_c = 0, y_soft_c = 0;

//Нападающий
double angle_forward;
int speed_forward;
int state_forward = 1;
float kp_ball_distance = 30;
float max_distance = 7;
int x_dribler_point = 30, y_dribler_point = 140;
int dribler_angle = 0;

//Движение в точку
int f;
double angle_y_point, angle_x_point, angle_xy_point;
float u_y_point, u_x_point;
float Kp_point = 5, Kd_point = 20, Ki_point =0.005;
int err_old_y_point, err_old_x_point, err_i_y_point, err_i_x_point;

//Дрибллер
bool dribler = true;


//Ауты нападающего
const int out1_x = 120, out1_y = 165, out2_x = 30 , out3_y = 70; //основные границы
const int out1_x2 =110, out1_y2 = 155, out2_x2 = 40, out3_y2 = 80;  //границы замедления

//Ауты вратаря
const int out1_y_g = 45, out1_x_g = 145, out2_x_g = 35; //основные границы
const int out1_y2_g = 50, out1_x2_g = 140, out2_x2_g =40; //границы замедления