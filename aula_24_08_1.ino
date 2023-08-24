int inPin=7;
int ledPin=13;
int val = 0;

void setup() {
  pinMode(inPin,INPUT);
  pinMode(ledPin,13);

}

void loop() {
  val = digitalRead(inPin);
  digitalWrite(ledPin);

}
