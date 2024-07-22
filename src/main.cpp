#include <Arduino.h>
#include <Stepper.h>

// put function declarations here:
int powerState = 0;
int changePowerState = 0;
const int powerPin = 2;
const int stepPerRevolution = 2048;

void setup() {
  // put your setup code here, to run once:
  pinMode(powerPin, INPUT);
  Serial.begin(9600);
} 

void loop() {
  // put your main code here, to run repeatedly:
  changePowerState = digitalRead(powerPin);

  if (changePowerState == HIGH) {
    Serial.println(changePowerState);

  }
  else {
    Serial.println(changePowerState);
  }

  delay(1000);
}

// put function definitions here:
int motorStart {
  
}