#include <LiquidCrystal_I2C_Hangul.h>
#include "sonar.h"
#include "lcd.h"
#include "Player.h"
#include "Projectile.h"
#define address 0x27
#define col 20
#define line 4

#define sonarTrigPin 12  // define TrigPin
#define sonarEchoPin 11  // define EchoPin.
#define MAX_DISTANCE 200 // Maximum sensor distance is rated at 400-500cm.
Sonar mySonar(sonarTrigPin, sonarEchoPin, MAX_DISTANCE);
LCD myLCD(address, col, line);
Player player('0', 0, 3, 1);
Projectile projectile('*', 5, 19, 2, 1); // Example values, adjust as needed

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.

  mySonar.begin();
  myLCD.begin();
  myLCD.addGameObject(&player);
  myLCD.addGameObject(&projectile);
}

void loop()
{
  float distance = mySonar.getDistance();
  player.setGlobalDistance(distance); // Could be done in a looser way
  myLCD.updateGameObjects();
  myLCD.drawScreen();
  delay(100);
}