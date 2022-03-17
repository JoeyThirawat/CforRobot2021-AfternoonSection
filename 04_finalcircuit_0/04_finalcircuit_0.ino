#include <LiquidCrystal.h>

//photoresistor
int lightRead;

//ultrasonic
#define echoPin 5
#define trigPin 6
float duration;
int distance;

//LCD
#define RS 13
#define EN 12
#define D4 11
#define D5 4
#define D6 3
#define D7 2
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

//motor
int enA = 10;
int in1 = 9;
int in2 = 8;
float spdFloat = 0;
int spd = 0;

void setup()
{
  //photoresistor
  pinMode(A0, INPUT);

  //ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //LCD
  lcd.begin(16, 2);

  //motor
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  Serial.begin(9600);
}

void loop()
{
  lightRead = analogRead(A0);

  if (lightRead < 365)
  {
    spd = 0;
  }
  else
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration * 0.0343) / 2;

    spdFloat = map(distance, 100, 250, 0, 255);
    spd = round(spdFloat);
    if (spd > 255)
    {
      spd = 255;
    }
    else if (spd < 0)
    {
      spd = 0;
    }
  }

  lcd.setCursor(0, 0);
  lcd.print("DIST:");
  lcd.setCursor(7, 0);
  lcd.print(distance);
  lcd.setCursor(11, 0);
  lcd.print("cm.");

  lcd.setCursor(0, 1);
  lcd.print("SPEED:");
  lcd.setCursor(7, 1);
  lcd.print(spd);
  Serial.println(spd);
  motor1(spd);
  //Serial.println((int)spd);

  delay(100);
  lcd.clear();
}

void motor1(int motor1_speed)
{
  if (motor1_speed < 0)
  {
    analogWrite(enA, abs(motor1_speed));
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  else
  {
    analogWrite(enA, abs(motor1_speed));
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
}
