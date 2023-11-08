#define pot A0
int val,data1,delta;
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
    delta = val - data1;
    (val == data1) ? Serial.print("equal ") : NULL;
    (val > data1) ? Serial.print("greater +") : NULL;
    (val < data1) ? Serial.print("less ") : NULL;
    Serial.println(delta);
    data1 = val;
    preTime = millis();
  }
}