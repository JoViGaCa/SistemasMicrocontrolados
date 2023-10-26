#include <OneWire.h>
#include <DallasTemperature.h>


#define dados 8
#define led 11
#define alarme 40
#include "exibe_disp.h"
#define portUnidade 2
#define portDezena 3

// vetor com os caracteres
int displayValue[10][7] = {{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},
                          {0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},
                          {1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
int pinDisplay[7] = {22,23,24,25,26,27,28};
int unidade  = 0;
int dezena = 0;
int count = 0;
int next=0;
int analogPin = A1;
float temp = 0, ultimo_temp = 0, erro = 0;
int estado = 1;
float Kd = 0, Ki = 0, Kp = 12;
float Kp_gain = 0, Kd_gain = 0, Ki_gain = 0; 


OneWire oneWire(dados);

DallasTemperature sensors(&oneWire);



void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  Serial.println("Demonstração do funcionamento do sensor");
  sensors.begin();
  pinMode(pinDisplay[0],OUTPUT);
  pinMode(pinDisplay[1],OUTPUT);
  pinMode(pinDisplay[2],OUTPUT);
  pinMode(pinDisplay[3],OUTPUT);
  pinMode(pinDisplay[4],OUTPUT);
  pinMode(pinDisplay[5],OUTPUT);
  pinMode(pinDisplay[6],OUTPUT);
  pinMode(portUnidade,OUTPUT);
  pinMode(portDezena,OUTPUT);
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1<<CS10);
  TCNT1 = 0xC181;
  TIMSK1 |= (1 << TOIE1);
  sensors.requestTemperatures();
  ultimo_temp = sensors.getTempCByIndex(0);
  
}

void loop() {
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);
  if(temp < 0){
    temp = ultimo_temp;
  }
  Kp_gain = Kp*(40-temp);
  Ki_gain = Ki*(temp-ultimo_temp);
  Serial.println("Temperatura: " + (String) temp + " Ganho: " + (String) Kp_gain + "\n");
  

  //digitalWrite(led,HIGH);
  //analogWrite(led,(Kp_gain + Ki_gain));
  analogWrite(led,Kp_gain);

  ultimo_temp = temp;

  dezena = (int)temp/10;
  unidade = (int)temp%10;


}



ISR(TIMER1_OVF_vect){
  TCNT1 = 0xC181;
  switch(estado){
    case 1:
      exibeUnidade(unidade);
      estado = 2;
      break;
    case 2:
      exibeDezena(dezena);
      estado = 1;
      break;
  }
}
