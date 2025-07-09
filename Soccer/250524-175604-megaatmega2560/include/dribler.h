#pragma once

#include "Arduino.h"
#include "Servo.h"
#include "config.h"

void dribler_config()
{
esc.attach(13); 
  delay(5000);    // Wait for ESC to initialize

  esc.writeMicroseconds(2000); // Send max throttle signal
  delay(1000);

  esc.writeMicroseconds(1000); // Send min throttle signal
  delay(1000);
}

void dribler_power(int power)
{
    power = constrain(power, 1000, 2000);
  esc.writeMicroseconds(power);  
}