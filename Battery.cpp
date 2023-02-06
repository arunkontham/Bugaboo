/*
  Battery.cpp - Library for calculating Battery level for ChillBaby Inc. supported products.
  Created by Mohannad A. Alhassan, September 9, 2021.
*/

#include "Arduino.h"
#include "Battery.h"

float Level(){ // Get battery voltage
  float adc=0;  // Initialize adc variable
  unsigned int lcsc=0;  // Temp variable
  adc=0;
  for(lcsc=0;lcsc<50;lcsc++){ // Average adc value over 250ms
    adc=adc+analogRead(36);
    delay(5);
  }
  adc=(float)adc/50; // Get instant voltage reading
  adc=(float)adc/1241; // Convert to digital voltage
  adc=adc*2; // Double value to compensate for voltage divider on hardware
  adc = adc + 0.32; // Temp mod
  //adc=0.9009*adc+0.6802; // Modifier derived from tests
  return(adc);
}

int Percent(float bVoltage, bool loadOn) { // Look up table for battery percentage based on battery voltage.
  int bPercent = 0;
  if(loadOn){
       bVoltage = 0.2-bVoltage;
    }
    else{
      bVoltage = 0.2+bVoltage;
    }
  if(bVoltage > 4.2) bPercent = 100;
  else if(bVoltage == 4.2) bPercent = 100;
  else if(bVoltage < 4.2 && bVoltage > 4.1) bPercent = 100;
  else if(bVoltage == 4.1) bPercent = 95;
  else if(bVoltage < 4.1 && bVoltage > 4.0) bPercent = 90;
  else if(bVoltage == 4.0) bPercent = 85; 
  else if(bVoltage < 4.0 && bVoltage > 3.9) bPercent = 80;
  else if(bVoltage == 3.9) bPercent = 75;
  else if(bVoltage < 3.9 && bVoltage > 3.8) bPercent = 70;
  else if(bVoltage == 3.8) bPercent = 65 ;
  else if(bVoltage < 3.8 && bVoltage > 3.7) bPercent = 60;
  else if(bVoltage == 3.7) bPercent = 55;
  else if(bVoltage < 3.7 && bVoltage > 3.6) bPercent = 50;
  else if(bVoltage == 3.6) bPercent = 45;
  else if(bVoltage < 3.6 && bVoltage > 3.5) bPercent = 40;
  else if(bVoltage == 3.5) bPercent = 35;
  else if(bVoltage < 3.5 && bVoltage > 3.4) bPercent = 30;
  else if(bVoltage == 3.4) bPercent = 25;
  else if(bVoltage < 3.4 && bVoltage > 3.3) bPercent = 20;
  else if(bVoltage == 3.3) bPercent = 15;
  else if(bVoltage < 3.3 && bVoltage > 3.2) bPercent = 10;
  else if(bVoltage == 3.2) bPercent = 5;
  return(bPercent);
}
   
