/*
 * Blink
 * Turns on an LED for one second and then
 * turns off for one section
 * (in public domain)
 */

int blue = 13;
int red = 12;
int yel = 11;

void setup() {
  // init light colors
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  // Alternate between blue, yel, and green
 
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(4000);
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(11, LOW);
  delay(4000);
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(4000);
}
