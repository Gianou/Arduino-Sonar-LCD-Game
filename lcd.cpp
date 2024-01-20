#include "LCD.h"

LCD::LCD(int address, int columns, int rows) : lcd(address, columns, rows), numGameObjects(0)
{
    // Initialize gameObjects array elements
    for (int i = 0; i < MAX_GAME_OBJECTS; ++i)
    {
        gameObjects[i] = nullptr;
    }
}

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
}

void LCD::drawGameObject(GameObject *obj)
{
    lcd.setCursor(obj->getX(), obj->getY());
    lcd.print(obj->getSprite());
}

void LCD::removeGameObject(uint8_t id)
{
    for (int i = 0; i < numGameObjects; ++i)
    {
        if (gameObjects[i]->getId() == id)
        {
            // Shift remaining elements to fill the gap
            for (int j = i; j < numGameObjects - 1; ++j)
            {
                gameObjects[j] = gameObjects[j + 1];
            }
            delete gameObjects[numGameObjects - 1];    // Delete the removed object
            gameObjects[numGameObjects - 1] = nullptr; // Set the last element to nullptr
            numGameObjects--;
            break;
        }
    }
}

void LCD::updateGameObjects()
{
    // Update logic for game objects
    for (int i = 0; i < numGameObjects; ++i)
    {
        gameObjects[i]->update();
    }
}

void LCD::addGameObject(GameObject *obj)
{
    if (numGameObjects < MAX_GAME_OBJECTS)
    {
        gameObjects[numGameObjects] = obj;
        numGameObjects++;
    }
    // If the array is full, you may want to handle this case or provide feedback.
}
