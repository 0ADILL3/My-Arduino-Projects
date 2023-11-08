#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int i,s,c,r;
int button1=2;
int button2=3;
int button3=4;
int hold;

void setup()
{
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(button3,INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  if(s==0) {home();}
  if(s==1) {opt1s();}
  if(s==2) {opt2s();}
  pb();
  cursor();
}

void opt1s()
{
  lcd.setCursor(1,0);
  lcd.print("opt.1");
  lcd.setCursor(1,1);
  lcd.print("opt.2");
  lcd.setCursor(9,0);
  lcd.print("opt.3");
  lcd.setCursor(9,1);
  lcd.print("opt.4");
  lcd.setCursor(c,r);
  lcd.print(">");
}
void pb()
{
  if((digitalRead(button1)==0) and (s==1))
  {
    if(hold==0)
    {
      i++;
      hold=1;
      lcd.clear();
      delay(100);
    }
  }
  else if((digitalRead(button2)==0) and (s<2))
  {
    if(hold==0)
    {
      s++;
      hold=1;
      lcd.clear();
      delay(100);
    }
  }
  else if((digitalRead(button3)==0) and (s>0))
  {
    if(hold==0)
    {
      s--;
      hold=1;
      lcd.clear();
      delay(100);
    }
  }
  else
  {
    hold=0;
  }
}
void opt2s()
{
  if((i==0) and (s==2))
  {opt1();}
  if((i==1) and (s==2))
  {opt2();}
  if((i==2) and (s==2))
  {opt3();}
  if((i==3) and (s==2))
  {opt4();}
}
void opt1()
{lcd.setCursor(0,0); lcd.print("this is opt1");}
void opt2()
{lcd.setCursor(0,0); lcd.print("this is opt2");}
void opt3()
{lcd.setCursor(0,0); lcd.print("this is opt3");}
void opt4()
{lcd.setCursor(0,0); lcd.print("this is opt4");}
void home()
{
  lcd.setCursor(3,0);
  lcd.print("WELLCOME!");
}
void cursor()
{
  if(i==0) {c=0; r=0;}
  else if(i==1) {c=0; r=1;}
  else if(i==2) {c=8; r=0;}
  else if(i==3) {c=8; r=1;}
  else {i=0;}
}