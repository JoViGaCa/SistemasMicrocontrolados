#include "exibe_disp.h"
// vetor com os caracteres
int displayValue[10][7] = {{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},
                          {0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},
                          {1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
int pinDisplay[7] = {22,23,24,25,26,27,28};
int unidade  = 0;
int dezena = 0;
int count = 0;
int next=0;

#define portUnidade 2
#define portDezena 3


void setup() {
  pinMode(pinDisplay[0],OUTPUT);
  pinMode(pinDisplay[1],OUTPUT);
  pinMode(pinDisplay[2],OUTPUT);
  pinMode(pinDisplay[3],OUTPUT);
  pinMode(pinDisplay[4],OUTPUT);
  pinMode(pinDisplay[5],OUTPUT);
  pinMode(pinDisplay[6],OUTPUT);
  pinMode(portUnidade,OUTPUT);
  pinMode(portDezena,OUTPUT);

}

void loop() {
  next++;
  if(next>45){
    count++;
    next=0;
  }
  if(count>99){
    count=0;
  }
  dezena=count/10;
  unidade=count%10;
  exibeNum(dezena,unidade);

}
