// GameObject.cpp
#include "GameObject.h"

GameObject::GameObject(char sprite, int x, int y, uint8_t id)
    : sprite(sprite), x(x), y(y), id(id), isPlayer(false) {}

GameObject::GameObject(char sprite, int x, int y, uint8_t id, bool isPlayer)
    : sprite(sprite), x(x), y(y), id(id), isPlayer(isPlayer) {}

GameObject::GameObject() : sprite(' '), x(0), y(0), id(0), isPlayer(false) {}

char GameObject::getSprite() const
{
    return sprite;
}

int GameObject::getX() const
{
    return x;
}

int GameObject::getY() const
{
    return y;
}

uint8_t GameObject::getId() const
{
    return id;
}

bool GameObject::getIsPlayer() const
{
    return isPlayer;
}

void GameObject::update()
{
    // Update logic for the game object
    // For example, adjust x, y based on some criteria
}
