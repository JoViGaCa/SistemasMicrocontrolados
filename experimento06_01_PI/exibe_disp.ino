void exibeNum(int dezena, int unidade){  
  for(int i = 0; i < 7; i++){
   digitalWrite(pinDisplay[i],displayValue[unidade][i]); 
  }
  // para acionar a dezena e a unidade tem, que alternar o acionamento do catodo
  digitalWrite(portUnidade,LOW);
  digitalWrite(portDezena,HIGH);
  delay(15);

  for(int i = 0; i < 7; i++){
   digitalWrite(pinDisplay[i],displayValue[dezena][i]); 
  }
  digitalWrite(portUnidade,HIGH);
  digitalWrite(portDezena,LOW);
  delay(1);
}

void exibeUnidade(int unidade){
  for(int i = 0; i < 7; i++){
   digitalWrite(pinDisplay[i],displayValue[unidade][i]); 
  }
  // para acionar a dezena e a unidade tem, que alternar o acionamento do catodo
  digitalWrite(portUnidade,LOW);
  digitalWrite(portDezena,HIGH);
}

void exibeDezena(int dezena){
  for(int i = 0; i < 7; i++){
   digitalWrite(pinDisplay[i],displayValue[dezena][i]); 
  }
  // para acionar a dezena e a unidade tem, que alternar o acionamento do catodo
  digitalWrite(portUnidade,HIGH);
  digitalWrite(portDezena,LOW);
}
