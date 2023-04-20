int STARTPIN = 22;
int LEDPIN = 23;

void waitButton(){
  int state = 0;

  found = 1;
  Serial.print("Here\n");  
 while(found != 1){
    state = digitalRead(STARTPIN);
    if(state == HIGH){
      Serial.print("Read as high\n");
      delay(500);
      if(state == HIGH){
        found = 1;        
      }      
    }
  } 
  pinMode(STARTPIN, OUTPUT);
  digitalWrite(LEDPIN, HIGH);
  found = 0;
  while(found == 1){
      state = digitalRead(STARTPIN);
      if(state == LOW){
        Serial.print("Read as low\n");
        delay(500);
        if(state == LOW){
          found = 0;        
        }      
      }
    } 
  
  Serial.print("Got the button Press\n\n\n");
  digitalWrite(LEDPIN, LOW);
}
