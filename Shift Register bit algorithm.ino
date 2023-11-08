unsigned long timer;
int input = 2;
int x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, xIn;

void setup()
{
  Serial.begin(9600);
  pinMode(input, INPUT_PULLUP);
}

void loop()
{
  (digitalRead(input) == 0) ? xIn = 1 : xIn = 0;
  if(millis() - timer >= 500)
  {
    x1 = x2;
    x2 = x3;
    x3 = x4;
    x4 = x5;
    x5 = x6;
    x6 = x7;
    x7 = x8;
    x8 = x9;
    x9 = x10;
    x10 = xIn;
    Serial.print(x1);
    Serial.print(x2);
    Serial.print(x3);
    Serial.print(x4);
    Serial.print(x5);
    Serial.print(x6);
    Serial.print(x7);
    Serial.print(x8);
    Serial.print(x9);
    Serial.print(x10);
    Serial.println();
    timer = millis();
  }
}
