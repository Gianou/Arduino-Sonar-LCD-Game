// GameObject.cpp
#include "GameObject.h"

GameObject::GameObject(char sprite, int x, int y)
    : sprite(sprite), x(x), y(y) {}

GameObject::GameObject() : sprite(' '), x(0), y(0) {}

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

void GameObject::setSprite(char newSprite)
{
    sprite = newSprite;
}

void GameObject::setX(int newX)
{
    x = newX;
}

void GameObject::setY(int newY)
{
    y = newY;
}

void GameObject::update()
{
    // Update logic for the game object
    // For example, adjust x, y based on some criteria
}
