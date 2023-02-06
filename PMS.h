/*!
 * @file Adafruit_PM25AQI.h
 *
 * This is the documentation for Adafruit's PM25 AQI driver for the
 * Arduino platform.  It is designed specifically to work with the
 * Adafruit PM25 air quality sensors: http://www.adafruit.com/products/4632
 *
 * These sensors use I2C or UART to communicate.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Written by Ladyada for Adafruit Industries.
 *
 * BSD license, all text here must be included in any redistribution.
 *
 */

#ifndef PMS_H
#define PMS_H

#include "Arduino.h"
#include <Adafruit_I2CDevice.h>

// the i2c address
#define PMSA003I_I2CADDR_DEFAULT 0x12 ///< PMSA003I has only one I2C address

/**! Structure holding Plantower's standard packet **/
typedef struct PMSAQIdata {
  uint16_t framelen;       ///< How long this data chunk is
  uint16_t pm10_standard,  ///< Standard PM1.0 or Retaining
      pm25_standard,       ///< Standard PM2.5 or Retaining
      pm100_standard;      ///< Standard PM10.0 or Retaining
  uint16_t pm10_env,       ///< Environmental PM1.0
      pm25_env,            ///< Environmental PM2.5
      pm100_env;           ///< Environmental PM10.0
  uint16_t retain0, ///Retaining
      retain1,      ///Retaining
      retain2;      ///Retaining

//  uint16_t unused;         ///< Unused
  uint16_t checksum;       ///< Packet checksum
} PM25_AQI_Data;

/*!
 *  @brief  Class that stores state and functions for interacting with
 *          PM2.5 Air Quality Sensor
 */
class Adafruit_PM25AQI {
public:
  Adafruit_PM25AQI();
  bool begin_I2C(TwoWire *theWire = &Wire);
  bool begin_UART(Stream *theStream);
  bool read(PM25_AQI_Data *data);

private:
  Adafruit_I2CDevice *i2c_dev = NULL;
  Stream *serial_dev = NULL;
  uint8_t _readbuffer[32];
};

#endif
