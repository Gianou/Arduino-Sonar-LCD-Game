// GameObject.h
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Arduino.h>

const int MAX_GAME_OBJECTS = 8;

class GameObject
{
public:
    GameObject(char sprite, int x, int y);
    GameObject();
    char getSprite() const;
    int getX() const;
    int getY() const;
    void setSprite(char newSprite);
    void setX(int newX);
    void setY(int newY);
    virtual void update();

private:
    char sprite;
    int x;
    int y;
};

#endif
