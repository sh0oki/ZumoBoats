/* Example of using the stepper motor with the motor shield
 *  
 *  Stepper motors, due to their unique design, can be controlled to a high degree of accuracy without any feedback mechanisms. 
 *  The shaft of a stepper, mounted with a series of magnets, is controlled by a series of electromagnetic coils that are charged positively and negatively in a specific sequence, 
 *  precisely moving it forward or backward in small "steps".
 * 
 */

#include <AFMotor.h>

// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor(64, 2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  motor.setSpeed(10);  // 10 rpm   
}

void loop() {
  Serial.println("Single coil steps");
  motor.step(100, FORWARD, SINGLE); 
  motor.step(100, BACKWARD, SINGLE); 

  Serial.println("Double coil steps");
  motor.step(100, FORWARD, DOUBLE); 
  motor.step(100, BACKWARD, DOUBLE);

  Serial.println("Interleave coil steps");
  motor.step(100, FORWARD, INTERLEAVE); 
  motor.step(100, BACKWARD, INTERLEAVE); 

  Serial.println("Micrsostep steps");
  motor.step(100, FORWARD, MICROSTEP); 
  motor.step(100, BACKWARD, MICROSTEP); 
}
