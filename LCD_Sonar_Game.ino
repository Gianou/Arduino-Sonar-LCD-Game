#include <LiquidCrystal_I2C_Hangul.h>
#include "Sonar.h"
#include "LCD.h"
#include "Player.h"
#include "Projectile.h"
#define address 0x27
#define col 20
#define line 4

#define sonarTrigPin 12  // define TrigPin
#define sonarEchoPin 11  // define EchoPin.
#define MAX_DISTANCE 200 // Maximum sensor distance is rated at 400-500cm.

#define FRAME_LENGTH 100

Sonar mySonar(sonarTrigPin, sonarEchoPin, MAX_DISTANCE);
LCD myLCD(address, col, line);
Player player('0', 0, 3);

Projectile projectiles[] = {
    Projectile('-', 19, 0, 1),
    Projectile('-', 9, 2, 1),
    Projectile('-', 19, 1, 1),
    Projectile('-', 19, 3, 1),
    Projectile('-', 19, 2, 1),
    Projectile('-', 19, 1, 1),
    Projectile('-', 19, 3, 1),
    Projectile('-', 19, 2, 1)};

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.

  mySonar.begin();
  myLCD.begin();
  myLCD.setPlayer(&player);
  // Create an array of pointers to Projectile
  Projectile *projectilePointers[] = {&projectiles[0], &projectiles[1], &projectiles[2], &projectiles[3], &projectiles[4], &projectiles[5], &projectiles[6], &projectiles[7]};

  // Pass the array of pointers to the setProjectiles function
  myLCD.setProjectiles(projectilePointers);
}

void loop()
{
  myLCD.drawScreen();
  float distance = mySonar.getDistance();
  player.setGlobalDistance(distance); // Could be done in a looser way
  myLCD.updateGameObjects();

  delay(FRAME_LENGTH);
}