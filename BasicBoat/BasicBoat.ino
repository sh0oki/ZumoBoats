/* Example of a boat with one DC motor and one Servo
 *  
 */

#include <AFMotor.h>
#include <Servo.h>

const int trigPin = A0;
const int echoPin = A1;

Servo myServo;

AF_DCMotor DCMotor(4);

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

// samples - average over number of samples for more accuracy 
void getDistance(int samples)  
{
  if (samples == 0)
    return; 
  duration =0;
  for(int i=0;i<samples;i++)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration += pulseIn(echoPin, HIGH);  
  }

  duration = duration/samples;
  // Calculating the distance
  distance = duration*0.034/2;
  Serial.print(distance);
  Serial.println("cm");
}

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  myServo.attach(9);
  myServo.write(0);
}

void loop() {
  if (state != previousState)
  {
    switch(state)
    {
      case STOP: break;
      case SAIL_STRAIGHT: 
      Serial.println("STR");
        DCMotor.run(FORWARD);
        DCMotor.setSpeed(250);
        myServo.write(15);
        break;
      case TURN_RIGHT:
      Serial.println("right");
        myServo.write(0);
        break;
      case TURN_LEFT:
        Serial.println("left");
        myServo.write(30);
        break;
    }
  }

  previousState = state;

  getDistance(3);
  if (distance < 10)
  {
    state = TURN_RIGHT;
  }
  else if (distance > 20)
  {
    state = SAIL_STRAIGHT;
  }
  delay(200);
}
