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
    void print(String message);
    void drawScreen();
    void drawGameObject(GameObject *obj);
    void removeGameObject(uint8_t id);
    void updateGameObjects();
    void addGameObject(GameObject *gameObject);
    void setPlayer(Player *player); // New method to set the Player

private:
    LiquidCrystal_I2C_Hangul lcd;
    GameObject *gameObjects[MAX_GAME_OBJECTS];
    int numGameObjects;
    Player *player; // Pointer to Player
};

#endif
