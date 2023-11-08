int clock = 10;
int reset = 9;
void setup()
{
  pinMode (clock,OUTPUT);
  pinMode (reset,OUTPUT);
  digitalWrite (reset,1);
}

void loop()
{
  digitalWrite (clock,1);
  delay(100);
  digitalWrite (clock,0);
  delay(100);
}
