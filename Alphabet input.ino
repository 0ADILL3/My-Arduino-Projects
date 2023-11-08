#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int cUpB=5;
int cDownB=4;
int nextB=3;
int backB=2;
int s,hold;
unsigned int c;
String chara;
unsigned long prevTime;

void setup()
{
  pinMode(cUpB,INPUT_PULLUP);
  pinMode(cDownB,INPUT_PULLUP);
  pinMode(nextB,INPUT_PULLUP);
  pinMode(backB,INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  button();
  alphabet();
  writeLcd();
}

void button()
{
  if(digitalRead(cUpB) == 0)
  {
    if(hold == 0)
    {
      prevTime=millis();
      c++;
      hold=1;
      delay(100);
      hold=0;
    }
  }
  else if(digitalRead(cDownB) == 0)
  {
    if(hold == 0)
    {
      prevTime=millis();
      c--;
      hold=1;
      delay(100);
      hold=0;
    }
  }
  else if(digitalRead(nextB) == 0)
  {
    if(hold == 0)
    {
      lcd.setCursor(s,0);
      lcd.print(chara);
      s++;
      c=0;
      hold=1;
      delay(100);
      hold=0;
    }
  }
  else if(digitalRead(backB) == 0)
  {
    if(hold == 0)
    {
      s--;
      c=0;
      hold=1;
      delay(100);
      hold=0;
    }
  }
  else {hold=0;}
}
void alphabet()
{
  switch(c)
  {
    case 0: chara=" "; break;
    case 1: chara="A"; break;
    case 2: chara="B"; break;
    case 3: chara="C"; break;
    case 4: chara="D"; break;
    case 5: chara="E"; break;
    case 6: chara="F"; break;
    case 7: chara="G"; break;
    case 8: chara="H"; break;
    case 9: chara="I"; break;
    case 10: chara="J"; break;
    case 11: chara="K"; break;
    case 12: chara="L"; break;
    case 13: chara="M"; break;
    case 14: chara="N"; break;
    case 15: chara="O"; break;
    case 16: chara="P"; break;
    case 17: chara="Q"; break;
    case 18: chara="R"; break;
    case 19: chara="S"; break;
    case 20: chara="T"; break;
    case 21: chara="U"; break;
    case 22: chara="V"; break;
    case 23: chara="W"; break;
    case 24: chara="X"; break;
    case 25: chara="Y"; break;
    case 26: chara="Z"; break;
    case 27: c=0; break;
    case 65535: c=26; break;
  }
}
void writeLcd()
{
  if(millis() == 0)
  {
    prevTime=0;
  }
  else if(millis() - prevTime < 100)
  {
    lcd.setCursor(s,0);
    lcd.print("_");
  }
  else if(millis() - prevTime < 200)
  {
    lcd.setCursor(s,0);
    lcd.print(chara);
  }
  else
  {
    prevTime=millis();
  }
}