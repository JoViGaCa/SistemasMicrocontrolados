#define ledPin 11
int count = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1<<CS10);
  TCNT1 = 0xC181;
  TIMSK1 |= (1 << TOIE1);

}

void loop() {
  if (count==999){
    count=0;
    Serial.println(millis());  
    digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
  }
}

ISR(TIMER1_OVF_vect){
  TCNT1 = 0xC181;
  count++;

}
