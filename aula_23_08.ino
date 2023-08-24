int i = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("Teste");
  pinMode(13,OUTPUT);

  
}

void loop() {
  Serial.println("Contador1 " + String(i));
  digitalWrite(13,HIGH);
  i++;
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
}
