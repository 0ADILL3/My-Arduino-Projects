int in2=2;
int i,hold,sample;
void setup()
{
  Serial.begin(9600);
  pinMode(in2, INPUT_PULLUP);
}

void loop()
{
  for(i=0;i<=100;i++)
  {
    pb();
    delay(1);
  }
}
void pb()
{
  if(digitalRead(in2)==0)
  {
    if(hold==0)
    {
      sample=i;
      Serial.println(sample);
      hold=1;
      delay(100);
    }
  }
  else {hold=0;}
}