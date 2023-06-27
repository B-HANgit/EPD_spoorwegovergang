#include <Servo.h>
Servo myServo;
const int SERVO_PIN = 11;
int servoPos;

void servoSetup() {
  myServo.attach(SERVO_PIN);
}

void setServoPos(int pos) {
  servoPos = pos;
  myServo.write(pos);
}

int getServoPos() {
  return servoPos;
}
