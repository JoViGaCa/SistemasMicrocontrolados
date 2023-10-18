unsigned long time_past = 0;
int led_pin = 11;
int segundos = 0, minutos = 0;


void setup() {
  Serial.begin(115200);
  pinMode(led_pin,OUTPUT);
  time_past = millis();
}

void loop() {
  if(millis() - time_past >= 1000){
    segundos++;
    if(segundos == 60){
      minutos++;
      segundos = 0;
    }
     Serial.println(String(minutos) + ":" + String(segundos));
     time_past = millis();
  }

}
