/* Example of using DC Motors with the driver shield.
 *  
 * A DC motor (Direct Current motor) is the most common type of motor. 
 * DC motors normally have just two leads, one positive and one negative. 
 * If you connect these two leads directly to a battery, the motor will rotate. 
 * If you switch the leads, the motor will rotate in the opposite direction.
 * Warning − Do not drive the motor directly from Arduino board pins - This may damage the board. Use a driver Circuit or an IC.
 * 
 */

#include <AFMotor.h>

AF_DCMotor motor1(1); // Definition of Motor connected to the shield M1 pins
AF_DCMotor motor2(3); // Definition of Motor connected to the shield M3 pins

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  motor1.run(BACKWARD); // Set the rotation direction FORWARD/BACKWARD
  motor1.setSpeed(250); // Set the rotation Speed between 0 and 255
  delay(1000); // Wait for 1 sec (in microseconds)
  
  motor2.run(BACKWARD);
  motor2.setSpeed(250);  
  delay(1000); 
  
  // Stop the motor (equals to setSpeed(0)
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
}
