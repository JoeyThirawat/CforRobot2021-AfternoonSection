#include<LiquidCrystal.h>

#define RS 12
#define EN 11
#define D4 6
#define D5 7
#define D6 8
#define D7 9

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Hello Robot CLUB");
  lcd.setCursor(6, 1);
  lcd.print("KMITL");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("1");
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("2");
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("3");
  delay(500);

  lcd.setCursor(0, 0);
  for (int i = 4; i <= 8; i++) {
    lcd.print(i);
    delay(500);
  }
  lcd.clear();
}
