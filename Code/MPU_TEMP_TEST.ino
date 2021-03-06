
#include<Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

const int MPU_6050_addr = 0x68;
const byte PWR_MGMT_1 = 0x6B;
const byte ACCEL_CONFIG = 0x1C;
const byte ACCEL_XOUT_H = 0x3B;
const byte GYRO_CONFIG = 0x1B;


float MPU_6050_AccX;
float MPU_6050_AccY;
float MPU_6050_AccZ;
float MPU_6050_Temp;
float MPU_6050_GyroX;
float MPU_6050_GyroY;
float MPU_6050_GyroZ;

Adafruit_BMP280 bme;

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(MPU_6050_addr);
  Wire.write(PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission();
  Wire.beginTransmission(MPU_6050_addr);
  Wire.write(ACCEL_CONFIG);
  Wire.write(0x18);     // +- 16g
  Wire.endTransmission();
  Wire.beginTransmission(MPU_6050_addr);
  Wire.write(GYRO_CONFIG);
  Wire.write(0x08);
  Wire.endTransmission();
  bme.begin();
  Serial.begin(9600);
}

void loop() {
  long Time = millis();
  counter = counter+1;
  
  Wire.beginTransmission(MPU_6050_addr);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission();
  Wire.requestFrom(MPU_6050_addr,14);
  MPU_6050_AccX = Wire.read() << 8 | Wire.read();
  MPU_6050_AccY = Wire.read() << 8 | Wire.read();
  MPU_6050_AccZ = Wire.read() << 8 | Wire.read();
  MPU_6050_Temp = Wire.read() << 8 | Wire.read();  
  MPU_6050_GyroX = Wire.read() << 8 | Wire.read();
  MPU_6050_GyroY = Wire.read() << 8 | Wire.read();
  MPU_6050_GyroZ = Wire.read() << 8 | Wire.read();

  MPU_6050_AccX = MPU_6050_AccX/2048;
  MPU_6050_AccY = MPU_6050_AccY/2048;
  MPU_6050_AccZ = MPU_6050_AccZ/2048;
  MPU_6050_Temp = MPU_6050_Temp/340 + 36.53;
  MPU_6050_GyroX = MPU_6050_GyroX/65.5;
  MPU_6050_GyroY = MPU_6050_GyroY/65.5;
  MPU_6050_GyroZ = MPU_6050_GyroZ/65.5;

  Serial.print(Time,1);Serial.print("; ");
  Serial.print(counter,1);Serial.print("; ");
  Serial.print(MPU_6050_AccX,2);Serial.print("; ");
  Serial.print(MPU_6050_AccY,2);Serial.print("; ");
  Serial.print(MPU_6050_AccZ,2);Serial.print("; ");
  Serial.print(MPU_6050_GyroX,2);Serial.print("; ");
  Serial.print(MPU_6050_GyroY,2);Serial.print("; ");
  Serial.print(MPU_6050_GyroZ,2);Serial.print("; ");
  Serial.print(MPU_6050_Temp,1);Serial.print("; ");
  Serial.print(bme.readTemperature());Serial.print("; ");
  Serial.print(bme.readPressure()/100);Serial.print("; ");
  Serial.print(bme.readAltitude(1017));Serial.print("; ");
  Serial.println("\n");
  while(millis()-Time<500)
    delay(1);

}
