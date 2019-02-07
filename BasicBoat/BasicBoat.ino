
/* Example of a boat with one DC motor and one Servo
 *  
 */

#include <AFMotor.h>
#include <Servo.h>

Servo myServo;

AF_DCMotor DCMotorWater(1);
AF_DCMotor DCMotorA(3);
AF_DCMotor DCMotorB(4);
AF_DCMotor DCMotorOn(4);


long duration;
int distance;

enum State{
  STOP,
  SAIL_STRAIGHT,
  TURN_RIGHT,
  TURN_LEFT
};

State state = SAIL_STRAIGHT;
State previousState = STOP;

int count = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
}

void loop() {


  DCMotorA.run(FORWARD);
  DCMotorB.run(FORWARD);
  .run(FORWARD);
  DCMotorOn.run(FORWARD);

  DCMotorA.setSpeed(250);
  DCMotorB.setSpeed(250);
  DCMotorOn.setSpeed(250);
  delay(3133);

  if (count == 2) {
    DCMotorWater.setSpeed(250);
  }

  
  DCMotorA.setSpeed(0);
  DCMotorB.setSpeed(0);
  delay(800);
  
  DCMotorA.setSpeed((count % 2 == 0 ? 200 : 0));
  DCMotorB.setSpeed((count % 2 != 0 ? 200 : 0));
  delay(300);

  count++;
}
