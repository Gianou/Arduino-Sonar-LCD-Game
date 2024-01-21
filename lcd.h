// LCD.h
#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <LiquidCrystal_I2C_Hangul.h>
#include "GameObject.h"
#include "Player.h"

class LCD
{
public:
    LCD(int address, int columns, int rows);
    void begin();
    void drawScreen();
    void drawGameObject(GameObject *obj);
    void drawPlayer(Player *player);
    void updateGameObjects();
    void addGameObject(GameObject *gameObject);
    void setPlayer(Player *player); // New method to set the Player
    void setAmountOfSpawnedProjectiles(int newNumbGameObjects);

private:
    LiquidCrystal_I2C_Hangul lcd;
    GameObject *gameObjects[MAX_GAME_OBJECTS];
    int amountOfSpawnedProjectiles;
    int amountOfLoadedProjectiles;
    int score;
    byte playerSprite[8];
    Player *player;
};

#endif
