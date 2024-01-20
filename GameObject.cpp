#include "GameObject.h"

GameObject::GameObject(char sprite, int x, int y, uint8_t id)
    : sprite(sprite), x(x), y(y), id(id) {}

GameObject::GameObject()
{
    // Implementation for default constructor
}

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

void GameObject::update()
{
    // Update logic for the game object
    // For example, adjust x, y based on some criteria
}
