// LCD.cpp
#include "LCD.h"

LCD::LCD(int address, int columns, int rows) : lcd(address, columns, rows), numGameObjects(0), player(nullptr) {}

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
            delete gameObjects[i];
            for (int j = i; j < numGameObjects - 1; ++j)
            {
                gameObjects[j] = gameObjects[j + 1];
            }
            gameObjects[numGameObjects - 1] = nullptr;
            numGameObjects--;
            break;
        }
    }
}

void LCD::updateGameObjects()
{
    // Flag to check if there's a collision
    bool collisionDetected = false;

    // Update logic for game objects
    for (int i = 0; i < numGameObjects; ++i)
    {
        gameObjects[i]->update();
        Serial.print(" X : ");
        Serial.println(gameObjects[i]->getX());
        Serial.print(" Y : ");
        Serial.println(gameObjects[i]->getY());

        // Check for collision with Player
        if (gameObjects[i]->getX() == 0 && gameObjects[i]->getY() == player->getY())
        {
            Serial.println("Collision detected!");
            Serial.print(" X : ");
            Serial.println(gameObjects[i]->getX());
            Serial.print(" Y : ");
            Serial.println(gameObjects[i]->getY());
            collisionDetected = true;
            break; // Break out of the loop after detecting a collision
        }
    }

    // Print "GAME OVER" message if a collision is detected
    if (collisionDetected)
    {
        lcd.setCursor(0, 0);
        lcd.print("GAME OVER");
        delay(1000);
    }

    // Update the Player
    if (player != nullptr)
    {
        player->update();
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

void LCD::setPlayer(Player *p)
{
    player = p;
}
