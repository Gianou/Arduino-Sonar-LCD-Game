#include "Player.h"
float Player::globalDistance = 0.0;

Player::Player(char sprite, int x, int y) : GameObject(sprite, x, y) {}

void Player::update()
{
    int max = 40;
    if (globalDistance == 0)
    {
        return;
    }

    if (globalDistance < max / 4)
    {
        setY(3);
    }
    else if (globalDistance < max / 2)
    {
        setY(2);
    }
    else if (globalDistance < max / 4 * 3)
    {
        setY(1);
    }
    else if (globalDistance < max)
    {
        setY(0);
    }
}

void Player::setGlobalDistance(float distance)
{
    // Set the global distance from outside the class
    globalDistance = distance;
}
