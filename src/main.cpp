#include <Arduino.h>
#include <Wire.h>
#include <SerLCD.h> //Click here to get the library: http://librarymanager/All#SparkFun_SerLCD
#include "avr8-stub.h"
#include "app_api.h" // only needed with flash breakpoints

void setup()
{
  // put your setup code here, to run once:
  debug_init();
  Wire.begin();

  lcd.begin(Wire); // Set up the LCD for I2C communication

  lcd.setBacklight(255, 255, 255); // Set backlight to bright white
  lcd.setContrast(5);              // Set contrast. Lower to 0 for higher contrast.

  lcd.clear(); // Clear the display - this moves the cursor to home position as well
  lcd.print("Hello, World!");
}

void loop()
{
  // put your main code here, to run repeatedly:
  // Set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // Print the number of seconds since reset:
  lcd.println(millis() / 1000);
}