#include <LiquidCrystal_I2C.h>
#include <DS3231.h>
#include <Wire.h>

DS3231  rtc(SDA, SCL);



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

Time  t;

#define buz 4

int Hor;

int Min;

int Sec;

void setup()
{
   Wire.begin();

  rtc.begin();


   Serial.begin(9600);

  pinMode(buz, OUTPUT);

  lcd.begin(16,2);     

  lcd.setCursor(0,0);

  lcd.print("DIYHacking.com");

  lcd.setCursor(0,1);

  lcd.print("Arduino Alarm ");

  // The following lines can be uncommented to set the date and time

  //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY

  //rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)

  //rtc.setDate(1, 1, 2014);   // Set the date to January 1st, 2014

  delay(2000);



  // lcd.init(); // Initialize the LCD I2C display
  // lcd.backlight();

  // lcd.createChar(0, customChar); // create a new custom character

  // lcd.setCursor(2, 0); // move cursor to (2, 0)
  // lcd.write((byte)0);  // print the custom char at (2, 0)
}

void loop()
{
  t = rtc.getTime();

  Hor = t.hour;

  Min = t.min;

  Sec = t.sec;

  lcd.setCursor(0,0);

  lcd.print("Time: ");

  lcd.print(rtc.getTimeStr());

 lcd.setCursor(0,1);

 lcd.print("Date: ");

 lcd.print(rtc.getDateStr());
}
