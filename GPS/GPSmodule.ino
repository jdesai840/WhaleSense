//This code allows the Arduino microcontroller to read GPS data, and then send it to the Raspberry Pi via USB serial communication

#include "TinyGPS++.h"
#include "SoftwareSerial.h"
#include "Servo.h"

SoftwareSerial serial_connection(10, 11); //RX=pin 10, TX=pin 11
TinyGPSPlus gps;
Servo pitchServo;
Servo yawServo;

void setup()
{
  //Initializing GPS module
  Serial.begin(9600);
  serial_connection.begin(9600);
  Serial.println("GPS Start");
  //Initializing servo for thermal camera gimbal control
  pitchServo.attach(8);
  yawServo.attach(9);
}

void loop()
{
  while(serial_connection.available())
  {
    gps.encode(serial_connection.read());
  }
  if(gps.location.isUpdated()) //Collecting GPS data, and sending it to Raspi via USB Serial
  {
    Serial.println("Satellite Count:");
    Serial.println(gps.satellites.value());
    Serial.println("Latitude:");
    Serial.println(gps.location.lat(), 6);
    Serial.println("Longitude:");
    Serial.println(gps.location.lng(), 6);
    Serial.println("Speed MPH:");
    Serial.println(gps.speed.mph());
    Serial.println("Altitude Feet:");
    Serial.println(gps.altitude.feet());
    Serial.println("");
  }
}

