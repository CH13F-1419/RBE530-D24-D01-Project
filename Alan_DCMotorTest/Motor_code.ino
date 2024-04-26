#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Connect two motors with the following terminals
Adafruit_DCMotor *motor1 = AFMS.getMotor(1); // Motor connected to M1
Adafruit_DCMotor *motor2 = AFMS.getMotor(2); // Motor connected to M2
Adafruit_DCMotor *motor3 = AFMS.getMotor(3); // Motor connected to M3

const int buttonPin = 2;  // the number of the pushbutton pin
int buttonState = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Competition Mode: Enabled");

  AFMS.begin();  // Create with the default frequency 1.6KHz
  motor1->setSpeed(150);  // Set the speed to 150/255
  motor2->setSpeed(150);  // Set the speed to 150/255
  motor3->setSpeed(75);  // Set the speed to 75/255
 pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
  Serial.println("Ramp!");
  motor3->run(BACKWARD);
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  delay(1000);
  }
  else {
  Serial.println("Drive!");
  motor3->run(FORWARD);
  motor1->run(FOWARD);
  motor2->run(FOWARD);
  delay(1000);
  }
}
