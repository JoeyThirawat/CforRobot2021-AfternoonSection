int lightRead;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}
void loop()
{
  lightRead = analogRead(A0);
  Serial.println(lightRead);
  delay(5);
}
