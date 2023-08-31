#include <EEPROM.h>
int valueByte = 0;
int addr = 0;
char ch;

void setup() {
  Serial.begin(9600);
  ch = EEPROM.read(addr);
}

void loop() {
  if(Serial.available() > 0){
    ch = Serial.read();
    Serial.print("Eu recebi: ");
    Serial.println(ch);
    EEPROM.write(0,ch);
  }
  Serial.println(ch);
  delay(1000);

}
