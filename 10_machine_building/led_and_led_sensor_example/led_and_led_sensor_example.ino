void setup() {
  Serial.begin(9600); 
  pinMode(A0, INPUT);                            
}
void loop() {
 int a=analogRead(A0);
 if (a > 100 ){
  Serial.println("No obstacle");
  }
  else {
    Serial.println("Obstacle detected");
    }

  delay(100);                                     
}
