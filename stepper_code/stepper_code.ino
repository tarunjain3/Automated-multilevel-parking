#include <Stepper.h>
const int stepsPerRevolution = 200;
   // change this to fit the number of steps per revolution
int count=0;
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 7, 8);

void setup() {
// pinMode(2,INPUT);
  // set the speed at 5000 rpm:
  myStepper.setSpeed(5000);
  // initialize the serial port:
  Serial.begin(9600);
}
void loop() {
int x=digitalRead(2);
  if (x==HIGH)
  {
 // step one revolution  in one direction:
  for(int x=0; x<50; x++){
     Serial.println("working");
     Serial.println("clockwise");
     myStepper.step(stepsPerRevolution);
     count++;
     Serial.println(count);
  }
  }

 //step one revolution in the other direction:
 if (x==LOW)
 {
  for(int x=0; x<50; x++){
     Serial.println("working");
Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution); }
}
}
