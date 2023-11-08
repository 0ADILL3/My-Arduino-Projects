#define in2 2
int numRandom,hold;
void setup()
{
  Serial.begin(9600);
  pinMode(in2,INPUT_PULLUP);
}

void loop()
{
  if(digitalRead(in2)==0)
  {
    if(hold==0)
    {
      numRandom=random(0,100);
      hold=1;
      Serial.println(numRandom);
      delay(100);
    }
  }
  else {hold=0;}
}
