#include <VarSpeedServo.h>
#include <SPI.h>
#include <Wire.h>
VarSpeedServo sv1;
VarSpeedServo sv2;
VarSpeedServo sv3;
VarSpeedServo sv4;
VarSpeedServo sv5;
VarSpeedServo sv6;
VarSpeedServo sv7;
int bt1 = 9;
int bt2 = 10;
int bt3 = 11;
int val1 = 90, val2 = 90 , val3 = 90, val4 = 90, val5 = 90, val6 = 90;
int x = 0;
String Ex_String_Read;
int angles_A[6] {90, 90, 90, 90, 90, 90};
int max_angles_A[6] { 180, 180, 180, 180, 180, 180};
int min_angles_A[6] { 0, 0, 0, 0, 0, 0};
int max_x = 30, max_y = 30, max_z = 30;
int min_x = 30, min_y = 30, min_z = 30;
int round_A = 0;
int spd = 10;
unsigned long pre1 = 0;
int ledState = LOW;
void setup() {
  delay(2000);
  pinMode(bt1, INPUT);
  Serial.begin(9600);
  pinMode(bt1, INPUT);
  pinMode(bt2, INPUT);
  pinMode(bt3, INPUT);
  sv1.attach(2);
  sv2.attach(3);
  sv3.attach(4);
  sv4.attach(5);
  sv5.attach(6);
  sv6.attach(8);
  sv7.attach(10);


}
void loop() {
  if (digitalRead(bt3) == HIGH) {
    delay(100);
     if (digitalRead(bt3) == HIGH) {
    x += 1;
    if (x == 8) {
      x = 0;
    }
  }}

  if (x == 8) {
    if (digitalRead(bt1) == HIGH) {
      spd += 1;

    }
    if (digitalRead(bt2) == HIGH) {
      spd -= 1;
    }
  }
  if (x == 1) {


    if (digitalRead(bt1) == HIGH) {
      val1++;
      sv1.write(val1, spd); //rotate1 axis1
      sv2.write(val2, spd); //updown1 axis2
      sv3.write(val3, spd); //forbk   axis3
      sv4.write(val4, spd); //rotate2 axis4
      sv5.write(val5, spd); //updown2 axis5
      sv6.write(val6, spd); //rotate3 axis6

      sv1.wait();
      sv2.wait();
      sv3.wait();
      sv4.wait();
      sv5.wait();
      sv6.wait();

    }

    if (digitalRead(bt2) == HIGH) {
      val1--;
      sv1.write(val1, spd); //rotate1 axis1
      sv2.write(val2, spd); //updown1 axis2
      sv3.write(val3, spd); //forbk   axis3
      sv4.write(val4, spd); //rotate2 axis4
      sv5.write(val5, spd); //updown2 axis5
      sv6.write(val6, spd); //rotate3 axis6

      sv1.wait();
      sv2.wait();
      sv3.wait();
      sv4.wait();
      sv5.wait();
      sv6.wait();

    }
    
  }

  if (x == 2) {


    if (digitalRead(bt1) == HIGH) {
      val2++;
      sv1.write(val1, spd); //rotate1 axis1
      sv2.write(val2, spd); //updown1 axis2
      sv3.write(val3, spd); //forbk   axis3
      sv4.write(val4, spd); //rotate2 axis4
      sv5.write(val5, spd); //updown2 axis5
      sv6.write(val6, spd); //rotate3 axis6

      sv1.wait();
      sv2.wait();
      sv3.wait();
      sv4.wait();
      sv5.wait();
      sv6.wait();

    }

    if (digitalRead(bt2) == HIGH) {
      val2--;
      sv1.write(val1, spd); //rotate1 axis1
      sv2.write(val2, spd); //updown1 axis2
      sv3.write(val3, spd); //forbk   axis3
      sv4.write(val4, spd); //rotate2 axis4
      sv5.write(val5, spd); //updown2 axis5
      sv6.write(val6, spd); //rotate3 axis6

      sv1.wait();
      sv2.wait();
      sv3.wait();
      sv4.wait();
      sv5.wait();
      sv6.wait();

    }
  }
  if (x == 3) {


    if (digitalRead(bt1) == HIGH) {
      val3++;
      sv1.write(val1, spd); //rotate1 axis1
      sv2.write(val2, spd); //updown1 axis2
      sv3.write(val3, spd); //forbk   axis3
      sv4.write(val4, spd); //rotate2 axis4
      sv5.write(val5, spd); //updown2 axis5
      sv6.write(val6, spd); //rotate3 axis6

      sv1.wait();
      sv2.wait();
      sv3.wait();
      sv4.wait();
      sv5.wait();
      sv6.wait();

    }

    if (digitalRead(bt2) == HIGH) {
      val3--;
      sv1.write(val1, spd); //rotate1 axis1
      sv2.write(val2, spd); //updown1 axis2
      sv3.write(val3, spd); //forbk   axis3
      sv4.write(val4, spd); //rotate2 axis4
      sv5.write(val5, spd); //updown2 axis5
      sv6.write(val6, spd); //rotate3 axis6

      sv1.wait();
      sv2.wait();
      sv3.wait();
      sv4.wait();
      sv5.wait();
      sv6.wait();

    }
  }

  if (x == 4) {


    if (digitalRead(bt1) == HIGH) {
      val4++;
      sv1.write(val1, spd); //rotate1 axis1
      sv2.write(val2, spd); //updown1 axis2
      sv3.write(val3, spd); //forbk   axis3
      sv4.write(val4, spd); //rotate2 axis4
      sv5.write(val5, spd); //updown2 axis5
      sv6.write(val6, spd); //rotate3 axis6

      sv1.wait();
      sv2.wait();
      sv3.wait();
      sv4.wait();
      sv5.wait();
      sv6.wait();

    }

    if (digitalRead(bt2) == HIGH) {
      val4--;
      sv1.write(val1, spd); //rotate1 axis1
      sv2.write(val2, spd); //updown1 axis2
      sv3.write(val3, spd); //forbk   axis3
      sv4.write(val4, spd); //rotate2 axis4
      sv5.write(val5, spd); //updown2 axis5
      sv6.write(val6, spd); //rotate3 axis6

      sv1.wait();
      sv2.wait();
      sv3.wait();
      sv4.wait();
      sv5.wait();
      sv6.wait();

    }
  }


  if (x == 5) {


    if (digitalRead(bt1) == HIGH) {
      val5++;
      sv1.write(val1, spd); //rotate1 axis1
      sv2.write(val2, spd); //updown1 axis2
      sv3.write(val3, spd); //forbk   axis3
      sv4.write(val4, spd); //rotate2 axis4
      sv5.write(val5, spd); //updown2 axis5
      sv6.write(val6, spd); //rotate3 axis6

      sv1.wait();
      sv2.wait();
      sv3.wait();
      sv4.wait();
      sv5.wait();
      sv6.wait();

    }

    if (digitalRead(bt2) == HIGH) {
      val5--;
      sv1.write(val1, spd); //rotate1 axis1
      sv2.write(val2, spd); //updown1 axis2
      sv3.write(val3, spd); //forbk   axis3
      sv4.write(val4, spd); //rotate2 axis4
      sv5.write(val5, spd); //updown2 axis5
      sv6.write(val6, spd); //rotate3 axis6

      sv1.wait();
      sv2.wait();
      sv3.wait();
      sv4.wait();
      sv5.wait();
      sv6.wait();

    }
  }
  if (x == 6) {


    if (digitalRead(bt1) == HIGH) {
      val6++;
      sv1.write(val1, spd); //rotate1 axis1
      sv2.write(val2, spd); //updown1 axis2
      sv3.write(val3, spd); //forbk   axis3
      sv4.write(val4, spd); //rotate2 axis4
      sv5.write(val5, spd); //updown2 axis5
      sv6.write(val6, spd); //rotate3 axis6

      sv1.wait();
      sv2.wait();
      sv3.wait();
      sv4.wait();
      sv5.wait();
      sv6.wait();

    }

    if (digitalRead(bt2) == HIGH) {
      val6--;
      sv1.write(val1, spd); //rotate1 axis1
      sv2.write(val2, spd); //updown1 axis2
      sv3.write(val3, spd); //forbk   axis3
      sv4.write(val4, spd); //rotate2 axis4
      sv5.write(val5, spd); //updown2 axis5
      sv6.write(val6, spd); //rotate3 axis6

      sv1.wait();
      sv2.wait();
      sv3.wait();
      sv4.wait();
      sv5.wait();
      sv6.wait();

    }
  }

  Serial.print("spd");
  Serial.print(" ");
  Serial.print(spd);
  Serial.print(" ");
  Serial.print("SERVO");
  Serial.print(" ");
  Serial.print(x);
  Serial.print(" ");
  Serial.print("sv1");
  Serial.print(" ");
  Serial.print(val1);
  Serial.print(" ");
  Serial.print("sv2");
  Serial.print(" ");
  Serial.print(val2);
  Serial.print(" ");
  Serial.print("sv3");
  Serial.print(" ");
  Serial.print(val3);
  Serial.print(" ");
  Serial.print("sv4");
  Serial.print(" ");
  Serial.print(val4);
  Serial.print(" ");
  Serial.print("sv5");
  Serial.print(" ");
  Serial.print(val5);
  Serial.print(" ");
  Serial.print("sv6");
  Serial.print(" ");
  Serial.println(val6);


  if(digitalRead(bt3)==HIGH){
    //record
    int position_A[7]
  }
}
//}
//void para1() {
//  if (max_angles_A[3] == angles_A[3]) {
//    Serial.print("ERR");
//
//  }
//  angles_A[3] -= angles_A[2] - x + y;
//  angles_A[2] += x;
//  angles_A[3] += y;
//  read_angles();
//}
//void control_A() {
//  Serial.println(round_A);
//  sv1.write(angles_A[1], spd); //rotate1 axis1
//  sv2.write(angles_A[2], spd); //updown1 axis2
//  sv3.write(angles_A[3], spd); //forbk   axis3
//  sv4.write(angles_A[4], spd); //rotate2 axis4
//  sv5.write(angles_A[5], spd); //updown2 axis5
//  sv6.write(angles_A[6], spd); //rotate3 axis6
//  sv7.write(90, spd); //gripper
//  sv1.wait();
//  sv2.wait();
//  sv3.wait();
//  sv4.wait();
//  sv5.wait();
//  sv6.wait();
//  sv7.wait();

//}
//void read_angles() {
//  Serial.print(angles_A[2]);
//  Serial.print(" ");
//  Serial.print("x");
//  Serial.print(" ");
//  Serial.print(x);
//
//  Serial.print(" ");
//  Serial.print("y");
//  Serial.print(" ");
//  Serial.print(y);
//  Serial.print(" ");
//  Serial.println(angles_A[3]);
//}
