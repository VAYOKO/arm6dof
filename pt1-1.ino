#include <VarSpeedServo.h>
VarSpeedServo sv1;
VarSpeedServo sv2;
VarSpeedServo sv3;
VarSpeedServo sv4;
VarSpeedServo sv5;
VarSpeedServo sv6;
VarSpeedServo sv7;
int axis1 = 90;
int axis2 = 90;
int axis3 = 90;
int axis4 = 90;
int axis5 = 90;
int axis6 = 90;
int axis7 = 90;

int sn1 = A0;
int bt1 = 12;
void setup() {
  pinMode(sn1, INPUT);
  pinMode(bt1,INPUT_PULLUP);
  Serial.begin(9600);
  sv1.attach(2);
  sv2.attach(3);
  sv3.attach(4);
  sv4.attach(5);
  sv5.attach(6);
  sv6.attach(7);
  sv7.attach(8);

}


void loop() {
  int maxspd = 160;
  int midspd = 100;
  int lowspd = 50;
  int verlowspd = 10 ;
  int valsn1 = analogRead(sn1);
  if(Serial.available() > 0){
    char inbyte = Serial.read();
    Serial.println(inbyte);
    switch(inbyte){
      case'a':
      axis1+=10;
      sv1.write(axis1, 10);
      break;

      case'd':
       axis1-=10;
      sv1.write(axis1, 10);
      break;

       case'w':
      axis2+=10;
      sv2.write(axis2, 10);
      sv3.write(axis2, 10);
      break;

      case's':
       axis2-=10;
      sv2.write(axis2, 10);
      sv3.write(axis2, 10);
      break;
      

      case'e':
      axis3+=10;
      sv4.write(axis3, 10);
      break;

      case'q':
       axis3-=10;
      sv4.write(axis3, 10);
      break;

        case'r':
      axis4+=10;
      sv5.write(axis4, 10);
      break;

      case'f':
       axis4-=10;
      sv5.write(axis4, 10);
      break;

        case't':
      axis5+=10;
      sv6.write(axis5, 10);
      break;

      case'g':
       axis5-=10;
      sv6.write(axis5, 10);
      break;
        case'y':
      axis6+=10;
      sv7.write(axis6, 10);
      break;

      case'h':
       axis6-=10;
      sv7.write(axis6, 10);
      break;
    }
    

  }
//  sv1.write(90, 10);
//  sv2.write(90, 10);
//  sv3.write(90, 10);
//  sv4.write(90, 10);
//  sv5.write(90, 10);
//  sv6.write(90, 10);
//  sv7.write(90, 10);
//  sv1.wait();
//  sv2.wait();
//  sv3.wait();
//  sv4.wait();
//  sv5.wait();
//  sv6.wait();
//  sv7.wait();
//  sv1.write(90, 10);
//  sv2.write(150, 10);
//  sv3.write(150, 10);
//  sv4.write(90, 10);
//  sv5.write(20, 10);
//  sv6.write(90, 10);
//  sv1.wait();
//  sv2.wait();
//  sv3.wait();
//  sv4.wait();
//  sv5.wait();
//  sv6.wait();
//
//
//  sv1.write(180, 10);
//  sv2.write(150, 10);
//  sv3.write(140, 10);
//  sv4.write(90, 10);
//  sv5.write(15, 10);
//  sv6.write(90, 10);
//  sv1.wait();
//  sv2.wait();
//  sv3.wait();
//  sv4.wait();
//  sv5.wait();
//  sv6.wait();
//
//  delay(2000);
//  Serial.print(" sensor ir:  "); Serial.println(valsn1);
//  Serial.print("  mode    :  "); Serial.println("listen");
//  sv1.write(180, 10);
//  sv2.write(170, 10);
//  sv3.write(160, 10);
//  sv4.write(90, 10);
//  sv5.write(0, 10);
//  sv6.write(90, 10);
//  sv7.write(180, 10);
//  sv1.wait();
//  sv2.wait();
//  sv3.wait();
//  sv4.wait();
//  sv5.wait();
//  sv6.wait();
//  delay(1000);
// sv1.write(90, 10);
//  sv2.write(170, 10);
//  sv3.write(160, 10);
//  sv4.write(90, 10);
//  sv5.write(15, 10);
//  sv6.write(90, 10);
//  sv7.write(180, 10);
//  sv1.wait();
//  sv2.wait();
//  sv3.wait();
//  sv4.wait();
//  sv5.wait();
//  sv6.wait();
//  sv1.write(90, 10);
//  sv2.write(90, 10);
//  sv3.write(90, 10);
//  sv4.write(90, 10);
//  sv5.write(15, 10);
//  sv6.write(90, 10);
//  sv7.write(90, 10);
//  sv1.wait();
//  sv2.wait();
//  sv3.wait();
//  sv4.wait();
//  sv5.wait();
//  sv6.wait();
//  delay(1000);
}
