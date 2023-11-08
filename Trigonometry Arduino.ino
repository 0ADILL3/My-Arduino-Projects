#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#define pot A0
float vSin, vCos, vTan, rad;
float pi = 3.1415926535897;
int deg1, deg2;

void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(pot,INPUT);
}

void loop()
{
  deg1 = map(analogRead(pot),0,1023,0,360);
  rad = deg1 * pi / 180;
  vSin = sin(rad);
  vCos = cos(rad);
  if((deg1 != 90) and (deg1 != 270))
  {
    vTan = tan(rad);
  }
  else
  {
    vTan = 0;
  }
  if(deg1 != deg2) {lcd.clear();}
  lcd.setCursor(0,0);
  lcd.print("degree : " + String(deg1) + "'");
  lcd.setCursor(0,1);
  lcd.print("vSin   : " + String(vSin));
  lcd.setCursor(0,2);
  lcd.print("vCos   : " + String(vCos));
  lcd.setCursor(0,3);
  if((deg1 != 90) and (deg1 != 270))
  {
    lcd.print("vTan   : " + String(vTan));
  }
  else
  {
    lcd.print("vTan   : invalid");
  }
  deg2 = deg1;
}