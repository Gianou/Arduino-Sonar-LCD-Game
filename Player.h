#ifndef PLAYER_H
#define PLAYER_H

#include <Arduino.h>
#include "GameObject.h"

class Player : public GameObject
{
public:
    Player(char sprite, int x, int y, uint8_t id);

    // Specific update method for player (optional)
    void update() override;
    void setGlobalDistance(float distance);

private:
    // Static member variable to store the global distance
    static float globalDistance;
};

#endif
