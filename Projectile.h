// Projectile.h
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameObject.h"

class Projectile : public GameObject
{
public:
    Projectile(char sprite, int x, int y, uint8_t id, int speed);

    // Override the update method for projectile-specific behavior
    void update() override;

private:
    int speed; // Speed of the projectile
};

#endif
