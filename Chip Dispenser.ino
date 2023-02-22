#include <Servo.h>

Servo leftDisp, rightDisp;

int LCDPIN = 28;
int RCDPIN = 29;

void initDisp(){
leftDisp.write(0);
rightDisp.write(0);

leftDisp.attach(LCDPIN);
rightDisp.attach(RCDPIN);
}

void openLeft(){
  leftDisp.write(180);
}

void openRight(){
  rightDisp.write(180);
}

void closeLeft(){
  leftDisp.write(0);
}

void closeRight(){
  rightDisp.write(0);
}


void setup() {
  // put your setup code here, to run once:
  initDisp();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  openLeft();
  delay(500);
  openRight();
  delay(500);
  closeLeft();
  delay(500);
  closeRight();
}
