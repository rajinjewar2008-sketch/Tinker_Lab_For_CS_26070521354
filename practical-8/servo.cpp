#include <Servo.h>

Servo myServo;
int pos = 0;

void setup() {
  myServo.attach(9); // Connect servo signal to digital pin 9
}

void loop() {
  // Move from 0 to 180 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(15);
  }
  
  // Move back from 180 to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);
    delay(15);
  }
}
