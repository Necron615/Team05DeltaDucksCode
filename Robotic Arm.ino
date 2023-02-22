#include <Servo.h>
Servo base, shoulder, elbow, wrist, pivot, claw;

//Claw open/close numbers
int COPEN = 120;
int CCLOSE = 162;

//Grabbing Duck 
int CDCLOSE = 160;
//upright pillar
int CPCLOSE = 170;

//Port numbers for each servo
int SBASE = 22;
int SSHOULDER = 23;
int SELBOW = 24;
int SWRIST = 25;
int SPIVOT = 26;
int SCLAW = 27;
 
//Degree Numbers for the direction the arm is facing
int NORTH = 180;
int NORTHEAST = 135;
int EAST = 90;
int SOUTHEAST = 45;
int SOUTH = 0;
 
//Important Notes for how servos move. 
//1.0-2.0 ms (0-180 degrees)
//Elbow: bigger number means it extends, smaller contracts

//Function that will be used to convert seconds to degrees, so its easier to code later. Want to utilize the hardware PWMs with this.
float secToDeg(){
return 5.0;
  
}

 //Ease function. Smooths out the motion of the claw. Need to make a member function of the struct later. Name suggested by Cameron
void ease(int start, int stop){
  int temp, i;
  temp = abs(start-stop);
  if(start > stop){
    for(i = 0; i < temp; i++){
      claw.write(start-(i*1));
      delay(5); //17 is what was used earlier and it seems kinda good.
    }
  }
  else if (start < stop){
    for(i = 0; i < temp; i++){
      claw.write(start+(i*1));
      delay(17); //17 is what was used earlier and it seems kinda good.
    }    
  }
} 

 
void initArm(){
  //Default position for each servo
  delay(5000); // 5 second delay so i can start recording
  claw.write(90);
  pivot.write(38);
  wrist.write(180); //0 is poiting upwards. 180 is pointing down.
  elbow.write(45);
  shoulder.write(90);
  base.write(180);

  //Attaching all servos to their respective pins
  base.attach(SBASE);
  delay(500);
  shoulder.attach(SSHOULDER);
  delay(500);
  elbow.attach(SELBOW);
  delay(500);
  wrist.attach(SWRIST);
  delay(500);
  pivot.attach(SPIVOT);
  delay(500);
  claw.attach(SCLAW);
  delay(500);
}
//Slowly lowers the arm until its about level. Input 0 for not stacking pillar, otherwise 1 = mid, 2 = top, 3 = duck
//Currently only meant to be used to pick up and stack
void slowFall(int stack){
  //slowly lowers the arm so it doesnt slam into the ground.
  if(stack == 0){
    for(int i = 0; i < 30; i++){
     shoulder.write(80-(i*1));
     delay(17); //round(500/30) = 17 
    }
    shoulder.write(45);//45 is good
  }
  else if (stack == 1){
   // elbow.write(105); //Need to change elbow since the higher it is, the more horizontal distance it needs to place pillar
    for(int i = 0; i < 14; i++){
     shoulder.write(80-(i*1));
     delay(17);    
    }
  }
  //Need to change for top and duck
  else if (stack == 2){
    for(int i = 0; i < 13; i++){
     shoulder.write(80-(i*1));
     delay(17);      
    }
  }
  else if (stack == 3){
    for(int i = 0; i < 3; i++){
     shoulder.write(80-(i*5));
     delay(500);  
    }      

  }
  else {
    return;
  }
}

//Takes an input that is the rotational deg that the claw needs to pick up the object.
// Then the arm goes to the location, closes claw, and lifts object up.
//Need to lower base more, raise elbow and lower wrist
void pickUp(int objDeg){
  // Code to grab a duck about a foot away from the base.
  claw.write(COPEN); //25 is fully open, 90 is fully closed for aluminum claw.

  // delay(1000);
  // pivot.write(180); //38 degrees is roughly a flat, leveled position for the claw.
  // delay(1000);
  wrist.write(100);
  delay(500);
  elbow.write(100); // 90 is good
  delay(500);
  slowFall(0);
  delay(500);    
  //end code for grabbing a duck a foot away from base.
  claw.write(objDeg);
  delay(500);

  //Lifting the duck into the air (default position)
  pivot.write(38);
  delay(500);
  wrist.write(180);
  delay(500);
  shoulder.write(90);
  delay(500);
  elbow.write(45);
  delay(500); 
}

//Takes in the parameter that specifies which part of the pillar it is building.
//0 Means base, 1 means middle, 2 means top, 3 means duck
void pillarStack(int posNum){
  // Code to grab a duck about a foot away from the base.
  delay(500); 
  shoulder.write(100);
  // delay(1000);
  // pivot.write(180); //38 degrees is roughly a flat, leveled position for the claw.
  // delay(1000);
  if(posNum > 1){
   elbow.write(118);
   delay(500);
   wrist.write(73);
  }  
  else{
    wrist.write(100);
    delay(500);
    elbow.write(80); // 90 is good
}
  delay(500);
  slowFall(posNum);
  delay(500);
  ease(CPCLOSE, COPEN);
  delay(500);
}

//Sets the arm to go to a default position facing the rotatioanl degree specified by the parameter.
// Note this does nothing to the claw. The claw must be sent a signal manually.
void positionDefault(int baseDeg){
  pivot.write(38);
  delay(500);
  wrist.write(180); //0 is pointing upwards. 180 is pointing down.
  delay(500);
  elbow.write(45);
  delay(500);
  shoulder.write(90);
  delay(500);
  base.write(baseDeg);
}

void setup() {
  int stack = 0;
  initArm();
  delay(1000);
  positionDefault(EAST);
  delay(1000);
  pickUp(CPCLOSE);
  delay(1000);
  positionDefault(NORTH);
  delay(500);
  pillarStack(stack);
  stack++;
  delay(500);
  positionDefault(NORTH);
  delay(500);
  positionDefault(NORTHEAST);
  delay(500);
  pickUp(CPCLOSE);
  delay(500);
  positionDefault(NORTH);
  delay(500);
  pillarStack(stack);
  stack++;
  delay(500);
  positionDefault(SOUTHEAST);
  delay(500);
  pickUp(CPCLOSE);
  delay(500);
  positionDefault(NORTH);
  delay(500);
  pillarStack(stack);
  delay(500);
  positionDefault(NORTH);
  delay(500);  
}

void loop() {
  // put your main code here, to run repeatedly:

}
