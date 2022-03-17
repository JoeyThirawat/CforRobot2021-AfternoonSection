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

  for (int i = 0; i < 20; i++)
  {
    lcd.setCursor(0, 0);
    lcd.print(i);
    delay(500);
  }
  lcd.clear();

}
