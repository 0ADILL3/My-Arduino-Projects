#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define i0 2
#define i1 3
#define i2 4
#define i3 5
int v0=0;
int v1=1;
int v2=2;
int v3=3;
int s,hold,b,s0,s1,s2,s3;
void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(i0, INPUT_PULLUP);
  pinMode(i1, INPUT_PULLUP);
  pinMode(i2, INPUT_PULLUP);
  pinMode(i3, INPUT_PULLUP);
}

void loop()
{
  pbVal();
  pbS();
  blink();
}
void pbVal()
{
  if(digitalRead(i0)==0)
  {
    s0=v0;
    lcd.setCursor(s,0);
    lcd.print(s0);
  }
  else if(digitalRead(i1)==0)
  {
    s1=v1;
    lcd.setCursor(s,0);
    lcd.print(s1);
  }
  else if(digitalRead(i2)==0)
  {
    s2=v2;
    lcd.setCursor(s,0);
    lcd.print(s2);
  }
  else if(digitalRead(i3)==0)
  {
    s3=v3;
    lcd.setCursor(s,0);
    lcd.print(s3);
  }
}
void pbS()
{
  if((digitalRead(i0)==0) or (digitalRead(i1)==0) or (digitalRead(i2)==0) or (digitalRead(i3)==0))
  {
    if(hold==0)
    {
      s++;
      hold=1;
      delay(100);
    }
  }
  else
  {
    hold=0;
  }
}
void blink()
{
  if(b==0)
  {
    lcd.setCursor(s,0);
    lcd.print("_");
    delay(100);
    b=1;
  }
  else if(b==1)
  {
    lcd.setCursor(s,0);
    lcd.print(" ");
    delay(100);
    b=0;
  }
}