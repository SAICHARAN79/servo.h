#include <LiquidCrystal_I2C.h>
//#include <LiquidCrystal.h>

const int echoPin = 2;            // arduino 5th pin connected to echo Pin in the ultrasonic distance sensor
const int trigPin = 3; 
const int cm =15;// arduino 7th pin connected to trig Pin in the ultrasonic distance sensor
LiquidCrystal_I2C lcd(0x27, 16, 2);
//LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2);
//LiquidCrystal lcd(4, 6, 10, 11, 12, 13);   
void setup() 
{
  pinMode(echoPin, INPUT);       //Set the connection pin output mode Echo pin
  pinMode(trigPin, OUTPUT);      //Set the connection pin output mode Trig pin
  lcd.begin();              //set up the LCD's number of columns and rows: 
  lcd.clear();                   //Clears the LCD screen and positions the cursor in the upper-left corner 
  delay(1000);//delay 1000ms
} 

void loop() 
{ 
  
  int cm = echo(echoPin) ;
  if(cm<15){ 
  lcd.setCursor(0, 0);           // set the cursor to column 0, line 0
  lcd.print(" maintain distance    ");
  lcd.setCursor(0,1);
  lcd.print("distance=");
  lcd.print(cm);
  lcd.print("cm");
  delay(2000);
  lcd.clear();
}// Print a message of "TEXOHAM: "to the LCD.
  else if(cm>15)
  {
  lcd.setCursor(0, 0);           // set the cursor to column 0, line 0
  lcd.print("begood "); 
  lcd.setCursor(0,1);
  lcd.print("distance=");
  lcd.print(cm);// Print a message of "TEXOHAM: "to the LCD.                // Print a centimeter distance to the LCD. 
  lcd.print("cm");          // Print a centimeter distance to the LCD.
  delay(500);
  }
}
     
int echo(int echoPin) 
{ 
  // establish variables for duration of the Echo, 
  // and the distance result in inches and centimeters: 
  long duration, cm; 
  // The Echo))) is triggered by a HIGH pulse of 2 or more microseconds. 
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse: 
  pinMode(trigPin, OUTPUT); 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(5); 
  digitalWrite(trigPin, LOW); 
  
  pinMode(echoPin, INPUT); 
  duration = pulseIn(echoPin, HIGH); 
  
  // convert the time into a distance 
  cm = microsecondsToCentimeters(duration); 
  return cm ; 
} 

long microsecondsToCentimeters(long microseconds) 
{
   // The speed of sound is 340 m/s or 29 microseconds per centimeter. 
   // The Echo travels out and back, so to find the distance of the 
   // object we take half of the distance travelled. 
   return microseconds / 29 / 2; 
} 
