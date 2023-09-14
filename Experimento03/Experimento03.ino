int pinLed = 5;

void setup() {
  pinMode(pinLed,5);
}

void loop() {
  for (int i = 0; i < 30; i++){
    digitalWrite(pinLed,HIGH);
    delay(10 - i/3);
    digitalWrite(pinLed,LOW);
    delay(i/3);
  }

  for (int i = 0; i < 30; i++){
    digitalWrite(pinLed,LOW);
    delay(10 - i/3);
    digitalWrite(pinLed,HIGH);
    delay(i/3);
  }
}
