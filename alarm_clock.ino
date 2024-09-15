#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

byte customChar[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};

void setup()
{
  lcd.init(); // Initialize the LCD I2C display
  lcd.backlight();

  lcd.createChar(0, customChar); // create a new custom character

  lcd.setCursor(2, 0); // move cursor to (2, 0)
  lcd.write((byte)0);  // print the custom char at (2, 0)
}

void loop()
{
}
