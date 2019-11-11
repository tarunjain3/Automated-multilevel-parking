#include <Stepper.h>
#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 

int pos = 0;    // 
int count=0;
const int stepsPerRevolution = 200; 
Stepper myStepper(stepsPerRevolution, 7, 8);

void setup() {
  // put your setup code here, to run once:

pinMode (9,INPUT);
pinMode (2,INPUT);
pinMode (3,INPUT);
pinMode (4,INPUT);
pinMode (5,INPUT);


 myStepper.setSpeed(5000);
Serial.begin (9600);


  int Aa=digitalRead (2);
  int Ab=digitalRead (3);
  int Ba=digitalRead (4);
  int Bb=digitalRead (5);
  if (Aa==HIGH)
  {
    if(Ab==HIGH)
    {
       if (Ba==HIGH)
       {
         if (Bb==LOW)
         {
          for(int x=0; x<3500; x++){
           Serial.println("working");
           Serial.println("counterclockwise");
         myStepper.step(-stepsPerRevolution); }
         delay(5000);

          for(int x=0; x<1400; x++){
            Serial.println("working");
            Serial.println("clockwise");
            myStepper.step(stepsPerRevolution);}
         }
         else
         {
          Serial.println("all spot are full");
         }
       }
       else
       {
        for(int x=0; x<3500; x++){
           Serial.println("working");
           Serial.println("counterclockwise");
         myStepper.step(-stepsPerRevolution); }
         delay(5000);
          for(int x=0; x<1000; x++){
            Serial.println("working");
            Serial.println("clockwise");
            myStepper.step(stepsPerRevolution);}
       }
        }
        else
        {
           for(int x=0; x<1200; x++){
           Serial.println("working");
           Serial.println("counterclockwise");
         myStepper.step(-stepsPerRevolution); }

         delay(5000);
          for(int x=0; x<500; x++){
            Serial.println("working");
            Serial.println("clockwise");
            myStepper.step(stepsPerRevolution);}
        }
      }
      else
      {

            for(int x=0; x<1200; x++){
           Serial.println("working");
           Serial.println("counterclockwise");
         myStepper.step(-stepsPerRevolution); }
         delay(5000);
          for(int x=0; x<500; x++){
            Serial.println("working");
            Serial.println("clockwise");
            myStepper.step(stepsPerRevolution);}
      }
    
     myservo.attach(10);  // attaches the servo on pin 9 to the servo object 
     for(pos = 0; pos < 90; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  delay(4000);
  for(pos = 90; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
}
void loop() {
  // put your main code here, to run repeatedly:

} 
