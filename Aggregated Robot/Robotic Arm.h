 
//Important Notes for how servos move. 
//1.0-2.0 ms (0-180 degrees)
//Elbow: bigger number means it extends, smaller contracts

//Robotic Arm
Servo base, shoulder, elbow, wrist, pivot, claw;

//Converting deg to uS
long MINUSRANGE = 500;
long MAXUSRANGE = 2400;
long MIDUSRANGE = MAXUSRANGE-MINUSRANGE;
long USINC = MIDUSRANGE/180;

//Claw open/close numbers
long COPEN = 750;
long CCLOSE = 1300;

//Grabbing Duck 
long CDCLOSE = 1250;
//upright pillar
long CPCLOSE = 1200;

//Port numbers for each servo
long SBASE = 8;
long SSHOULDER = 9;
long SELBOW = 10;
long SWRIST = 11;
long SPIVOT = 12;
long SCLAW = 13;
 
//Degree Numbers for the direction the arm is facing
long NORTH = 2400; //2400 for micro
long NORTHEAST = 1925;
long EAST = 2000;
long SOUTHEAST = 975;
long SOUTH = 500;
 

void easeClaw(long start, long stop);
void easePivot(long start, long stop);
void easeWrist(long start, long stop);
void easeElbow(long start, long stop);
void easeShoulder(long start, long stop);
void easeBase(long start, long stop);

//Function takes in a new deg, converst it to uS, reads in current deg in uS, and performs ease function
void dtsClaw(long newUS){
  long tempRead = 0;
  tempRead = claw.read();
  tempRead = round(((tempRead*MIDUSRANGE)/180) + 500);
  easeClaw(tempRead, newUS); //100
}

void dtsPivot(long newUS){
  long tempRead = 0;
  tempRead = pivot.read(); 
  tempRead = round(((tempRead*MIDUSRANGE)/180) + 500);
  easePivot(tempRead, newUS); //100
}

void dtsWrist(long newUS){
  long tempRead = 0;
  tempRead = wrist.read();
  tempRead = round(((tempRead*MIDUSRANGE)/180) + 500);
  easeWrist(tempRead, newUS); //100
}

void dtsElbow(long newUS){
  long tempRead = 0;
  tempRead = elbow.read();
  tempRead = round(((tempRead*MIDUSRANGE)/180) + 500); 
  easeElbow(tempRead, newUS); //100
}
//Doesnt use the global constants since it is a different servo
void dtsShoulder(long newUS){
  long tempRead = 0;
  tempRead = shoulder.read();
  tempRead = round(((tempRead*1800)/180) + 700);
  easeShoulder(tempRead, newUS); //100
}

void dtsBase(long newUS){
  long tempRead = 0;
  tempRead = base.read();
  tempRead = round(((tempRead*MIDUSRANGE)/180) + 500);
  easeBase(tempRead, newUS); //100
}


  //Need to update for Microsecondwrite
 //Ease function. Smooths out the motion of the claw. Need to make a member function of the struct later. Name suggested by Cameron
void easeClaw(long start, long stop){
  long temp, i;
  temp = abs(start-stop);
  temp = (temp*180)/MIDUSRANGE;
  if(start > stop){
    for(i = 0; i < temp; i++){
      claw.writeMicroseconds(start-(i*USINC));
      delay(5); //17 is what was used earlier and it seems kinda good.
    }
  }
  else if (start < stop){
    for(i = 0; i < temp; i++){
      claw.writeMicroseconds(start+(i*USINC));
      delay(5); //17 is what was used earlier and it seems kinda good.
    }    
  }
} 
void easeBase(long start, long stop){
  long temp, i;
  temp = abs(start-stop);
  temp = abs(start-stop);
  temp = (temp*180)/MIDUSRANGE;
  if(start > stop){
    for(i = 0; i < temp; i++){
      base.writeMicroseconds(start-(i*USINC));
      delay(5); //17 is what was used earlier and it seems kinda good.
    }
  }
  else if (start < stop){
    for(i = 0; i < temp; i++){
      base.writeMicroseconds(start+(i*USINC));
      delay(5); //17 is what was used earlier and it seems kinda good.
    }    
  }
} 

