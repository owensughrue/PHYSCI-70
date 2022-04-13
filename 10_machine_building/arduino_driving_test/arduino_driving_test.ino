# include <AccelStepper.h>

const int stepPin = 13;   // blue
const int dirPin = 12;   // orange

// Define a stepper and the pins it will use
AccelStepper stepper(1, stepPin, dirPin);  // initialize accelstepper for a two wire board

int pos = 0;

void setup() {
  pinMode(A0, INPUT);
  stepper.setMaxSpeed(100);
  stepper.setAcceleration(300);
  home_motor();
}

void loop() {
  while (analogRead(A0) > 900) {
    pos += 1;
    stepper.run();
    stepper.moveTo(pos);
  }
}
