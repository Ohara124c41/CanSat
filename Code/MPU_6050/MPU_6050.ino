#include<Wire.h> // I2C Lib

/* Constanst */
const int MPU_6050_addr = 0x68; // I2C addr of MPU-6050
const byte PWR_MGMT_1 = 0x6B; // reg addr
const byte ACCEL_CONFIG = 0x1C; // reg addr
const byte ACCEL_XOUT_H = 0x3B; // reg addr
const byte GYRO_CONFIG = 0x1B; // reg addr

/* Variables */
float MPU_6050_AccX;
float MPU_6050_AccY;
float MPU_6050_AccZ;
float MPU_6050_Temp;
float MPU_6050_GyroX;
float MPU_6050_GyroY;
float MPU_6050_GyroZ;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(MPU_6050_addr);
  Wire.write(PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission();
  Wire.beginTransmission(MPU_6050_addr);
  Wire.write(ACCEL_CONFIG);
  Wire.write(0x10);
  Wire.endTransmission();
  Wire.beginTransmission(MPU_6050_addr);
  Wire.write(GYRO_CONFIG);
  Wire.write(0x08);
  Wire.endTransmission();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(MPU_6050_addr);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission();
  Wire.requestFrom(MPU_6050_addr, 14);
  MPU_6050_AccX = Wire.read() << 8 | Wire.read();
  MPU_6050_AccY = Wire.read() << 8 | Wire.read();
  MPU_6050_AccZ = Wire.read() << 8 | Wire.read();
  MPU_6050_Temp = Wire.read() << 8 | Wire.read();
  MPU_6050_GyroX = Wire.read() << 8 | Wire.read();
  MPU_6050_GyroY = Wire.read() << 8 | Wire.read();
  MPU_6050_GyroZ = Wire.read() << 8 | Wire.read();
  MPU_6050_AccX = MPU_6050_AccX/4096;
  MPU_6050_AccY = MPU_6050_AccY/4096;
  MPU_6050_AccZ = MPU_6050_AccZ/4096;
  MPU_6050_Temp = MPU_6050_Temp/340 + 36.53;
  MPU_6050_GyroX = MPU_6050_GyroX/65.5;
  MPU_6050_GyroY = MPU_6050_GyroY/65.5;
  MPU_6050_GyroZ = MPU_6050_GyroZ/65.5;
  Serial.print("MPU-6050 AccX  "; Serial.print(MPU_6050_AccX, 2); Serial.println("[g]");
  Serial.print("MPU-6050 AccY  "; Serial.print(MPU_6050_AccY, 2); Serial.println("[g]");
  Serial.print("MPU-6050 AccZ  "; Serial.print(MPU_6050_AccZ, 2); Serial.println("[g]");
  Serial.print("MPU-6050 GyroX  "; Serial.print(MPU_6050_AccX, 2); Serial.println("[deg/s]");
  Serial.print("MPU-6050 GyroY  "; Serial.print(MPU_6050_AccY, 2); Serial.println("[deg/s]");
  Serial.print("MPU-6050 GyroZ  "; Serial.print(MPU_6050_AccZ, 2); Serial.println("[deg/s]");
  Serial.print("MPU-6050 Temp  "; Serial.print(MPU_6050_Temp, a); Serial.println("[deg C]");
  Serial.print("---------break--------");
  delay(1000);
}
