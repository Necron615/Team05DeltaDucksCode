const int trigPin = 9;
const int echoPin = 8;
// defines variables
long duration;
int distance;
void SSsetup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}
long sonarLoop(int wall) {
  long time1 = 0;
  long time2 = 0;
  long tempDistance = 1;
  long timeElapsed = 0;
  int done = 0;
  // Clears the trigPin
  time1 = millis();  
  distance = 10000;
  while(done == 0){
    if(distance > wall){
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin, HIGH);
      // Calculating the distance
      distance = duration * 0.034 / 2;
      // Prints the distance on the Serial Monitor
      Serial.print("Distance: ");
      Serial.println(distance);
      delay(100);
            digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin, HIGH);
      // Calculating the distance
      distance = duration * 0.034 / 2;
      // Prints the distance on the Serial Monitor
      Serial.print("Distance: ");
      Serial.println(distance);
      done = 0;
    }
    else{
      done = 1;

    }
  }
  time2 = millis();
  timeElapsed = time2 - time1;
  return timeElapsed;
}