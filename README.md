# LCD Sonar Game

This Arduino project is a simple game that uses an Arduino Uno, an HC-SR04 ultrasonic sensor (sonar), and a 2004A LCD with I2C interface to create an interactive experience.
The player controls a character on the LCD screen using the ultrasonic sensor, and their goal is to avoid incoming projectiles.

## Components:

- Arduino Uno
- HC-SR04 Ultrasonic Sensor (Sonar)
- 2004A LCD with I2C Interface (20x4)

## Installation:

1. Clone or download the repository to your local machine.
2. Open the Arduino IDE.
3. Load the `LCD_Sonar_Game.ino` sketch.
4. Connect your Arduino Uno to your computer.
5. Choose the correct board (Arduino Uno) and port in the Arduino IDE.
6. Upload the sketch to your Arduino Uno.

## Wiring:

- Connect the HC-SR04 Ultrasonic Sensor Trig pin to Arduino pin 12.
- Connect the HC-SR04 Ultrasonic Sensor Echo pin to Arduino pin 11.
- Connect the HC-SR04 Ultrasonic Sensor VCC pin to Arduino 5V.
- Connect the HC-SR04 Ultrasonic Sensor GND pin to Arduino GND.

- Connect the 2004A I2C LCD to Arduino pins A4 (SDA) and A5 (SCL).
- Connect the 2004A I2C LCD VCC pin to Arduino 5V.
- Connect the 2004A I2C LCD GND pin to Arduino GND.

## Gameplay:

- Use the HC-SR04 Ultrasonic Sensor to control the Ship on the LCD screen.
- The Ship changes lane according to the distance between your hand and the sensor.
- Avoid collisions with incoming asteroids.
- Your score is the distance you travel, it is displayed on the top right of the screen.
- The game end when the Ship collides with an asteroid.
- The will automatically restart after a while.

