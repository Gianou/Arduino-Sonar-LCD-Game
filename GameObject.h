#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Arduino.h>

const int MAX_GAME_OBJECTS = 10;

class GameObject
{
public:
    GameObject(char sprite, int x, int y, uint8_t id);
    GameObject();
    char getSprite() const;
    int getX() const;
    int getY() const;
    uint8_t getId() const;
    virtual void update();

public:
    char sprite;
    int x;
    int y;
    uint8_t id;
};

#endif
