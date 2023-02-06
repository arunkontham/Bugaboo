/*
  Battery.cpp - Library for calculating Battery level for ChillBaby Inc. supported products.
  Created by Mohannad A. Alhassan, September 18, 2021.
*/

#include "Arduino.h"
#include "AirQuality.h"

float AQM(float Air){  // Air quality algorithm

  float AirQual = 0;
  if(Air >= 0 && Air <= 12) AirQual = 4.3 * Air;
  else if(Air >= 12.1 && Air <= 35.4) AirQual = 24.05 + (2.145 * Air);
  else if(Air >= 35.5 && Air <= 55.4) AirQual = 10.83 + (2.512 * Air);
  else if(Air >= 55.5 && Air <= 150.4) AirQual = 120.81 + (0.526 * Air);
  else if(Air >= 150.5 && Air <= 250.4) AirQual = 124.6 + (0.501 * Air);
  else if(Air >= 250.5 && Air <= 450) AirQual = 187.14 + (0.251 * Air);
  else if(Air >=450.1 && Air <= 10000) AirQual = 297.95 + ( 0.005 * Air);
  return (AirQual);
}
