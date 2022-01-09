int cutoff=70; // Set Engine Cutoff time (If you're using relay, do not set timing under 40ms)
int dly=500;       // Set Delay time before next Upshift
int i=0;

void setup() {
  pinMode(2, INPUT_PULLUP);   // Sensor pin
  pinMode(5, OUTPUT);         // Relay Pin
  pinMode(8, OUTPUT);         // Relay2 Pin
  digitalWrite(5, LOW);      // Set Relay on Low State
  digitalWrite(8, LOW);      // Set Relay2 on Low State

}

void loop() {
  int snsrstate=digitalRead(2);
  if (snsrstate==LOW && i==0) {
    i+=1;
    digitalWrite(5, HIGH);
    digitalWrite(8, HIGH);
    delay(cutoff);
    digitalWrite(5, LOW);
    digitalWrite(8, LOW);
    delay(dly);
  }
  if (snsrstate==HIGH) {
    i=0;
    //delay(10);
  }
}
