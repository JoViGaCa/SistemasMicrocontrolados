void setup() {
  
    DDRE = B11111110; // Set arduino pin 1 to 7 as output and 0 as input
    // ou (or) digital, bit a bit, 
    DDRE = DDRE | B11111100; // Mais seguro, pin 0 e 1 são RX e TX
    DDRE |= B11111100;
    DDRB = B10000000;
    DDRB |= B10000000;
    // outra forma mais simples: pinMode(número da porta na placa, modo OUTPUT ou INPUT);
}

void loop() {
    // modo mais simples digitalWrite(Número da porta na placa, valor HIGH ou LOW)
    // ou (or) digital
    PORTE |= B00010000; // set pin D2 to HIGH
    PORTB &= B01111111;
    delay(1000);
    // e (and) digital
    PORTE &= B11101111; // set pin D2 to low
    PORTB |= B10000000;
    delay(1000);
}
