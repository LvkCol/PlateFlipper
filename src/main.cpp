#include <Arduino.h>
#include <Stepper.h>

// Define number of steps per rotation for your stepper motor
const int stepsPerRevolution = 2048;

// Initialize stepper motors on pins 7-10
Stepper myStepper1(stepsPerRevolution, 7, 9, 8, 10);

// Define switch pin
const int buttonPin = 13;

int currentPosition = 0; // Variable to keep track of the motor's position
bool isPressed = false; // Variable to check if the button is pressed or not

void setup() {
  // Set up stepper motors:
  myStepper1.setSpeed(9); // You can adjust this speed as needed


  // Set up button pin:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonPin) == LOW && !isPressed) {
    isPressed = true;
    if (currentPosition == 0) {
      // Move set amount clockwise
      myStepper1.step(stepsPerRevolution / 3);
      currentPosition = 1;
    } else if (currentPosition == 1) {
      // Move back to original position 
      myStepper1.step(-stepsPerRevolution / 3);
      currentPosition = 0;
    }
  } else if (digitalRead(buttonPin) == HIGH && isPressed) {
    isPressed = false;
  }
}