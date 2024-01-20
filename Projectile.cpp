// Projectile.cpp
#include "Projectile.h"

Projectile::Projectile(char sprite, int x, int y, uint8_t id, int speed)
    : GameObject(sprite, x, y, id), speed(speed)
{
    // Additional initialization if needed
}

void Projectile::update()
{
    // Update logic for the projectile
    // For example, move the projectile based on its speed
    x -= speed;
    if (x < 0)
    {
        x = 19;
    }
}
