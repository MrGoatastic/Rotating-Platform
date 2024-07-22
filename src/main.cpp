// github link test

#include <Arduino.h>
#include <Stepper.h>

int powerState = 0;                   // ON OFF tracking
int changePowerState = 0;             // Variable of the power button
int rolePerMinute = 7;               // Adjustable range of 28BYJ-48 stepper is 0~17 rpm
const int powerPin = 2;               // ON OFF Switch
const int stepPerRevolution = 4096;

Stepper myStepper = Stepper(stepPerRevolution, 8, 9, 10, 11);

void setup() {
  pinMode(powerPin, INPUT);
  Serial.begin(9600);
} 

void loop() {
  changePowerState = digitalRead(powerPin);

  if (changePowerState == HIGH) {
    Serial.println(changePowerState + powerState);
    if (powerState = 0) {
      motorStart();
    }
    else {
      motorStop();
    }
  }
  else {
    Serial.println(changePowerState + powerState);
  }

  delay(250);
}

// put function definitions here:
int motorStart() {
  powerState = 1;
  myStepper.setSpeed(rolePerMinute);
}

int motorStop() {
  powerState = 0;
  myStepper.setSpeed(0);
}