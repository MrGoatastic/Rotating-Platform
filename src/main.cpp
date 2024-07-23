// Library Include List
#include <Arduino.h>
#include <Stepper.h>

// Variables déclaration
const int stepPerRevolution = 2048;        // # of Step for Full 360 rotation in Full Step mode. Change value for 4096 for half-step mode
const int switchPin = 2;                   // ON OFF Switch
bool activationState = LOW;                // Track if the motor is running or not.
int switchPress = LOW;                     // Track if the button is press

Stepper platformMotor = Stepper(stepPerRevolution, 8, 9, 10, 11);   //function Stepper(steps, pin1, pin2, pin3, pin4)

void setup() {
//Initialization of the configuration on boot
  pinMode(switchPin, INPUT);               // Set "read" mode on the activation button
  platformMotor.setSpeed(0);               // Set the Speed of the stepper (The maximum speed for a 28byj-48 stepper motor is roughly 10-15 rpm at 5 V.)
  Serial.begin(9600);                      // Begin Serial communication at a baud rate of 9600:
  Serial.println("The program is starting");                  
}

void loop() {
// Program running in loop
  switchPress = digitalRead(switchPin);   // Read the switch PIN to know if it has been press

  if (switchPress == HIGH) {
    activationState = !activationState;
  }

  if (activationState == LOW) {
    platformMotor.setSpeed(0);            // Set the Speed of the stepper (The maximum speed for a 28byj-48 stepper motor is roughly 10-15 rpm at 5 V.)
  } else {
    platformMotor.setSpeed(5);            // Set the Speed of the stepper (The maximum speed for a 28byj-48 stepper motor is roughly 10-15 rpm at 5 V.)
  }
  
  platformMotor.step(stepPerRevolution);  // Turn the motor in  clockwise for a full rotation
  delay(500);
  
  platformMotor.step(-stepPerRevolution); // Turn the motor in counterclockwise for a full rotation
  delay(500);
}

// put function definitions here