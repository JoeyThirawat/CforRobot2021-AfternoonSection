#include<LiquidCrystal.h>

#define RS 12
#define EN 11
#define D4 6
#define D5 7
#define D6 8
#define D7 9
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// Ultrasonic sensor
#define echoPin 5
#define trigPin 4
float duration;
int distance;

void setup() {

  lcd.begin(16, 2);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);  // Sets the echoPin as an INPUT
}

void loop() {

  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = (duration * 0.0343) / 2; // Speed of sound wave divided by 2 (go and back)

  lcd.clear();

  // Displays the distance on the LCD
  lcd.setCursor(0, 0);
  lcd.print("DIS:");
  lcd.setCursor(5, 0);
  lcd.print(distance);
  delay(10);
}
