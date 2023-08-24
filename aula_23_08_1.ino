
float a= 0, b = 0, c = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Seno1:");
  Serial.print(5*sin(a/10));
  Serial.print(",Seno2:");
  Serial.print(5*sin(b/5 -3.14/4));
  Serial.print(",Seno3:");
  Serial.println(5*sin(c/20 - 3.14/2));
  c++;
  b++;
  a++;
  delay(50);


}
