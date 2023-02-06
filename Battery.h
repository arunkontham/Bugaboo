#ifndef Battery_h
#define Battery_h

#include "Arduino.h"

//int Percent(float V);
int Percent(float bVoltage, bool loadOn);
float Level();
#endif
