// Projectile.cpp
#include "Projectile.h"

Projectile::Projectile(char sprite, int x, int y, int speed)
    : GameObject(sprite, x, y), speed(speed)
{
    // Additional initialization if needed
}

int Projectile::getSpeed() const
{
    return speed;
}

void Projectile::update()
{
    // Update logic for the projectile
    // For example, move the projectile based on its speed
    setX(getX() - getSpeed());
    if (getX() < 0)
    {
        setX(19);
    }
}
