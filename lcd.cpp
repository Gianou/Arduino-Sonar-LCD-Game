// LCD.cpp
#include "LCD.h"

LCD::LCD(int address, int columns, int rows) : lcd(address, columns, rows),
                                               amountOfSpawnedProjectiles(2),
                                               amountOfLoadedProjectiles(0),
                                               player(nullptr),
                                               score(0),
                                               playerSprite{
                                                   0b01000,
                                                   0b11100,
                                                   0b11111,
                                                   0b01000,
                                                   0b11111,
                                                   0b11100,
                                                   0b01000,
                                                   0b00000} {}

void LCD::begin()
{
    lcd.init();
    lcd.backlight();
    lcd.print("LCD started.");
    delay(3000);
    lcd.clear();
    // Upload the custom heart character
    lcd.createChar(0, playerSprite);
}

void LCD::drawScreen()
{
    lcd.clear();
    // Call draw on all game objects
    for (int i = 0; i < amountOfSpawnedProjectiles; ++i)
    {
        drawGameObject(gameObjects[i]);
    }

    // Draw the Player separately
    if (player != nullptr)
    {
        drawPlayer(player);
    }

    // Draw score
    lcd.setCursor(15, 0);
    lcd.print(score);

    lcd.setCursor(10, 2);
}

void LCD::drawGameObject(GameObject *obj)
{
    lcd.setCursor(obj->getX(), obj->getY());
    lcd.print(obj->getSprite());
}

void LCD::drawPlayer(Player *player)
{
    lcd.setCursor(player->getX(), player->getY());
    lcd.write(0);
}

void LCD::updateGameObjects()
{
    // Flag to check if there's a collision
    bool collisionDetected = false;

    // Update logic for game objects
    for (int i = 0; i < amountOfSpawnedProjectiles; ++i)
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
        score = 0;
        amountOfSpawnedProjectiles = 2;
    }
    else
    {
        // Update the Player
        if (player != nullptr)
        {
            player->update();
        }
    }

    // Score increment to keep track of the frames elapsed in the game
    score++;

    // "Spawn" new projectiles
    if (score % 55 == 0 && amountOfSpawnedProjectiles < MAX_GAME_OBJECTS)
    {
        amountOfSpawnedProjectiles++;
    }
}

void LCD::addGameObject(GameObject *obj)
{
    if (amountOfLoadedProjectiles < MAX_GAME_OBJECTS)
    {
        gameObjects[amountOfLoadedProjectiles] = obj;
        amountOfLoadedProjectiles++;
    }
    // If the array is full, you may want to handle this case or provide feedback.
}

void LCD::setPlayer(Player *p)
{
    player = p;
}

void LCD::setAmountOfSpawnedProjectiles(int newNumbGameObjects)
{
    amountOfSpawnedProjectiles = newNumbGameObjects;
}
