const int pins[6] = {3,5,6,9,10,11};
int color[3] = {255,255,255};
void setup(){
    for(int i = 0; i < 6; i++){
    pinMode(pins[i], OUTPUT);
  }
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop(){

//  int color[3] = { 255, 255, 255 };

int incomingByte = 0;

 if(Serial.available() > 9){
  incomingByte = Serial.read() - 48;
  if(incomingByte == 3){
    for(int i = 0; i<3;i++){
      color[i] = 100 * (Serial.read()-48);
      color[i] = color[i] + 10 * (Serial.read() - 48);
      color[i] = color[i] + (Serial.read() - 48);
    }
  }
  else if(incomingByte == 1){
     color[0] = random(256);
     color[1] = random(256);
     color[2] = random(256); 
  }
  Serial.print("color chosen : ");
 Serial.print(color[0]);
 Serial.print(" ");
 Serial.print(color[1]);
 Serial.print(" ");
 Serial.println(color[2]);
 Serial.flush();
 }

blinkColor(color);

// for(int i = 0; i < 100; i++){
//  color[0] = random(256);
//  color[1] = random(256);
//  color[2] = random(256);
//  //fadeColor(color);
//  blinkColor(color);
//  delay(50);
//}


//   for(int i=0; i<1000;i++){
//     for(int j=0; j < 3; j++){
//     color[0] = 0;
//     color[1] = 0;
//     color[2] = 0;
//     color[j] = 255;
//     blinkColor(color);
//     delay(50);
//   } 
//}

}
void fadeColor(int color[3]){

  int bright = color[0];
  for(int i = 0; i < 3; i++){
    if(bright > 255)
        bright=255;
    else if(bright < 0)
        bright=0;
     color[i] = bright;
     bright = color[i+1];
   }
   for(int j=0; j < 3; j++){
     for(int b = 0; b <= color[j]; b++){
           analogWrite(pins[j], b);
           analogWrite(pins[j+3], b);   
           delay(25);    
      }
   }
}
void blinkColor(int color[3]){

  int bright = color[0];
  for(int i = 0; i < 3; i++){
    if(bright > 255)
        bright=255;
    else if(bright < 0)
        bright=0;
     color[i] = bright;
     bright = color[i+1];
   }
   for(int j=0; j < 3; j++){
           analogWrite(pins[j], color[j]);
           analogWrite(pins[j+3], color[j]);   
//           delay(25);
   }
}

