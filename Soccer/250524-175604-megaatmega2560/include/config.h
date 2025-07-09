#pragma once
#include "Arduino.h"
#include "Servo.h"

#define M1_P1 2
#define M1_P2 3

#define M2_P1 5
#define M2_P2 6

#define M3_P1 7
#define M3_P2 8

#define M4_P1 10
#define M4_P2 9

#define ADDR_P1 23
#define ADDR_P2 25
#define ADDR_P3 27
#define ADDR_P4 29

#define BALL_SEN_SIGNAL_1 31
#define BALL_SEN_SIGNAL_2 26

#define SEN_LEADLE1 A1 //A2 - 2   A1 - 1
#define SEN_LEADLE2 A2

#define BUT_DOWN 38
#define BUT_UP 36
#define BUT_ENTER 40

#define LED_CALIBRATION 42
#define LED_YELLOW 48
#define LED_BLUE 44

#define KICK_PIN1 14

#define CHARGE_PIN A0
#define CHARGE_LED_PIN 46

#define ec 2.7182

Servo esc;