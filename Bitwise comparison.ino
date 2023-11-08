void setup()
{
  Serial.begin(9600);
}
void loop()
{
  for (int bits=0;bits<8;bits++)
  {
    ((0b00111100 >> bits) & 1) ?
    Serial.println(1) : Serial.println(0);
    delay(500);
  }
}