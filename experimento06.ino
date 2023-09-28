#include <OneWire.h>
#include <DallasTemperature.h>


#define dados 8
#define led 11
#define alarme 30
OneWire oneWire(dados);

DallasTemperature sensors(&oneWire);



void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  Serial.println("Demonstração do funcionamento do sensor");
  sensors.begin();
}

void loop() {
  Serial.println("Requerimento de temperatura ...");
  sensors.requestTemperatures();
  Serial.println("Pronto");


  Serial.print("A sua temperatura é: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print("\n");
  if (sensors.getTempCByIndex(0) > alarme) {
    digitalWrite(led,HIGH);
  } else {
    digitalWrite(led,LOW);
  }
  delay(100);

}
