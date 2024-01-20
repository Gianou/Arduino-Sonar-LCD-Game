// Projectile.h
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameObject.h"

class Projectile : public GameObject
{
public:
    Projectile(char sprite, int x, int y, int speed);

    // Override the update method for projectile-specific behavior
    void update() override;
    int getSpeed() const;

private:
    int speed; // Speed of the projectile
};

#endif
