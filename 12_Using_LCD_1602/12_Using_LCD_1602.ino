/*********************************************************** 
Project 11: Using LCD Display
Description: Get print something Text on Your LCD Display
Company: Texoham eLearning Platform
Website: www.texoham.com/elearning
***********************************************************/ 

#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2); // CHANGE THE 0X3F ADDRESS TO YOUR SCREEN ADDRESS IF NEEDED
//LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2); 

/**********************************************************
 Connection for I2C Module
 VCC - 5v
 Gnd- Gnd
 SDA - A4
 SCL - A5
 ***********************************************************/
void setup()
{
  lcd.begin();
  lcd.backlight();
}
void loop() 
{
  lcd.setCursor(4, 0); 
  lcd.print("masatti"); 
  lcd.setCursor(4, 1); 
  lcd.print("saichara");
  delay(2000);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("sriindu");
  lcd.setCursor(4, 1); 
  lcd.print("siiet");
  delay(2000);  
}
