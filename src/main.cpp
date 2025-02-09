#include <Arduino.h>
#define LED_PIN 23 // Red status LED
#define RELAY1_PIN 32
#define RELAY2_PIN 33
#define RELAY3_PIN 25
#define RELAY4_PIN 26
#define RELAY5_PIN 27
#define RELAY6_PIN 14
#define RELAY7_PIN 12
#define RELAY8_PIN 13

#define SERIAL_BAUD_RATE 9600 // Adjust according to your serial communication settings

void setup()
{
  // Set GPIOs for relays as output
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);
  pinMode(RELAY4_PIN, OUTPUT);
  pinMode(RELAY5_PIN, OUTPUT);
  pinMode(RELAY6_PIN, OUTPUT);
  pinMode(RELAY7_PIN, OUTPUT);
  pinMode(RELAY8_PIN, OUTPUT);

  // Set GPIO for LED as output
  pinMode(LED_PIN, OUTPUT);

  // Set relays and LED to LOW (relays off, LED off) initially
  digitalWrite(RELAY1_PIN, HIGH);
  digitalWrite(RELAY2_PIN, HIGH);
  digitalWrite(RELAY3_PIN, HIGH);
  digitalWrite(RELAY4_PIN, HIGH);
  digitalWrite(RELAY5_PIN, HIGH);
  digitalWrite(RELAY6_PIN, HIGH);
  digitalWrite(RELAY7_PIN, HIGH);
  digitalWrite(RELAY8_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);
  delay(500);

  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);
  digitalWrite(RELAY3_PIN, LOW);
  digitalWrite(RELAY4_PIN, LOW);
  digitalWrite(RELAY5_PIN, LOW);
  digitalWrite(RELAY6_PIN, LOW);
  digitalWrite(RELAY7_PIN, LOW);
  digitalWrite(RELAY8_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  // Start serial communication
  Serial.begin(SERIAL_BAUD_RATE);
}

void loop()
{
  // Check if any data is received on serial port
  if (Serial.available() > 0)
  {
    String command = Serial.readStringUntil('\n');
    command.trim(); // Remove any unwanted whitespace

    if (command == "11")
    {
      digitalWrite(RELAY1_PIN, HIGH);
    }
    else if (command == "10")
    {
      digitalWrite(RELAY1_PIN, LOW);
    }
    else if (command == "21")
    {
      digitalWrite(RELAY2_PIN, HIGH);
    }
    else if (command == "20")
    {
      digitalWrite(RELAY2_PIN, LOW);
    }
    else if (command == "31")
    {
      digitalWrite(RELAY3_PIN, HIGH);
    }
    else if (command == "30")
    {
      digitalWrite(RELAY3_PIN, LOW);
    }
    else if (command == "41")
    {
      digitalWrite(RELAY4_PIN, HIGH);
    }
    else if (command == "40")
    {
      digitalWrite(RELAY4_PIN, LOW);
    }
    else if (command == "51")
    {
      digitalWrite(RELAY5_PIN, HIGH);
    }
    else if (command == "50")
    {
      digitalWrite(RELAY5_PIN, LOW);
    }
    else if (command == "61")
    {
      digitalWrite(RELAY6_PIN, HIGH);
    }
    else if (command == "60")
    {
      digitalWrite(RELAY6_PIN, LOW);
    }
    else if (command == "71")
    {
      digitalWrite(RELAY7_PIN, HIGH);
    }
    else if (command == "70")
    {
      digitalWrite(RELAY7_PIN, LOW);
    }
    else if (command == "81")
    {
      digitalWrite(RELAY8_PIN, HIGH);
    }
    else if (command == "80")
    {
      digitalWrite(RELAY8_PIN, LOW);
    }
    else if (command == "91")
    {
      digitalWrite(LED_PIN, HIGH);
    }
    else if (command == "90")
    {
      digitalWrite(LED_PIN, LOW);
    }
    else if (command == "0")
    {
      digitalWrite(RELAY1_PIN, LOW);
      digitalWrite(RELAY2_PIN, LOW);
      digitalWrite(RELAY3_PIN, LOW);
      digitalWrite(RELAY4_PIN, LOW);
      digitalWrite(RELAY5_PIN, LOW);
      digitalWrite(RELAY6_PIN, LOW);
      digitalWrite(RELAY7_PIN, LOW);
      digitalWrite(RELAY8_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
    }
    else
    {
      Serial.println("Invalid command");
    }
  }
}
