#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Connect two motors with the following terminals
Adafruit_DCMotor *motor1 = AFMS.getMotor(1); // Left Motor connected to M1
Adafruit_DCMotor *motor2 = AFMS.getMotor(2); // Right Motor connected to M2
// Adafruit_DCMotor *motor3 = AFMS.getMotor(3); // Size adjuster Motor connected to M3

const int buttonLeft = 2;  // the number of the pushbutton pin
// const int buttonRight = 3;  // the number of the pushbutton pin
int buttonLeftState = 0;
// int buttonLeftState = 0;

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
  if (buttonLeftState == HIGH) {
    Serial.println("driving foward");
    motor1->run(FORWARD);
    motor2->run(FORWARD);
  }
  else {
    Serial.println("No Moter Movement");
    motor1->run(RELEASE);
    motor2->run(RELEASE);
    delay(1000);
  }
}
