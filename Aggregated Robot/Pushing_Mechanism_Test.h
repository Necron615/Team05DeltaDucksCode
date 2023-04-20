/*Code Idea:
 * Pushing Mechanism starts in the upright/vertical/true rampition
 * This rampition has the servo in its halt mode (some number 0-180 that makes the speed 0)
 * when the main program asks to set the pushing mechanism downwards/horizontal/false
 * the program then will set a speed and have the motor continue downwards/clockwise 
 * this will end after an arbitrary delay and will be set back to the halt mode
 * this is vice versa for putting the pushing mechanism back upright
 * halt value for test is 75 : halt value for real should be 90
 */


#include <Servo.h>
#include<SoftwareSerial.h>
Servo pmech;

int d =3000;
int Shalt = 85;
int Mhalt  = 1355;
int Mraise = 1390;
int Mlower = 1330;//1410
int raise = 30; // 5
int lower = 40; // 102
bool pPosition = true;
int sPin = 13;

void reposition(bool pPosition){
 
  //Starts at upright rampition and lowers to downwards rampition
    if(pPosition == false){
     //Go();
     pmech.writeMicroseconds(Mlower);
     delay(1000);
     pmech.writeMicroseconds(Mhalt);
  }
  //Starts at pushing position and goes back to raised position
    if(pPosition == true){
     // Go();
      pmech.writeMicroseconds(Mraise);              
      delay(1800); 
      pmech.writeMicroseconds(Mhalt);   
    }
}
//Micro Down Up
void MDU(){
    reposition(false);
    reposition(true);
    pmech.writeMicroseconds(Mhalt);
}

void MUD(){
    reposition(true);
    reposition(false);
    pmech.writeMicroseconds(Mhalt);
}

void initPM() {
  pmech.write(90);
  pmech.attach(sPin);
  delay(100);
  }

void pushMech(int state){
  if(state == 1){
    pmech.writeMicroseconds(1800);
  }
  else if (state == 0){
    pmech.writeMicroseconds(1200); 
    
  }    

  
}