void easeShoulder(long start, long stop){
  long temp, i;
  temp = abs(start-stop);
  temp = abs(start-stop);
  temp = (temp*180)/MIDUSRANGE;
  if(start > stop){
    for(i = 0; i < temp; i++){
      shoulder.writeMicroseconds(start-(i*USINC));
      delay(10); //17 is what was used earlier and it seems kinda good.
    }
  }
  else if (start < stop){
    for(i = 0; i < temp; i++){
      shoulder.writeMicroseconds(start+(i*USINC));
      delay(10); //17 is what was used earlier and it seems kinda good.
    }    
  }
} 

void easeElbow(long start, long stop){
  long temp, i;
  temp = start-stop;
  temp = abs(temp);
  Serial.print("Num of Iterations: ");
  Serial.println(temp);
  //delay(5000);
  temp = (temp*180)/MIDUSRANGE;

  Serial.print("Num of Iterations: ");
  Serial.println(temp);
  //delay(5000);
  if(start > stop){
    for(i = 0; i < temp; i++){
      elbow.writeMicroseconds(start-(i*USINC));
      delay(5); //17 is what was used earlier and it seems kinda good.
    }
  }
  else if (start < stop){
    for(i = 0; i < temp; i++){
      elbow.writeMicroseconds(start+(i*USINC));
      delay(5); //17 is what was used earlier and it seems kinda good.
    }    
  }
} 

void easePivot(long start, long stop){
  long temp = 0;
  long i = 0;
  Serial.print("Before temp\n");
  temp = abs(start-stop);
  temp = (temp*180)/MIDUSRANGE;
  Serial.print("After temp\n");
  if(start > stop){
    Serial.print("made it here1\n");
    for(i = 0; i < temp/2; i++){
      Serial.print("Iteration");      
      pivot.writeMicroseconds(start-(i*2*USINC));
      delay(5); //17 is what was used earlier and it seems kinda good.
    }
  }
  else if (start < stop){
    Serial.print("made it here2\n");
    for(i = 0; i < temp/2; i++){
      Serial.print("Iteration ");
      Serial.println(i); 
      Serial.print("USINC = ");
      Serial.println(USINC);
      pivot.writeMicroseconds(start+(i*2*USINC));
      delay(5); //17 is what was used earlier and it seems kinda good.
    }    
  }
  else{   
    Serial.print("made it here3\n");
  }
} 

void easeWrist(long start, long stop){
  long temp, i;
  temp = abs(start-stop);
  temp = (temp*180)/MIDUSRANGE;
  if(start > stop){
    for(i = 0; i < temp; i++){
      wrist.writeMicroseconds(start-(i*USINC));
      delay(5); //17 is what was used earlier and it seems kinda good.
    }
  }
  else if (start < stop){
    for(i = 0; i < temp; i++){
      wrist.writeMicroseconds(start+(i*USINC));
      delay(5); //17 is what was used earlier and it seems kinda good.
    }    
  }
} 


 //2400-500. Just did some conversion in the paramter since im lazy. Need to remount the wrist servo probably elbow too. doesnt go far enough to do what I need it to do. Max arange is 2500.
