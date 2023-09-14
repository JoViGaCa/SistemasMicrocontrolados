int analogPin = 5;
int readPin = A1;
int val = 0;

void setup() {
  pinMode(analogPin,OUTPUT);
  pinMode(readPin,INPUT);

}

void loop() {
    val = analogRead(readPin);
    analogWrite(analogPin,val);

}
