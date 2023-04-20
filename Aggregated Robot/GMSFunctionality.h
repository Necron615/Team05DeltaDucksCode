#include <Servo.h>
//back left for some reason behaves the opposite of others (ccw is cw and vice versa)
Servo frontRight;
Servo frontLeft;
Servo backRight;
Servo backLeft;

//Motor pin numbers
int frpin = 3;
int flpin = 4;
int brpin = 5;
int blpin = 6;

//Halting constants for different motors. In using old servos, they are not accurate to original spec for PWM values. These constants offset this.
int frStop = 90; //front right
int flStop = 90;// front left 
int brStop = 90;// back right
int blStop = 90;// back left 0 = ccw, 180 = cw 

//Constants for the motors to move completely clockwise and counterclockwise at maximum power
int cw = 180;
int ccw = 0;

//Tests the quality of each servo motor
void testServo(){
  delay(3000);

  frontRight.write(89);
  frontLeft.write(80);
  backLeft.write(58);
  backRight.write(74);


  delay(2000);

  frontRight.write(180);
  frontLeft.write(180);
  backLeft.write(180);
  backRight.write(180);
  delay(2000);

  frontRight.write(89);
  frontLeft.write(80);
  backLeft.write(58);
  backRight.write(74);
}

//Halts all servo motors
void halt(int runtime){
  frontRight.write(frStop);
  backRight.write(brStop);
  frontLeft.write(flStop);
  backLeft.write(blStop);
  delay(runtime);
}

//Robot moves in forward direction
void backward(int runtime){
  frontRight.write(172);
  backRight.write(170);
  frontLeft.write(20);
  backLeft.write(0);
  delay(runtime);
}

//Robot moves in backward direction
void forward(int runtime){
  frontRight.write(15); //orig 8
  backRight.write(17); //orig 10
  frontLeft.write(173); //orig 180
  backLeft.write(180);
  delay(runtime);
}

//Robot shifts horizontally right
void left(int runtime){
  frontRight.write(ccw);
  backRight.write(cw);
  frontLeft.write(ccw);
  backLeft.write(cw);
  delay(runtime);
}

//Robot shifts horizontally left
void right(int runtime){
  frontRight.write(cw);
  backRight.write(ccw);
  frontLeft.write(cw);
  backLeft.write(ccw);
  delay(runtime);
}

//Robot rotates right (clockwise direction)
void rotLeft(int runtime){
  //about 4 seconds to fully rotate 90 degreees
  frontRight.write(ccw);
  backRight.write(ccw);
  frontLeft.write(ccw);
  backLeft.write(ccw);
  delay(runtime);
}

//Robot rotates left (counterclockwise direction)
void rotRight(int runtime){
  frontRight.write(cw);
  backRight.write(cw);
  frontLeft.write(cw);
  backLeft.write(cw);
  delay(runtime);
}

//Ninety degree turn right
void ninetyRight(){
  frontRight.write(cw);
  backRight.write(cw);
  frontLeft.write(cw);
  backLeft.write(cw);
  delay(2565); //2425
}

//Ninety degree turn left
void ninetyLeft(){
  frontRight.write(ccw);
  backRight.write(ccw);
  frontLeft.write(ccw);
  backLeft.write(ccw);
  delay(2565);//2425
}


//Robot moves diagonally to the right (forward and right)
void diagLeft(int runtime){
  frontRight.write(cw);
  backLeft.write(cw);
  delay(runtime);
}

//Robot moves diagonally to the left (forward and left)
void diagRight(int runtime){
  frontLeft.write(cw);
  backRight.write(cw);
  delay(runtime);
}

//Test the 6 different motions of the robot. Moves forwards and backwards, right and left, rotates right then rotates left
void testMovement(){
  halt(5000);  
  forward(4000);
  halt(1000);
  backward(4000);
  halt(1000);
  right(4000);
  halt(1000);
  left(4000);
  halt(1000);
  rotRight(1900);
  halt(1000);
  rotLeft(1900);
  halt(1000);
}

//Completes a square shape without rotation. Tests the 4 directions
void testSquare(){
  halt(5000);
  forward(4000);
  halt(500);
  right(4000);
  halt(500);
  backward(4000);
  halt(500);    
  left(4000);
  halt(1000);  
}

//Tests the rotation ability of the robot by completing a square in both directions 2350 is a 90 degree turn
void testNASCAR(){
  //Tests the right rotation ability of the robot
  halt(5000);
  forward(4000);
  halt(500);
  rotRight(2350);
  halt(500);
  forward(4000);
  halt(500);
  rotRight(2350);
  halt(500);
  forward(4000);
  halt(500);
  rotRight(2350);
  halt(500);
  forward(4000);
  halt(500);
  rotRight(2350);
  halt(500);
  rotRight(2350);
  halt(500);

  //Tests the left rotation ability of the robot
  forward(4000);
  halt(500);
  rotLeft(4000);
  halt(500);
  forward(4000);
  halt(500);
  rotLeft(4000);
  halt(500);
  forward(4000);
  halt(500);
  rotLeft(4000);
  halt(500);
  forward(4000);
  halt(500);
  rotLeft(4000);
  halt(500);
  rotLeft(4000);
  halt(500);  
}

void deliverChips(){
  halt(5000);
  forward(500);
  left(7100);
  halt(2000);
  forward(5800);  
  halt(100);
  rotRight(2950);
  halt(2000);
  forward(12000);
}

void cleanup(){
  rotRight(5900);
  halt(2000);
  forward(12000);
  rotLeft(5900);
  halt(2000);
  forward(12000);
  rotRight(5900);
  halt(2000);
  forward(12000);
  halt(10000);
}


//Assigns the PWN pins on the Arduino Mega
void GMSInit() {
  frontRight.attach(frpin);
  backRight.attach(brpin);
  frontLeft.attach(flpin);
  backLeft.attach(blpin);
}
