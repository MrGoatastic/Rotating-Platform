// Library Include List
#include <Arduino.h>
#include <Stepper.h>

// Variables declaration
const int stepPerRevolution = 2048;        // # of Step for Full 360 rotation in Full Step mode. Change value for 4096 for half-step mode
const int switchPin = 2;                   // ON OFF Switch
bool activationState = LOW;                // Track if the motor is running or not.
int switchPress = LOW;                     // Track if the button is press
int lastSwitchReading = LOW;                 // Record last reading of the switchPin
unsigned long lastDebounceTime = 0;        
unsigned long debounceDelay = 50;

Stepper platformMotor = Stepper(stepPerRevolution, 8, 9, 10, 11);   //function Stepper(steps, pin1, pin2, pin3, pin4)

//Initialization of the configuration on boot
void setup() {
  pinMode(switchPin, INPUT);               // Set "read" mode on the activation button
  platformMotor.setSpeed(1);               // Set the Speed of the stepper (The maximum speed for a 28byj-48 stepper motor is roughly 10-15 rpm at 5 V.)
  Serial.begin(9600);                      // Begin Serial communication at a baud rate of 9600:
  Serial.println("The program is starting");                  
}

// Program running in loop
void loop() {
  // Read the switch PIN to know if it has been press
  int reading = digitalRead(switchPin);   

  // Make sure switch has been press by debouncing
  if (reading != lastSwitchReading) {
    lastDebounceTime = millis();
  }

  // Change activationState
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != switchPress) {
      switchPress = reading;
      if (switchPress == HIGH) {
        activationState = !activationState;
        Serial.println("Switch pressed");
        delay(1000);
      }
    }
  }

  // Change the Record of the last reading for next debouncing
  lastSwitchReading = reading;
  
  // Rotate the Platform by looking at the tracker 
  if (activationState == HIGH) {
    Serial.println("Rotating the platform");
    platformMotor.step(10);
  } else {
    Serial.println("Motor stopped");
  }
}

// Put function definitions here