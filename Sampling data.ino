#include <LiquidCrystal.h>
LiquidCrystal lcd(4,5,6,7,8,9);
int pot = A0;
int valDelay;
int sample;
void setup()
{
  lcd.begin(16,2);
  pinMode(pot, INPUT);
}

void loop()
{
  valDelay=analogRead(pot);
  lcd.setCursor(0,0);
  lcd.print(valDelay);
  lcd.setCursor(7,0);
  lcd.print(sample);
  if(sample != valDelay)
  {
    delay(10);
    sample=valDelay;
  }
  else if(sample == valDelay)
  {
    lcd.setCursor(0,1);
    lcd.print("_ ");
    delay(valDelay);
    lcd.setCursor(0,1);
    lcd.print(" _");
    delay(valDelay);
  }
}