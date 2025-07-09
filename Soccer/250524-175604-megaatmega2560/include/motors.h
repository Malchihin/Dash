#pragma once

#include "Arduino.h"
#include "config.h"
#include "global.h"

void motor1 (int16_t power) {
  power = constrain (power, -255, 255);
  if (power < 0) {
    digitalWrite (M1_P1, 0);
    analogWrite (M1_P2, abs(power));
  }
  else {
    digitalWrite (M1_P2, 0);
    analogWrite (M1_P1, power);
  }
}

void motor2 (int16_t power) {
  power = constrain (power, -255, 255);
  if (power < 0) {
    digitalWrite (M2_P1, 0);
    analogWrite (M2_P2, abs(power));
  }
  else {
    digitalWrite (M2_P2, 0);
    analogWrite (M2_P1, power);
  }
}

void motor3 (int16_t power) {
  power = constrain (power, -255, 255);
  if (power < 0) {
    digitalWrite (M3_P2, 0);
    analogWrite (M3_P1, abs(power));
  }
  else {
    digitalWrite (M3_P1, 0);
    analogWrite (M3_P2, power);
  }
}

void motor4 (int16_t power) {
  power = constrain (power, -255, 255);
  if (power < 0) {
    digitalWrite (M4_P2, 0);
    analogWrite(M4_P1, abs(power));
  }
  else {
    digitalWrite (M4_P1, 0);
    analogWrite (M4_P2, power);
  }
}

void stop_m () {
  digitalWrite (M1_P1, HIGH);
  digitalWrite (M1_P2, HIGH);

  digitalWrite (M2_P1, HIGH);
  digitalWrite (M2_P2, HIGH);

  digitalWrite (M3_P1, HIGH);
  digitalWrite (M3_P2, HIGH);

  digitalWrite (M4_P1, HIGH);
  digitalWrite (M4_P2, HIGH);
}
