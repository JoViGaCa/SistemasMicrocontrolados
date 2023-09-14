int analogPin1 = 5;
int analogPin2 = 6;
int analogPin3 = 7;
int led2 = 0;
int led3 = 0;
int val1 = 0;
int val2 = 0;
int val3 = 0;
int tempo1 = 0;
int tempo2 = 0;
int tempo3 = 0;

void setup() {
  pinMode(analogPin1,OUTPUT);
  pinMode(analogPin2,OUTPUT);
  pinMode(analogPin3,OUTPUT);
  

}

void loop() {
  tempo1++;
  if(led2 == 1){
    tempo2++;
  }
  if(led3 == 1){
    tempo3++;
  }

  if(tempo1 <= 300){
    val1 = map(tempo1, 0, 300, 0, 255);
    if (tempo1 == 200){
      led2 = 1;
    }
  } else if(tempo1 <= 600){
    val1 = map(tempo1, 300, 600, 255, 0); 
    if(tempo1 == 400){
      led3 = 1;
    }
  } else {
    tempo1 = 0;
  }
  
  if(tempo2 <= 300){
    val2 = map(tempo2, 0, 300, 0, 255);
  } else if(tempo2 <= 600){
    val2 = map(tempo2, 300, 600, 255, 0); 
  } else {
    tempo2 = 0;
  }

  if(tempo3 <= 300){
    val3 = map(tempo3, 0, 300, 0, 255);
  } else if(tempo3 <= 600){
    val3 = map(tempo3, 300, 600, 255, 0); 
  } else {
    tempo3 = 0;
  }
  
  
  analogWrite(analogPin1,val1);
  if(led2 == 1){
    analogWrite(analogPin2,val2);
  }
  if(led3 == 1){
    analogWrite(analogPin3,val3);
  }

  delay(1);


}
