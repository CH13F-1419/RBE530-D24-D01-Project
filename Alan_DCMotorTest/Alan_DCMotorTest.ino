#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Connect two motors with the following terminals
Adafruit_DCMotor *motor1 = AFMS.getMotor(1); // Motor connected to M1
Adafruit_DCMotor *motor2 = AFMS.getMotor(2); // Motor connected to M2

const int buttonPin = 2;  // the number of the pushbutton pin
int buttonState = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // Create with the default frequency 1.6KHz
  motor1->setSpeed(150);  // Set the speed to 150/255
  motor2->setSpeed(150);  // Set the speed to 150/255
 pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
  Serial.println("Forward!");
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  delay(1000);
  }
  else {
  Serial.println("Backward!");
  motor1->run(BACKWARD);
  motor2->run(BACKWARD);
  delay(1000);
  }
  Serial.println("Release");
  motor1->run(RELEASE);
  motor2->run(RELEASE);
  delay(1000);
}
