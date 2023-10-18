unsigned long time_past = 0;
int led_pin = 11;


void setup() {
  Serial.begin(115200);
  pinMode(led_pin,OUTPUT);
}

void loop() {
  time_past = millis();
  digitalWrite(led_pin,HIGH);
  while((millis()-time_past) < 300){}
  digitalWrite(led_pin,LOW);
  while((millis()-time_past) < 600){}

}
