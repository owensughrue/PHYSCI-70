// Thank you to the teaching staff of PS70 for providing the foundations of this code!
// I changed numbersto fit the motor and my structure, but the bulk of this code comes from our class website.

const int A1A = 3;  // define pin 3 for A-1A (PWM Speed)
const int A1B = 4;  // define pin 4 for A-1B (direction)

void setup() {
  pinMode(A1A, OUTPUT);     // specify these pins as outputs
  pinMode(A1B, OUTPUT);
  analogWrite(A1A, 0);   // start with the motors off 
  digitalWrite(A1B, LOW);
}

void loop() {
  // start the motor at a low speed
  analogWrite(A1A, 255);   
  digitalWrite(A1B, LOW);
  delay(4000);              // allow the motor to run for 4 seconds

  // stop the motor
  analogWrite(A1A, 0);   // setting both pins LOW stops the motor
  delay(1500);              // keep the motor off for 2 seconds

  // start the motor at a low speed in the other direction
  analogWrite(A1A, 0);   
  digitalWrite(A1B, HIGH);
  delay(4000);              // allow the motor to run for 4 seconds

  // stop the motor
  analogWrite(A1A, 0);   // setting both pins LOW stops the motor
  digitalWrite(A1B, LOW);
  delay(1500);              // keep the motor off for 2 seconds

}
