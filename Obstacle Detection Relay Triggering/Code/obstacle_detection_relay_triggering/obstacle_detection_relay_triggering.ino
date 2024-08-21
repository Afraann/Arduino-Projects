
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);   // Mentioning the kind of LCD used along with the library we are using in this program

const int irPin = 13;                 // Pin 13 connected to digital output of IR sensor
const int relayPin = 3;               // Pin number 3 of arduino connected to Relay

int irState = 0;                      // Initialising to store the value of the variable
int relayState = 0;


void setup()
{
  pinMode(irPin, INPUT_PULLUP);       // Mentioning if the sensor in a input device or a output device
  pinMode(relayPin, OUTPUT);
  relayState = LOW;
  digitalWrite(relayPin, relayState);
  lcd.begin();                        // Initializing the LCD
  lcd.setCursor(0, 0);
  lcd.print("Obstacle");
  lcd.setCursor(0, 1);
  lcd.print("Detection");
  delay(3000);
}

void loop()
{
  irState = digitalRead(irPin);       // Check for Obstacle Detection----

  if (irState == HIGH)
  {
    relayState = LOW;
    digitalWrite(relayPin, relayState);
    lcd.clear();
    lcd.print("No Obstacle");         // Display this in first line
    lcd.setCursor(0, 1);
    lcd.print("Relay OFF");
    delay(500);                       //wait for 1000ms
  }

  if (irState == LOW)
  {
    relayState = HIGH;
    digitalWrite(relayPin, relayState);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Obstacle");            // Display this in first line
    lcd.setCursor(0, 1);
    lcd.print("Detected");
    delay(1000);
    lcd.clear();
    lcd.print("Relay ON");
    Serial.println("Obstacle Detected");
    delay(500);                       //wait for 1000ms
  }
}
