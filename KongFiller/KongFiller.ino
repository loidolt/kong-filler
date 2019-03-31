/*
* Kong Filler
* Chris Loidolt
* 
* References:
* Simple Stepper Motor Control Exaple Code
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
*/

const int stepPin = 1;
const int dirPin = 0;
//const int enablePin = 2;

const int autoBtn = 3;
const int manualBtn = 4;

int StepsTaken = 0;
const int autoSteps = 1000;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  //pinMode(enablePin, OUTPUT);

  pinMode(autoBtn, INPUT_PULLUP);
  pinMode(manualBtn, INPUT_PULLUP);
 
  digitalWrite(dirPin,HIGH); //Enables the motor to move in a particular direction
}
void loop() {

  while (digitalRead(manualBtn) == LOW){
    
    //digitalWrite(enablePin, LOW);
    
    digitalWrite(stepPin, HIGH); //This moves the stepper by 1 step.
    delay(70); //Depends on Motor 500-1000 is good
    digitalWrite(stepPin, LOW);
    delay(70);
  }

  if (digitalRead(autoBtn) == LOW){

    //digitalWrite(enablePin, LOW);
    
    while (StepsTaken < autoSteps){
      digitalWrite(stepPin, HIGH); //This moves the stepper by 1 step.
      delay(70); //Depends on Motor 500-1000 is good
      digitalWrite(stepPin, LOW);
      delay(70);
      StepsTaken++;
    }
  }

}
