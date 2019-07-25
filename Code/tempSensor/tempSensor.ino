const int analogInPin = A0; // analog IO
float tempSensorValue = 0; // temp sensor data

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  }

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  tempSensorValue = analogRead(analogInPin);
  tempSensorValue = tempSensorValue * 5000/1023 * 1/10;
  Serial.println(tempSensorValue, 1); 
  delay(500); 
  digitalWrite(13, LOW);
  delay(500);
  }
