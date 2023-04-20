#include <Servo.h>
#include <SoftwareSerial.h>
#include ".\Chip_Dispenser.h"
#include ".\Robotic Arm.h"
#include ".\Start Button.h"
#include ".\Pushing_Mechanism_Test.h"
//#include ".\colorSensor.h"
#include ".\GMSFunctionality.h"
#include ".\Ultra_Sonic_Sensor_2.0.h"
#include ".\Photoresistor.h"

int wall = 15 - 5; // Seems to be a good distance from the wall.


void start(){
  initDisp();
  GMSInit();
  SSsetup(); 
  photoInit();
  
}
//Habitat Chip Firework routine
void HCFRoutine(){
  long xDistance = 0;
  long yDistance = 0;
  //start to habitat 1 and drop chips
  pinMode(STARTPIN, INPUT); 
  Serial.begin(9600);
  start(); 
  photoLoop();  
  forward(10); 
  xDistance = 1.9*(sonarLoop(wall)); //Finding the time it takes to go from start to hab1. Using proportions you can estimate the xdistasnce of field.
  halt(250);
  ninetyRight();
  halt(10);
  openLeft();

  //habitat 1 to habitat 2. drop 2nd disp chips
  halt(500);
  forward(10);
  yDistance = sonarLoop(wall); //Finding the y distance based on how long it takes to go from hab1 to hab2
  ninetyRight();
  halt(10);
  left(750);  
  halt(1000);


  //lower dozer, go from habitat 2 to recycling zone
  reposition(0);
  forward(xDistance);
  halt(10);
  reposition(1);
  halt(1000);

  //back up, move right, go forward to fireworks display  
  backward(xDistance/2);
  halt(10);
  right(yDistance/2);
  halt(10);
  reposition(0);
  forward(xDistance/2);

  //flip fireworks display from off to on
  halt(1000);    
  right(yDistance/4);
  halt(10);  
}


void lawnmower(){
  long xDistance = 0;
  long yDistance = 0;
  long xDozDist = 0;
  long yDozDist = 0;  
  //go from start, to habitat 1 and drop chips
  pinMode(STARTPIN, INPUT); 
  Serial.begin(9600);
  start();
  //photoLoop();
  forward(10); 
  xDistance = 1.9*(sonarLoop(wall)); //Finding the time it takes to go from start to hab1. Using proportions you can estimate the xdistasnce of field.
  halt(250);
  ninetyRight();
  halt(10);
  openLeft();


//go from habitat 1 to habitat 2. drop disp 2 chips
  halt(500);
  forward(10);
  yDistance = sonarLoop(wall); //Finding the y distance based on how long it takes to go from hab1 to hab2
  ninetyRight();
  halt(10);
  //openRight();
  halt(500);


//Calculating xDozDist and yDozDist
xDozDist = 0.9*xDistance ;
yDozDist = 0.9*yDistance ;

//Drop dozer and go to recycling zone
  initPM();
  delay(500);
  reposition(0);
  forward(xDozDist);
  halt(10);
  backward(yDistance/8);
  halt(10);   
  ninetyRight();
  halt(10);
  left(yDistance/8);
  halt(10);
  for(int i = 0; i < 7; i++){
    forward(yDozDist);
    halt(250);
    backward(yDozDist);
    halt(10);
    right(2250);
    halt(10);
  }

  right(2250);  
  halt(10);
  ninetyLeft();    
  halt(10);
  right(yDistance);
  halt(10);  
  forward((xDistance*3)/4);
  halt(10);
  backward(xDistance/2);
  halt(10);
  left(yDistance/2);
  halt(10);
  forward((xDistance*3)/4);
  halt(10);
  right(xDistance/2);
  halt(10);
}

void brayLawn(){
  long xDistance = 0;
  long yDistance = 0;
  long xDozDist = 0;
  long yDozDist = 0;  
  Servo rightDisp;
  
  //go from start, to habitat 1 and drop chips
  pinMode(STARTPIN, INPUT); 
  Serial.begin(9600);
  start();
  photoLoop();
  forward(10); 
  xDistance = 1.9*(sonarLoop(wall)); //Finding the time it takes to go from start to hab1. Using proportions you can estimate the xdistasnce of field.
  halt(250);
  ninetyRight();
  halt(10);
  openLeft();


//go from habitat 1 to habitat 2. drop disp 2 chips
  halt(500);
  forward(10);
  yDistance = sonarLoop(wall); //Finding the y distance based on how long it takes to go from hab1 to hab2
  ninetyRight();
  halt(10);
  //rightDisp.write(20);
 // rightDisp.attach(26);
  openRight();
  halt(500);


//Calculating xDozDist and yDozDist
xDozDist = 0.9*xDistance ;
yDozDist = 0.9*yDistance ;

//Drop dozer and go to recycling zone
  initPM();
  delay(500);
  pushMech(0);
  halt(10);
  left(1000);  
  halt(10);
  forward(xDozDist - (xDistance/16));
  halt(10);
  backward(xDozDist - (xDistance/8));
  halt(10);
  right(yDistance/3);

  
  forward(xDozDist - xDistance/16);
  halt(10);
  ninetyRight();
  halt(10);
  forward((yDozDist)/16);
  halt(10);  
  backward((yDozDist)/16);
  halt(10);
  ninetyLeft();
  backward(xDozDist - xDistance/16);
  right(yDistance/2);
  
//Shift left aand go to second recycling zone
  halt(10);
  forward(xDozDist - xDistance/4);
  halt(10);
  backward(xDozDist - xDistance/4);
  halt(10);
  
  left(yDistance/3);
  forward(xDozDist - xDozDist/4);
  halt(10);
  right(yDistance/3);
  halt(10);  

//
}
Servo tServo;
int testPin = 11;
void setup() {
  long distance = 0;
  start();
  delay(5000);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  brayLawn();
  // initPM();
  // pushMech(0);
  // delay(2000);
 // pushMech(1);  
    
  //pushMech(0);
          
}


void loop() {
  // put your main code here, to run repeatedly:

}