void initArm(){
  //Default position for each servo
  //delay(5000); // 5 second delay so i can start recording
  claw.writeMicroseconds(COPEN);
  pivot.writeMicroseconds(MINUSRANGE+450);
  wrist.writeMicroseconds(2500); //0 is poiting upwards. 180 is pointing down.
  elbow.writeMicroseconds(1000);
  shoulder.writeMicroseconds(1600);//was 90 700-2500, so 90 is about 700+1800*90/180=1600
  base.writeMicroseconds(NORTH);//Was 180

  //Attaching all servos to their respective pins
  base.attach(SBASE);
  delay(100);
  shoulder.attach(SSHOULDER);
  delay(100);
  elbow.attach(SELBOW);
  delay(100);
  wrist.attach(SWRIST);
  delay(100);
  pivot.attach(SPIVOT);
  delay(100);
  claw.attach(SCLAW);
  delay(100);
}
//Slowly lowers the arm until its about level. Input 0 for not stacking pillar, otherwise 1 = mid, 2 = top, 3 = duck
//Currently only meant to be used to pick up and stack. Might need to change slowfall a bit later to get it t use dts function
void slowFall(long stack){
  //slowly lowers the arm so it doesnt slam into the ground.
  if(stack == 0){
    for(long i = 0; i < 317; i++){
     shoulder.writeMicroseconds(1600-(i*USINC));
     delay(17); //round(500/30) = 17 
    }
  }
  else if (stack == 1){
   // elbow.write(105); //Need to change elbow since the higher it is, the more horizontal distance it needs to place pillar
    for(long i = 0; i < 148; i++){
     shoulder.writeMicroseconds(1600-(i*USINC));
     delay(17);    
    }
  }
  //Need to change for top and duck
  else if (stack == 2){
    for(long i = 0; i < 137; i++){
     shoulder.writeMicroseconds(1600-(i*USINC));
     delay(17);      
    }
  }
  else if (stack == 3){
    for(long i = 0; i < 3; i++){
     shoulder.writeMicroseconds(1344-(i*USINC));
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
void pickUp(long objDeg){
  long tempRead = 0;
  // Code to grab a duck about a foot away from the base.
   dtsClaw(COPEN);
  delay(500);
  dtsElbow(1000);
  delay(500);
  dtsShoulder(1700);
  slowFall(0);
  delay(500);    
  //end code for grabbing a duck a foot away from base.
  dtsClaw(objDeg);
  delay(500);

  //Lifting the duck into the air (default position)
  dtsPivot(901);//38
  delay(100);
  dtsWrist(2500); //180
  delay(100);
  dtsShoulder(1800);//90
  delay(100);
  dtsElbow(975); //45
  delay(100); 
}

//Takes in the parameter that specifies which part of the pillar it is building.
//0 Means base, 1 means middle, 2 means top, 3 means duck
void pillarStack(long posNum){
  long tempRead = 0;
  // Code to grab a duck about a foot away from the base.
  delay(100); 
  dtsShoulder(1700); //100
  if(posNum > 1){
    dtsElbow(1746);//118
   delay(100);
   dtsWrist(1270);//73
  }  
  else{
    dtsWrist(1556);//100
    delay(100);
    dtsElbow(1450); // 90 is good
}
  delay(500);
  slowFall(posNum);
  delay(500);
  easeClaw(CPCLOSE, COPEN);
  delay(500);
}

//Sets the arm to go to a default position facing the rotatioanl degree specified by the parameter.
// Note this does nothing to the claw. The claw must be sent a signal manually.
void positionDefault(long baseDeg){
  long tempRead = 0;

  dtsPivot(MINUSRANGE+450);//38
  Serial.print("Finished Pivot\n");
  delay(100);
  dtsWrist(2500); //0 is pointing upwards. 180 is pointing down. want 180
  Serial.print("Finished Wrist\n");
  delay(100);
  dtsElbow(1000);//45
  Serial.print("Finished Elbow\n");
  delay(100);
  dtsShoulder(1600); //90
  Serial.print("Finished Shoulder\n");
  delay(100);
  dtsBase(baseDeg);
  Serial.print("Finished Base\n");
  }
//Horizontal movement on the claw machine. Starts on the left, moves to the right.

void CMpickUp(int objDeg){
  dtsShoulder(1300);
  dtsElbow(1000);
  delay(100);
  dtsClaw(objDeg);
  delay(500);
  dtsShoulder(1600);
  dtsElbow(1000);  
}


volatile int found = 0;
void CMHorizontal(int objDeg){
  int i =  0;
  dtsBase(NORTHEAST);
  delay(500);
  dtsPivot(1300);  
  for(i = 0; i < 44; i++){
    //found = digitalRead(BUTTONPIN);  Weird functionality if this is uncommented when the button is commented  
    if(found != 1){
      dtsBase(NORTHEAST-i*20);
      dtsPivot(1300-i*20);
      delay(5);
    }
    else{
      CMpickUp(objDeg);//some pickup function
      break;
      
    }
  }
  Serial.print("After CMHorizontal\n");
}


void testStack(){
  long stack = 0;
  initArm();
  delay(100);
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
