#include <Stepper.h>
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 

int pos = 0;
   // variable to store the servo position 

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance. 

//Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created  
int count=0;
int back=0;
const int stepsPerRevolution = 200; 
Stepper myStepper(stepsPerRevolution, 7, 8);

void setup() {
   Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
   myservo.attach(6);  // attaches the servo on pin 9 to the servo object 

  // put your setup code here, to run once:

pinMode (9,INPUT);
pinMode (2,INPUT);
pinMode (3,INPUT);
pinMode (4,INPUT);
pinMode (5,INPUT);


 myStepper.setSpeed(5000);
Serial.begin (9600);


  
}
void loop() {
  // put your main code here, to run repeatedly:
   // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "56 93 75 1F" || "03 6F CD 73") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
  /*  for(pos = 0; pos < 90; pos += 1)  // goes from 0 degrees to 180 degrees 
  { */                                 // in steps of 1 degree 
    myservo.write(170);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  //} 
  delay(4000);
  /*for(pos = 90; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  { */                               
    myservo.write(90);              // tell servo to go to position in variable 'pos' 
    delay(2000);

    int Aa=digitalRead (2);
  int Ab=digitalRead (3);
  int Ba=digitalRead (4);
  int Bb=digitalRead (5);
  if (Aa==LOW  )
  {
    if(Ab==HIGH)
    {
       if (Ba==HIGH)
       {
         if (Bb==LOW)
         {
          for(int x=0; x<3300; x++){
           Serial.println("working");
           Serial.println("counterclockwise");
            count++;
            Serial.println(count);
         myStepper.step(-stepsPerRevolution); }
         delay(5000);

          for(int x=0; x<1200; x++){
            Serial.println("working");
            Serial.println("clockwise");
            back++;
            Serial.println(back);
           
            myStepper.step(stepsPerRevolution);}
         }
         else
         {
          Serial.println("all spot are full");
         }
       }
       else
       {
        for(int x=0; x<3300; x++){
           Serial.println("working");
           Serial.println("counterclockwise");
         myStepper.step(-stepsPerRevolution); }
         delay(5000);
          for(int x=0; x<1200; x++){
            Serial.println("working");
            Serial.println("clockwise");
              count++;
            Serial.println(count);
            myStepper.step(stepsPerRevolution);}
       }
        }
        else
        {
           for(int x=0; x<1300; x++){
           Serial.println("working");
           Serial.println("counterclockwise");
             count++;
            Serial.println(count);
         myStepper.step(-stepsPerRevolution); }

         delay(5000);
          for(int x=0; x<490; x++){
            Serial.println("working");
            Serial.println("clockwise");
            back++;
            Serial.println(back);
            myStepper.step(stepsPerRevolution);}
        }
      }
      else
      {

            for(int x=0; x<1300; x++){
           Serial.println("working");
           Serial.println("counterclockwise");
             count++;
            Serial.println(count);
         myStepper.step(-stepsPerRevolution); }
         delay(5000);
          for(int x=0; x<490; x++){
            Serial.println("working");
            Serial.println("clockwise");
            back++;
            Serial.println(back);
            myStepper.step(stepsPerRevolution);}
      }
    
     /*myservo.attach(10);  // attaches the servo on pin 9 to the servo object 
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
  }*/
  //}
  }
 else   {
    Serial.println(" Access denied");
    Serial.println(" tryagain");                        
  
  }

} 
