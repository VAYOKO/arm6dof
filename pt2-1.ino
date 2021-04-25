#include <VarSpeedServo.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // pixel ความกว้าง
#define SCREEN_HEIGHT 64 // pixel ความสูง 

// กำหนดขาต่อ I2C กับจอ OLED
#define OLED_RESET     -1 //ขา reset เป็น -1 ถ้าใช้ร่วมกับขา Arduino reset
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

VarSpeedServo sv1;
VarSpeedServo sv2;
VarSpeedServo sv3;
VarSpeedServo sv4;
VarSpeedServo sv5;
VarSpeedServo sv6;
VarSpeedServo sv7;
String Ex_String_Read;
int vr = A0;
int buz = 7;
int bt = 9;
int val = 90;
int x = 15 ;
int y = 0;
int z = 0;
int l = 0;
int led = 11;
int tim = 0;
int manual1 = 90;
int manual2 = 90;
int manual3 = 90;
int manual4 = 90;
int manual5 = 150;
int manual6 = 90;
int manual7 = 90;
unsigned long pre1 = 0;
int ledState = LOW;
void setup() {
  delay(2000);
  Serial.begin(9600);
  if (!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // สั่งให้จอ OLED เริ่มทำงานที่ Address 0x3C
    Serial.println("SSD1306 allocation failed");
  } else {
    Serial.println("ArdinoAll OLED Start Work !!!");
  }
  sv1.attach(2);
  sv2.attach(3);
  sv3.attach(4);
  sv4.attach(5);
  sv5.attach(6);
  sv6.attach(8);
  sv7.attach(10);

  pinMode(buz, OUTPUT);               //pinout
  pinMode(led, OUTPUT);
  pinMode(vr, INPUT);
  pinMode(bt, INPUT);
  pinMode(buz, OUTPUT);
  tone(buz, 15);
  delay(100);
  noTone(buz);
  delay(60);
  tone(buz, 15);
  delay(100);
  tone(buz, 30);
  delay(100);
  noTone(buz);

  sv1.write(90, x); //rotate1 axis1
  sv2.write(90, x); //updown1 axis2
  sv3.write(90, x); //forbk   axis3
  sv4.write(90, x); //rotate2 axis4
  sv5.write(90, x); //updown2 axis5
  sv6.write(90, x); //rotate3 axis6
  sv7.write(90, x); //gripper

}
void loop() {
  OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
  OLED.setTextColor(WHITE, BLACK);  //กำหนดข้อความสีขาว ฉากหลังสีดำ
  OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.println("SPEED"); // แสดงผลข้อความ ALL
  OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.print(x);
  OLED.display(); // สั่งให้จอแสดงผล
  if (Serial.available() > 0) {
    // read incoming serial data:
    char inChar = Serial.read();
    // Type the next ASCII value from what you received:
    Serial.println(inChar);

    Serial.println(inChar);
    if (inChar == 'w') {
      alarm1();
      manual2++;
      sv2.write(manual2, x);
      rea();
    }
    else if (inChar == 's') {
      alarm1();
      manual2--;
      sv2.write(manual2, x);
      rea();
    }

    else if (inChar == 'a') {
      alarm1();
      manual1++;
      sv1.write(manual1, x);
      rea();
    }
    else if (inChar == 'd') {
      alarm1();
      manual1--;
      sv1.write(manual1, x);
      rea();
    }

    else if (inChar == 'q') {
      alarm1();
      manual3++;
      sv3.write(manual3, x);
      rea();
    }
    else if (inChar == 'e') {
      alarm1();
      manual3--;
      sv3.write(manual3, x);
      rea();
    }

    else if (inChar == 'i') {
      alarm1();
      manual4++;
      sv4.write(manual4, x);
      rea();
    }
    else if (inChar == 'o') {
      alarm1();
      manual4--;
      sv4.write(manual4, x);
      rea();
    }

    else if (inChar == 'u') {
      alarm1();
      manual5++;
      sv5.write(manual5, x);
      rea();
    }
    else if (inChar == 'j') {
      alarm1();
      manual5--;
      sv5.write(manual5, x);
      rea();
    }

    else if (inChar == 'k') {
      alarm1();
      manual6++;
      sv6.write(manual6, x);
      rea();
    }
    else if (inChar == 'l') {
      alarm1();
      manual6--;
      sv6.write(manual6, x);
      rea();
    }

    else if (inChar == 'g') {
      alarm1();
      manual7++;
      sv7.write(manual7, x);
      rea();
    }
    else if (inChar == 'h') {
      alarm1();
      manual7--;
      sv7.write(manual7, x);
      rea();
    }

    else if (inChar == '1') {
      alarm1();
      x = 10;
      rea();
    }
    else if  (inChar == '2') {
      alarm1();
      x = 25;
      rea();
    }
    else {
      noTone(buz);
    }

  }
  if (digitalRead(bt) == HIGH) {
    OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
    OLED.setTextColor(WHITE, BLACK);  //กำหนดข้อความสีขาว ฉากหลังสีดำ
    OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
    OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
    OLED.println("SPEED :"); // แสดงผลข้อความ ALL
    OLED.setCursor(70, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
    OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
    OLED.print(x);
    OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
    OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
    OLED.println("TIME :"); // แสดงผลข้อความ ALL
    OLED.setCursor(70, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
    OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
    OLED.print(tim, DEC);
    OLED.setCursor(0, 40); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
    OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
    OLED.println("inprogress.."); // แสดงผลข้อความ ALL
    OLED.display(); // สั่งให้จอแสดงผล
    digitalWrite(led, 1);
    rea();
    sv1.write(90, x); //rotate1 axis1
    sv2.write(90, x); //updown1 axis2  left
    sv3.write(90, x); //forbk   axis3  left
    sv4.write(90, x); //rotate2 axis4
    sv5.write(150, x); //updown2 axis5 left
    sv6.write(90, x); //rotate3 axis6
    sv7.write(0, x); //gripper
    sv1.wait();
    sv2.wait();
    sv3.wait();
    sv4.wait();
    sv5.wait();
    sv6.wait();
    sv7.wait();

    sv1.write(90, x); //rotate1 axis1
    sv2.write(90, x); //updown1 axis2  left
    sv3.write(90, x); //forbk   axis3  left
    sv4.write(90, x); //rotate2 axis4
    sv5.write(150, x); //updown2 axis5 left
    sv6.write(90, x); //rotate3 axis6
    sv7.write(0, x); //gripper
    sv1.wait();
    sv2.wait();
    sv3.wait();
    sv4.wait();
    sv5.wait();
    sv6.wait();
    sv7.wait();

    sv1.write(90, x); //rotate1 axis1
    sv2.write(90, x); //updown1 axis2  left
    sv3.write(90, x); //forbk   axis3  left
    sv4.write(0, x); //rotate2 axis4
    sv5.write(0, x); //updown2 axis5 left
    sv6.write(40, x); //rotate3 axis6
    sv7.write(0, x); //gripper
    sv1.wait();
    sv2.wait();
    sv3.wait();
    sv4.wait();
    sv5.wait();
    sv6.wait();
    sv7.wait();
    sv1.write(60, x); //rotate1 axis1
    sv2.write(50, x); //updown1 axis2  left
    sv3.write(170, x); //forbk   axis3  left
    sv4.write(0, x); //rotate2 axis4
    sv5.write(40, x); //updown2 axis5 left
    sv6.write(40, x); //rotate3 axis6
    sv7.write(0, x); //gripper
    sv1.wait();
    sv2.wait();
    sv3.wait();
    sv4.wait();
    sv5.wait();
    sv6.wait();
    sv7.wait();
    delay(2000);

    sv1.write(60, x); //rotate1 axis1
    sv2.write(50, x); //updown1 axis2  left
    sv3.write(170, x); //forbk   axis3  left
    sv4.write(0, x); //rotate2 axis4
    sv5.write(40, x); //updown2 axis5 left
    sv6.write(40, x); //rotate3 axis6
    sv7.write(180, x); //gripper
    sv1.wait();
    sv2.wait();
    sv3.wait();
    sv4.wait();
    sv5.wait();
    sv6.wait();
    sv7.wait();
    sv7.wait();
    sv1.write(90, x); //rotate1 axis1
    sv2.write(90, x); //updown1 axis2  left
    sv3.write(90, x); //forbk   axis3  left
    sv4.write(90, x); //rotate2 axis4
    sv5.write(150, x); //updown2 axis5 left
    sv6.write(0, x); //rotate3 axis6
    sv7.write(0, x); //gripper
    sv1.wait();
    sv2.wait();
    sv3.wait();
    sv4.wait();
    sv5.wait();
    sv6.wait();
    sv7.wait();

    rea();
    
    sv1.write(130, x); //rotate1 axis1
    sv2.write(40, x); //updown1 axis2
    sv3.write(150, x); //forbk   axis3
    sv4.write(0, x); //rotate2 axis4
    sv5.write(50, x); //updown2 axis5
    sv6.write(180, x); //rotate3 axis6
    sv7.write(180, x); //gripper
    sv1.wait();
    sv2.wait();
    sv3.wait();
    sv4.wait();
    sv5.wait();
    sv6.wait();
    sv7.wait();

    rea();
    sv1.write(70, x); //rotate1 axis1
    sv2.write(120, x); //updown1 axis2
    sv3.write(80, x); //forbk   axis3
    sv4.write(180, x); //rotate2 axis4
    sv5.write(140, x); //updown2 axis5
    sv6.write(0, x); //rotate3 axis6
    sv1.wait();
    sv2.wait();
    sv3.wait();
    sv4.wait();
    sv5.wait();
    sv6.wait();


    rea();
    sv1.write(50, x); //rotate1 axis1
    sv2.write(40, x); //updown1 axis2
    sv3.write(150, x); //forbk   axis3
    sv4.write(0, x); //rotate2 axis4
    sv5.write(140, x); //updown2 axis5
    sv6.write(180, x); //rotate3 axis6
    sv1.wait();
    sv2.wait();
    sv3.wait();
    sv4.wait();
    sv5.wait();
    sv6.wait();

    rea();
    sv1.write(90, x); //rotate1 axis1
    sv2.write(40, x); //updown1 axis2
    sv3.write(150, x); //forbk   axis3
    sv4.write(90, x); //rotate2 axis4
    sv5.write(80, x); //updown2 axis5
    sv6.write(180, x); //rotate3 axis6
    sv1.wait();
    sv2.wait();
    sv3.wait();
    sv4.wait();
    sv5.wait();
    sv6.wait();
    delay(1000);

    rea();
    sv1.write(60, x); //rotate1 axis1
    sv2.write(90, x); //updown1 axis2
    sv3.write(90, x); //forbk   axis3
    sv4.write(90, x); //rotate2 axis4
    sv5.write(90, x); //updown2 axis5
    sv6.write(90, x); //rotate3 axis6
    sv1.wait();
    sv2.wait();
    sv3.wait();
    sv4.wait();
    sv5.wait();
    sv6.wait();


    rea();



    sv1.write(90, x); //rotate1 axis1
    sv2.write(90, x); //updown1 axis2
    sv3.write(90, x); //forbk   axis3
    sv4.write(90, x); //rotate2 axis4
    sv5.write(150, x); //updown2 axis5
    sv6.write(0, x); //rotate3 axis6
    sv1.wait();
    sv2.wait();
    sv3.wait();
    sv4.wait();
    sv5.wait();
    sv6.wait();

    rea();
  }
  else {
    digitalWrite(led, 0);
    sv1.write(90, x); //rotate1 axis1
    sv2.write(90, x); //updown1 axis2
    sv3.write(90, x); //forbk   axis3
    sv4.write(90, x); //rotate2 axis4
    sv5.write(150, x); //updown2 axis5
    sv6.write(90, x); //rotate3 axis6
    sv7.write(0, x); //gripper
  }
}
void test() {
  delay(1000);

  sv1.write(90, x); //rotate1 axis1
  sv2.write(10, x); //updown1 axis2  In progress
  sv3.write(150, x); //forbk   axis3  In progress
  sv4.write(90, x); //rotate2 axis4
  sv5.write(130, x); //updown2 axis5 In progress
  sv6.write(90, x); //rotate3 axis6
  sv7.write(0, x); //gripper
  sv1.wait();
  sv2.wait();
  sv3.wait();
  sv4.wait();
  sv5.wait();
  sv6.wait();
  sv7.wait();
  sv1.write(90, x); //rotate1 axis1
  sv2.write(120, x); //updown1 axis2  In progress
  sv3.write(80, x); //forbk   axis3  In progress
  sv4.write(90, x); //rotate2 axis4
  sv5.write(0, x); //updown2 axis5 In progress
  sv6.write(90, x); //rotate3 axis6
  sv7.write(180, x); //gripper
  sv1.wait();
  sv2.wait();
  sv3.wait();
  sv4.wait();
  sv5.wait();
  sv6.wait();
  sv7.wait();




}
void statusled() {
  unsigned long cur1 = millis();

  if (cur1 - pre1 >= 500) {
    // save the last time you blinked the LED
    pre1 = cur1;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(led, ledState);
  }

}
void rea () {
  Serial.print(manual1);
  Serial.print(" ");
  Serial.print(manual2);
  Serial.print(" ");
  Serial.print(manual3);
  Serial.print(" ");
  Serial.print(manual4);
  Serial.print(" ");
  Serial.print(manual5);
  Serial.print(" ");
  Serial.print(manual6);
  Serial.print(" ");
  Serial.print(manual7);
  Serial.print(" ");


  Serial.print(sv1.read());
  Serial.print(" ");
  Serial.print(sv2.read());
  Serial.print(" ");
  Serial.print(sv3.read());
  Serial.print(" ");
  Serial.print(sv4.read());
  Serial.print(" ");
  Serial.print(sv5.read());
  Serial.print(" ");
  Serial.print(sv6.read());
  Serial.print(" ");
  Serial.println(sv7.read());

}
void alarm1() {
  tone(buz, 25);
  delay(400);
  noTone(buz);
}
void alarm2() {
  while (l <= 5) {
    tone(buz, 25);
    delay(400);
    noTone(buz);
    delay(200);
    l++;
    if (l == 5) {

      l = 0;
    }
  }
}
