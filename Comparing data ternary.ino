int a,pot;
String b;
void setup()
{
  Serial.begin(9600);
  pinMode(pot, INPUT);
}

void loop()
{
  a=analogRead(pot);
  b=(a>512) ? "more" : "less";
  Serial.print("compare : ");
  Serial.print(a);
  Serial.print(" : ");
  Serial.print("512");
  Serial.println(" result : " + (String)b);
  delay(500);
}
