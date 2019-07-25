/*
 * Blink
 * Turns on an LED for one second and then
 * turns off for one section
 * (in public domain)
 */

int led = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(500);
}
