/*
  This code outputs the raw accelerometer, gyroscope, and magnetometer data from the
  LSM9DS1 9D sensor.

  This uses the default Arduino_LSM9DS1 library, which has slow sample rates and preset ranges.
*/


#include <Arduino_LSM9DS1.h>

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("a_x\ta_y\ta_z\tw_x\tw_y\tw_z\tm_x\tm_y\tm_z");

  IMU.begin();
}


struct AccelData
{
  float x = 0.0;
  float y = 0.0;
  float z = 0.0;
} accel;

struct GyroData 
{
  float x = 0.0;
  float y = 0.0;
  float z = 0.0;
} gyro;

struct MagData 
{
  float x = 0.0;
  float y = 0.0;
  float z = 0.0;
} mag;

void loop() {
  if(IMU.accelerationAvailable())
  {
    IMU.readAcceleration(accel.x, accel.y, accel.z);
  }

  if(IMU.gyroscopeAvailable())
  {
    IMU.readGyroscope(gyro.x, gyro.y, gyro.z);
  }

  if(IMU.magneticFieldAvailable())
  {
    IMU.readMagneticField(mag.x, mag.y, mag.z);
  }

  Serial.print(accel.x);
  Serial.print('\t');
  Serial.print(accel.y);
  Serial.print('\t');
  Serial.print(accel.z);
  Serial.print('\t');
  Serial.print(gyro.x);
  Serial.print('\t');
  Serial.print(gyro.y);
  Serial.print('\t');
  Serial.print(gyro.z);
  Serial.print('\t');
  Serial.print(mag.x);
  Serial.print('\t');
  Serial.print(mag.y);
  Serial.print('\t');
  Serial.println(mag.z);
}
