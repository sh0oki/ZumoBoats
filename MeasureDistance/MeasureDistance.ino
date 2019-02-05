/* Example of using the Ultrasonic sensor to measure distance.
 *  
 *  The HC-SR04 ultrasonic sensor uses SONAR to determine the distance of an object just like the bats do. 
 *  It offers excellent non-contact range detection with high accuracy and stable readings in an easy-to-use package from 2 cm to 400 cm.
 *  The operation is not affected by sunlight or black material, although acoustically, soft materials like cloth can be difficult to detect. 
 * 
 * PINOUT: 
 * VCC  - 5V 
 * GND  - GND
 * TRIG - A0
 * ECHO - A1
 * 
 */

const int trigPin = A0; // Trigger Pin of Ultrasonic Sensor
const int echoPin = A1; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal

   pinMode(trigPin, OUTPUT); // Setup the trigger pin as output 
   pinMode(echoPin, INPUT); // Setup the echo pin as input
}

void loop() {
   long duration, cm;

   // Emit pulse
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);

   // Measure the time to get the reflected pulse
   duration = pulseIn(echoPin, HIGH);

   // Convert time into distance units and print the result
   cm = microsecondsToCentimeters(duration);
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
