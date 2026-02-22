#include <Arduino.h>
#include <SerLCD.h> //Click here to get the library: http://librarymanager/All#SparkFun_SerLCD
#include <Servo.h>
#include <Wire.h>

#include "avr8-stub.h"

SerLCD display; // Initialize the library with default I2C address 0x72

int potentiometer_position; // this variable will store the position of the
                            // potentiometer
int servo_position;         // the servo will move to this position

Servo servo_motor; // create a servo object

void setup() {
    debug_init();
    Wire.begin();

    display.begin(Wire); // Set up the LCD for I2C communication

    display.setBacklight(255, 255, 255); // Set backlight to bright white
    display.setContrast(5); // Set contrast. Lower to 0 for higher contrast.

    display.clear(); // Clear the display - this moves the cursor to home
                     // position as well
    display.print("Hello, World!");

    // tell the servo object that its servo is plugged into pin 9
    servo_motor.attach(9);
    servo_position = 0;
}

void loop() {
    // Set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    display.setCursor(0, 1);
    // Print the number of seconds since reset:
    potentiometer_position = ((millis() / 100) % 180);
    display.println(potentiometer_position);
    // servoPosition = map(potPosition, 0, 180, 20, 160) % 160; // convert the
    // potentiometer number to a servo position from 20-160 Note: its best to
    // avoid driving the little SIK servos all the way to 0 or 180 degrees it
    // can cause the motor to jitter, which is bad for the servo.
    servo_motor.write(15); // goes to 15 degrees
    delay(1000);           // wait for a second

    servo_motor.write(30); // goes to 30 degrees
    delay(1000);           // wait for a second.33

    servo_motor.write(45); // goes to 45 degrees
    delay(1000);           // wait for a second.33

    servo_motor.write(60); // goes to 60 degrees
    delay(1000);           // wait for a second.33

    servo_motor.write(75); // goes to 75 degrees
    delay(1000);           // wait for a second.33

    servo_motor.write(90); // goes to 90 degrees
    delay(1000);           // wait for a second

    servo_motor.write(75); // back to 75 degrees
    delay(1000);           // wait for a second.33

    servo_motor.write(60); // back to 60 degrees
    delay(1000);           // wait for a second.33

    servo_motor.write(45); // back to 45 degrees
    delay(1000);           // wait for a second.33

    servo_motor.write(30); // back to 30 degrees
    delay(1000);           // wait for a second.33

    servo_motor.write(15); // back to 15 degrees
    delay(1000);           // wait for a second

    servo_motor.write(0); // back to 0 degrees
    delay(1000);          // wait for a second
    for (int num = 0; num <= 180; num++) {
        servo_motor.write(num); // back to 'num' degrees(0 to 180)
        delay(10);              // control servo speed
    }
    for (int num = 180; num >= 0; num--) {
        servo_motor.write(num); // back to 'num' degrees(180 to 0)
        delay(10);              // control servo speed
    }
}