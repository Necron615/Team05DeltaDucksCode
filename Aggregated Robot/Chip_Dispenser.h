#include <Servo.h>
//Chip Dispenser Constants

int LCDPIN = 22;
int RCDPIN = 30; //used to be 25
Servo leftDisp, rightDisp;

void initDisp(){
  leftDisp.write(0);
  rightDisp.write(170);
  delay(100);
  leftDisp.attach(LCDPIN);
  rightDisp.attach(RCDPIN);
}

void openLeft(){
  leftDisp.write(150);
}

void openRight(){
  rightDisp.write(20);
}

void closeLeft(){
  leftDisp.write(0);
}

void closeRight(){
  rightDisp.write(170);
}