#define pot A0
int val,data1,data2,delta;
unsigned long preTime;

void setup()
{
  pinMode(pot,INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(pot);
  if(millis() - preTime >= 100)
  {
    data1 = val;
    delta = data1 - data2;
    (delta == 0) ? Serial.print("equal ") : NULL;
    (delta > 0) ? Serial.print("greater +") : NULL;
    (delta < 0) ? Serial.print("less ") : NULL;
    Serial.println(delta);
    data2 = data1;
    preTime = millis();
  }
}