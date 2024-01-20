#include "Player.h"
float Player::globalDistance = 0.0;

Player::Player(char sprite, int x, int y, uint8_t id) : GameObject(sprite, x, y, id)
{
}

void Player::update()
{
    int max = 40;
    if (globalDistance == 0)
    {
        return;
    }

    if (globalDistance < max / 4)
    {
        y = 3;
    }
    else if (globalDistance < max / 2)
    {
        y = 2;
    }
    else if (globalDistance < max / 4 * 3)
    {
        y = 1;
    }
    else if (globalDistance < max)
    {
        y = 0;
    }
}

void Player::setGlobalDistance(float distance)
{
    // Set the global distance from outside the class
    globalDistance = distance;
}
