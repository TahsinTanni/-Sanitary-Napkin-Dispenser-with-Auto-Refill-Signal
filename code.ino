#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Create servo object
Servo myservo;

// Define pins
const int buttonPin = 10;  // Button connected to digital pin 10
const int irPin = 8;       // IR sensor connected to digital pin 8
int lastButtonState = HIGH;
bool isAtZero = true;

// Initialize LCD (I2C address 0x27, 16 columns x 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  myservo.attach(9);                 // Attach servo to pin 9
  myservo.write(0);                  // Start at 0 degrees
  pinMode(buttonPin, INPUT_PULLUP); // Button with pull-up
  pinMode(irPin, INPUT);            // IR sensor input

  lcd.init();      
  lcd.backlight(); 
  lcd.setCursor(2, 0);
  lcd.print("System Ready");
}

void loop() {
  int irState = digitalRead(irPin);

  // If IR sensor is LOW, show "Please Refill" and halt other operations
  if (irState == LOW) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Please Refill");
    delay(1000); // Delay to prevent flickering
    return; // Skip the rest of the loop
  }

  // If IR is HIGH, continue with normal system behavior
  int buttonState = digitalRead(buttonPin);

  // Handle button press (falling edge)
  if (lastButtonState == HIGH && buttonState == LOW) {
    if (isAtZero) {
      myservo.write(180);
      isAtZero = false;
    } else {
      myservo.write(0);
      isAtZero = true;
    }

    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Please Collect");
    lcd.setCursor(4, 1);
    lcd.print("Your Pad");

    delay(2000); // Show message for 2 seconds

    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("System Ready");

    delay(200); // Debounce delay
  }

  lastButtonState = buttonState;
}
