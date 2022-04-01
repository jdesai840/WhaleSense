#include <Wire.h>
#include <LIDARLite.h>
#include <Servo.h>

//Global variables
LIDARLite lidarLite;
int cal_cnt = 0;
const int servoPin = 10;
Servo lidarServo;
int lidarAngle = 0;

void setup()
{
  Serial.begin(9600); // Initialize serial connection to Raspberry Pi
  lidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  lidarLite.configure(0);
  lidarServo.attach(servoPin);

void loop()
{
  int dist;
  for (lidarAngle = 0; lidarAngle <= 180; lidarAngle +=5) {
      if ( cal_cnt == 0 ) {
        dist = lidarLite.distance();      // With bias correction
      } else {
        dist = lidarLite.distance(false); // Without bias correction
      }
      // Increment reading counter
      cal_cnt++;
      cal_cnt = cal_cnt % 100;

      // Display distance and lidarAngle for 2D obstacle map construction
      Serial.print(dist);
      Serial.print(lidarAngle);
      delay(10);
  }
}
