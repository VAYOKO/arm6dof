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
int angles_A[6] {90, 90, 90, 90, 90, 90};
int max_angles_A[6] { 180, 180, 180, 180, 180, 180};
int min_angles_A[6] { 0, 0, 0, 0, 0, 0};
int max_x = 30, max_y = 30, max_z = 30;
int min_x = 30, min_y = 30, min_z = 30;
int round_A=0;
int x , y , z;
int spd = 10;
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


}
void loop() {
  para1();
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 180; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;
  angles_A[1] = 90; angles_A[2] = 90; angles_A[3] = 90; angles_A[4] = 90; angles_A[5] = 90; angles_A[6] = 90; control_A();round_A++;


}
void para1() {
  if (max_angles_A[3] == angles_A[3]) {
    Serial.print("ERR");

  }
  angles_A[3] -= angles_A[2] - x + y;
  angles_A[2] += x;
  angles_A[3] += y;
  read_angles();
}
void control_A() {
  Serial.println(round_A);
  sv1.write(angles_A[1], spd); //rotate1 axis1
  sv2.write(angles_A[2], spd); //updown1 axis2
  sv3.write(angles_A[3], spd); //forbk   axis3
  sv4.write(angles_A[4], spd); //rotate2 axis4
  sv5.write(angles_A[5], spd); //updown2 axis5
  sv6.write(angles_A[6], spd); //rotate3 axis6
  sv7.write(90, spd); //gripper
  sv1.wait();
  sv2.wait();
  sv3.wait();
  sv4.wait();
  sv5.wait();
  sv6.wait();
  sv7.wait();

}
void read_angles() {
  Serial.print(angles_A[2]);
  Serial.print(" ");
  Serial.print("x");
  Serial.print(" ");
  Serial.print(x);

  Serial.print(" ");
  Serial.print("y");
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.println(angles_A[3]);
}
