#include <Servo.h>

int PHOTOPIN = A0;

void photoInit() {
  // put your setup code here, to run once:
  pinMode(PHOTOPIN, INPUT);
  Serial.begin(9600);
}

void photoLoop() {
  int light;
  int done = 0;
  // put your main code here, to run repeatedly:
  while(done == 0){
    Serial.print("Photo output: ");
    light = analogRead(PHOTOPIN);
    Serial.println(light);
    delay(100);
    if(light > 400){
      light = analogRead(PHOTOPIN);
      if(light > 400){
        done = 1;
      }

    }
  }
}
