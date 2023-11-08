#define trig 2
#define echo 3
float distance, time;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig,1);
  delay(1);
  digitalWrite(trig,0);
  time = pulseIn(echo,1);
  distance = time / 58.4775;
  //distance = (time / 2) * 0.0342;
  Serial.println((String)time + "\t\t" + (String)distance);
  delay(500);
}
