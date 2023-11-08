#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(13,12,11,10,9,8);
Servo servo;
int ser = 6;
int pot = A0;

int temp;
float kP = 1;
float kI = 0.2;
float kD = 0.1;
float P,I,D;
int effort;
int setPoint = 70;
int Error,preError;
int sigmaError;
int deltaError;
unsigned long preTime;

void setup()
{
  lcd.begin(20,4);
  servo.attach(ser);
  pinMode(pot,INPUT);
  servo.write(0);
}

void loop()
{
  temp = map(analogRead(pot),0,1023,0,100);
  if(millis() - preTime >= 100)
  {
    Error = setPoint - temp;
    sigmaError += Error;
    deltaError = Error - preError;
    P = kP * Error;
    I = kI * sigmaError;
    D = kD * deltaError;
    effort = (P + I + D);
    servo.write(effort);
    preError = Error;
    prints();
    preTime = millis();
  }
}

void prints()
{
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("PID CONTROLLER");
  lcd.setCursor(0,1);
  lcd.print("temp=" + (String)temp + "'");
  lcd.setCursor(11,1);
  lcd.print("deg=" + (String)effort + "'");
  lcd.setCursor(0,2);
  lcd.print("eff=" + (String)effort);
  lcd.setCursor(11,2);
  lcd.print("error=" + (String)Error);
  lcd.setCursor(0,3);
  lcd.print("sigma=" + (String)sigmaError);
  lcd.setCursor(11,3);
  lcd.print("delta=" + (String)deltaError);
}