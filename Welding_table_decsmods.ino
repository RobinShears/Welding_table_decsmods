//Code that controls the speed and direction
//of the welding table at skyrora
//Robin Shears
int SpeedIn; //pot middle pin
int PWM = 5; // outputs variable sqaure wave for speed
int DIRSwitch = 3; //switch to switch direction
int DIRon = 2; //always on
int DIR1 = 11;  //Direction control 1
int DIR2 = 12;  //Direction control 2
int pulseV = 4;
uint32_t Sqauresp;
int lastSpeed;

void setup() {
  Serial.begin(9600);
  pinMode(SpeedIn, INPUT);
  pinMode(PWM, OUTPUT);
  pinMode(DIRSwitch, INPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(SpeedIn, INPUT);
  pinMode(DIRon, OUTPUT);
  pinMode(pulseV, OUTPUT);
  digitalWrite(DIRon, HIGH);
  digitalWrite(DIR1, HIGH);
  digitalWrite(pulseV, HIGH);
}


void loop() {

  

  if (digitalRead(DIRSwitch) == HIGH) {   //controls the direction of the table based on the switch position
    digitalWrite(DIR2, LOW);
  }
  else {
    digitalWrite(DIR2, HIGH);
  }


  SpeedIn = analogRead(A6);
  Serial.print("Speed in: ");
  Serial.print(SpeedIn);
  Serial.print("   ");

  if (SpeedIn > lastSpeed+2 || SpeedIn < lastSpeed-2){
  Sqauresp = map(SpeedIn, 0, 1024, 312, 3850000);
  }

  
  Serial.print("Squaresp: ");
  
  Serial.println(Sqauresp);
  Serial.println(" ");
  //Serial.println(" ");       
  
  for (int x = 0; x < 10; x++) {
    digitalWrite(PWM, HIGH); //genorates a pwm waveform at the frequency needed compared to the input
    delayMicroseconds(Sqauresp);
    digitalWrite(PWM, LOW);
    delayMicroseconds(Sqauresp); //(min ms+(range of ms/1024)*speedin)
  }
  //use 7 segment library here will update every ten pulses to releave the control circuit
  //print(calib*Speedin);



lastSpeed = SpeedIn;

}

/*
if (whateveveryoucallit.delayScript(delayTime){
 // do the thing
}
/*
 * 
 * // delayTime = squareSP
currentTime = micros();

if (currentTime - previousTime >= delayTime){
// do the thing
previousTime = currentTime;
}
*/
