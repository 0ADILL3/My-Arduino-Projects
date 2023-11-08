#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define pot1 A2
#define pot2 A3
#define vSinAnalogPin1 A0
#define vSinAnalogPin2 A1
#define vSinPWMPin1 10
#define vSinPWMPin2 11
float pi = 3.1415926535897;
int deg1, deg2;
int vSinAnalog, vSinPWM;
int frequency1, frequency2;
bool turn1, turn2;
unsigned long time1, time2;

void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(vSinAnalogPin1, OUTPUT);
  pinMode(vSinAnalogPin2, OUTPUT);
  pinMode(vSinPWMPin1, OUTPUT);
  pinMode(vSinPWMPin2, OUTPUT);
}

void loop()
{
  frequency1 = map(analogRead(pot1),0,1023,2750,46);
  frequency2 = map(analogRead(pot2),0,1023,2750,46);

  if((micros() - time1 >= frequency1) and (turn1 == 0))
  {
    deg1++;
    vSinAnalog = 255 * sin(deg1 * pi / 180);
    analogWrite(vSinAnalogPin1,vSinAnalog);
    if(deg1 >= 180)
    {
      turn1 = 1;
    }//printLcd();
    time1 = micros();
  }
  if((micros() - time1 >= frequency1) and (turn1 == 1))
  {
    deg1--;
    vSinAnalog = 255 * sin(deg1 * pi / 180);
    analogWrite(vSinAnalogPin2,vSinAnalog);
    if(deg1 <= 0)
    {
      turn1 = 0;
    }//printLcd();
    time1 = micros();
  }
}

void printLcd()
{
  lcd.setCursor(0,0);
  lcd.print(vSinAnalog);
}