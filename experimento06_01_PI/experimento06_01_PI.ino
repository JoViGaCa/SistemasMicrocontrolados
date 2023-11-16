#include <OneWire.h>
#include <DallasTemperature.h>


#define dados 8
#define led 13
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
float temp = 0, ultimo_temp = 0, erro = 0, temp2 = 0;
int estado = 1;
float Kd = 3, Ki = 6, Kp = 18.5;
float Kp_gain = 0, Kd_gain = 0, Ki_gain = 0;
float erro_anterior = 0, erro_atual = 0, ultima_temp=0;
float real_gain = 0;



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
  if(count >= 100){
    count = 0;
    sensors.requestTemperatures();
    temp2 = sensors.getTempCByIndex(0);
    if(temp2 >= 0){
      temp = temp2;
    }
    erro_atual = 40-temp;
    Kp_gain = Kp*(erro_atual);
    Ki_gain = Ki*(erro_atual+erro_anterior);
    Kd_gain = Kd*(erro_atual-erro_anterior);
    real_gain = Kp_gain + Ki_gain + Kd_gain;
    if(real_gain > 255){
      real_gain = 255;
    }
    erro_anterior = erro_atual;
    ultima_temp=temp;
  }
  Serial.println("Ganho P: " + (String) Kp_gain + " Ganho I: " + (String) Ki_gain + " Ganho D: " + (String) Kd_gain);

  Serial.println("Temperatura: " + (String) temp + " Ganho: " + (String) (real_gain) + "\n");

  dezena = (int)temp/10;
  unidade = (int)temp%10;


}



ISR(TIMER1_OVF_vect){
  TCNT1 = 0xC181;
  count++;
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
  if(real_gain < 0){
    real_gain = 0;
  }
  analogWrite(led, real_gain);
}
