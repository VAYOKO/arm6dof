#include <VarSpeedServo.h> 
VarSpeedServo myservo1;
VarSpeedServo myservo2;
VarSpeedServo myservo3;
VarSpeedServo myservo4;
VarSpeedServo myservo5;
VarSpeedServo myservo6;
void setup() {

  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  myservo5.attach(6);
  myservo6.attach(7);
   
  } 

  
void loop() {
  int maxspd = 160;
  int midspd = 100;
  int lowspd = 50;
  int verlowspd = 10 ;
   myservo1.write(90,verlowspd);
   myservo2.write(0,verlowspd);
   myservo3.write(0,verlowspd);
   myservo4.write(90,verlowspd);
   myservo5.write(90,verlowspd);
   myservo6.write(90,verlowspd);
   myservo1.wait();
   myservo2.wait();
   myservo3.wait();
   myservo4.wait();
   myservo5.wait();
   myservo6.wait();
  
   myservo1.write(0,verlowspd);
   myservo2.write(105,verlowspd);
   myservo3.write(105,verlowspd);
   myservo4.write(0,verlowspd);
   myservo5.write(90,verlowspd);
   myservo6.write(90,verlowspd);
   myservo1.wait();
   myservo2.wait();
   myservo3.wait();
   myservo4.wait();
   myservo5.wait();
   myservo6.wait();
   myservo1.write(0,verlowspd);
   myservo2.write(90,verlowspd);
   myservo3.write(90,verlowspd);
   myservo4.write(0,verlowspd);
   myservo5.write(90,verlowspd);
   myservo6.write(90,verlowspd);
   myservo1.wait();
   myservo2.wait();
   myservo3.wait();
   myservo4.wait();
   myservo5.wait();
   myservo6.wait();
   myservo1.write(0,verlowspd);
   myservo2.write(90,verlowspd);
   myservo3.write(0,verlowspd);
   myservo4.write(0,verlowspd);
   myservo5.write(0,verlowspd);
   myservo6.write(0,verlowspd);
   myservo1.wait();
   myservo2.wait();
   myservo3.wait();
   myservo4.wait();
   myservo5.wait();
   myservo6.wait();
}
