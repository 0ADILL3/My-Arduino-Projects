int led = 2;
unsigned long preTime;
int blink;
void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  if(millis() - preTime >= 1000) {preTime=millis();}
  blink = (millis() - preTime <= 500) ? 0 : 1;
  digitalWrite(led,blink);
}
