#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int up=2;
int down=3;
int reset=4;
int counter=0;
void setup()
{
  pinMode(up, INPUT); digitalWrite(up,1);
  pinMode(down, INPUT); digitalWrite(down,1);
  pinMode(reset, INPUT); digitalWrite(reset,1);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  pushButton();
  lcd.setCursor(0,0);
  lcd.print(counter);
}

void pushButton()
{
  if(digitalRead(up)==0)
  {
    lcd.clear();
    counter++;
    delay(100);
    while(digitalRead(up)==0) {}
  }
  else if(digitalRead(down)==0)
  {
    lcd.clear();
    counter--;
    delay(100);
    while(digitalRead(down)==0) {}
  }
  else if(digitalRead(reset)==0)
  {
    lcd.clear();
    counter=0;
    delay(100);
    while(digitalRead(reset)==0) {}
  }
}
