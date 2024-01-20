// LCD.cpp
#include "LCD.h"

LCD::LCD(int address, int columns, int rows) : lcd(address, columns, rows),
                                               numGameObjects(2),
                                               currentAmountOfProjectiles(0),
                                               player(nullptr),
                                               timeTracker(0) {}

void LCD::begin()
{
    lcd.init();
    lcd.backlight();
    lcd.print("LCD started.");
    delay(3000);
    lcd.clear();
}

void LCD::print(String message)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message);
}

void LCD::drawScreen()
{
    lcd.clear();
    // Call draw on all game objects
    for (int i = 0; i < numGameObjects; ++i)
    {
        drawGameObject(gameObjects[i]);
    }

    // Draw the Player separately
    if (player != nullptr)
    {
        drawGameObject(player);
    }

    // Draw timeTracker
    lcd.setCursor(15, 0);
    lcd.print(timeTracker);
}

void LCD::drawGameObject(GameObject *obj)
{
    lcd.setCursor(obj->getX(), obj->getY());
    lcd.print(obj->getSprite());
}

void LCD::updateGameObjects()
{
    // Flag to check if there's a collision
    bool collisionDetected = false;

    // Update logic for game objects
    for (int i = 0; i < numGameObjects; ++i)
    {

        // Check for collision with Player
        if (gameObjects[i]->getX() == 0 && gameObjects[i]->getY() == player->getY())
        {
            collisionDetected = true;
        }

        gameObjects[i]->update();
    }

    // Print "GAME OVER" message if a collision is detected
    if (collisionDetected)
    {
        lcd.setCursor(5, 1);
        lcd.print("GAME OVER");
        lcd.setCursor(player->getX(), player->getY());
        lcd.print("X");
        delay(3000);
        // reset
        timeTracker = 0;
        numGameObjects = 2;
    }
    else
    {
        // Update the Player
        if (player != nullptr)
        {
            player->update();
        }
    }
    timeTracker++;
    if (timeTracker % 55 == 0 && numGameObjects < MAX_GAME_OBJECTS)
    {
        numGameObjects++;
    }
}

void LCD::addGameObject(GameObject *obj)
{
    if (currentAmountOfProjectiles < MAX_GAME_OBJECTS)
    {
        gameObjects[currentAmountOfProjectiles] = obj;
        currentAmountOfProjectiles++;
    }
    // If the array is full, you may want to handle this case or provide feedback.
}

void LCD::setPlayer(Player *p)
{
    player = p;
}

void LCD::setNumGameObjects(int newNumbGameObjects)
{
    numGameObjects = newNumbGameObjects;
}
