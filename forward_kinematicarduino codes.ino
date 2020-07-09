#include <Servo.h>
#include <LiquidCrystal.h>
Servo servo_12;
Servo servo_13;
LiquidCrystal lcd (11, 10, 5, 4 , 3, 2);
//Q are the angles in radian
//q are the angles in degrees 
//L are the lengths in inches 
int L1 = 10;
int L2 = 10;
int q1 = 60;
int q2 = 30; 
float Q1= (60*PI)/180;  
float Q2= (30*PI)/180;
float x;
float y;

void setup()
{
  //Set number of rows and columns for LCD
  lcd.begin(16,2);
  servo_12.attach(12);
  servo_13.attach(13);
  x = ( L1 * cos ( Q1 )) + ( L2 * cos ( Q1 + Q2 )); 
  y = ( L1 * sin ( Q1 )) + ( L2 * sin ( Q1 + Q2 )); 
  Serial.begin(9600); 
}

void loop()
{
  servo_12.write(q1);
  servo_13.write(q2);
  delay(20); // Wait for 20 millisecond(s)
  lcd.setCursor (0,1);
  lcd.print ("x=");
  lcd.setCursor (4,1);
  lcd.print (x);
  delay(3000);
  lcd.setCursor (0,1);
  lcd.print ("y=");
  lcd.setCursor (4,1);
  lcd.print (y);
  delay(3000);
}