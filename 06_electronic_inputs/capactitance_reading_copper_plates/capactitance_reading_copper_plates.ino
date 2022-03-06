// Thank you to https://roberthart56.github.io/SCFAB/SC_lab/Sensors/tx_rx_sensors/rx_tx03.txt
// The above site supplied the code to me, and originally came from Robert Hart—thank you to him!
// Also, thank you very much to Gabby Perry for explaining this code and this circuit to me!

//tx_rx03  Robert Hart Mar 2019.
//  Program to use transmit-receive across space between two conductors.
//  One conductor attached to digital pin, another to analog pin.
//
//  This program has a function "tx_rx() which returns the value in a long integer.
//
//  Optionally, two resistors (1 MOhm or greater) can be placed between 5V and GND, with
//  the signal connected between them so that the steady-state voltage is 2.5 Volts.
//
//  Signal varies with electric field coupling between conductors, and can
//  be used to measure many things related to position, overlap, and intervening material
//  between the two conductors.
//


long result;   //variable for the result of the tx_rx measurement.
int analog_pin = A3;
int tx_pin = A1;
void setup() {
pinMode(tx_pin,OUTPUT);      //Pin 4 provides the voltage step
Serial.begin(9600);
}


long tx_rx(){         //Function to execute rx_tx algorithm and return a value
                      //that depends on coupling of two electrodes.
                      //Value returned is a long integer.
  int read_high;
  int read_low;
  int diff;
  long int sum;
  int N_samples = 100;    //Number of samples to take.  Larger number slows it down, but reduces scatter.

  sum = 0;

  for (int i = 0; i < N_samples; i++){
   digitalWrite(tx_pin,HIGH);              //Step the voltage high on conductor 1.
   read_high = analogRead(analog_pin);        //Measure response of conductor 2.
   delayMicroseconds(100);            //Delay to reach steady state.
   digitalWrite(tx_pin,LOW);               //Step the voltage to zero on conductor 1.
   read_low = analogRead(analog_pin);         //Measure response of conductor 2.
   diff = read_high - read_low;       //desired answer is the difference between high and low.
 sum += diff;                       //Sums up N_samples of these measurements.
 }
  return sum;
}                         //End of tx_rx function.


void loop() {

result = tx_rx();
Serial.println(result);
//delay(100);



}
