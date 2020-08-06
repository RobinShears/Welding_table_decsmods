//Code that controls the speed and direction
//of the welding table at skyrora
//Robin Shears


int SpeedIn; //pot read value
int speedPot = A6; //pot read value
int PWM = 5; // outputs variable sqaure wave for speed
int DIRSwitch = 3; //switch to switch direction
int DIRon = 2; //always on
int DIR1 = 11;  //Direction control 1
int DIR2 = 12;  //Direction control 2
int pulseV = 4;
uint32_t Sqauresp;
int lastSpeed;

void setup() {
  Serial.begin(115200);

  pinMode(speedPot, INPUT);
  pinMode(DIRSwitch, INPUT);

  pinMode(PWM, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(DIRon, OUTPUT);
  pinMode(pulseV, OUTPUT);
  digitalWrite(DIRon, HIGH);
  digitalWrite(DIR1, HIGH);
  digitalWrite(pulseV, HIGH);
}




uint32_t previousTime;


void loop() {

  directionSwitch();

  SpeedIn = analogRead(speedPot);
  Serial.print("Speed in: ");
  Serial.print(SpeedIn);
  Serial.print("   ");

  if (SpeedIn > lastSpeed + 1 || SpeedIn < lastSpeed - 1) {
    Sqauresp = map(SpeedIn, 0, 1024, 312, 38500);
    lastSpeed = SpeedIn;
  }


  Serial.print("Squaresp: ");

  Serial.print(Sqauresp);
  Serial.println(" ");
  //Serial.println(" ");



  uint32_t currentTime = micros();

  if (currentTime - previousTime >= Sqauresp*100) {

    if (PWM == HIGH) {
      digitalWrite(PWM, LOW);
    } else {
      digitalWrite(PWM, HIGH);
    }


    previousTime = currentTime;
  }



//use 7 segment library here will update every ten pulses to releave the control circuit
//print(calib*Speedin);





}





void directionSwitch() {

  if (digitalRead(DIRSwitch) == HIGH) {   //controls the direction of the table based on the switch position
    digitalWrite(DIR2, LOW);
    
  }
  else {
    digitalWrite(DIR2, HIGH);
    Serial.println("DIRswitch = LOW");
  }

}

/*
  if (whateveveryoucallit.delayScript(delayTime){
  // do the thing
  }
  /*


*/
