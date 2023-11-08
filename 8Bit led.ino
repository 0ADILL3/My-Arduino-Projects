int led[8] = {2,3,4,5,6,7,8,9};
byte data = 0b00111100;

void setup()
{
  for(int pins=0;pins<8;pins++)
  {
    pinMode(led[pins], OUTPUT);
  }
}

void loop()
{
  for(int bits=0;bits<8;bits++)
  {
    ((data >> bits) & 1) ? digitalWrite(led[bits],1) : digitalWrite(led[bits],0) ;
  }
}
