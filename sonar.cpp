#include <Arduino.h>
#include "sonar.h"

Sonar::Sonar(int trigPin, int echoPin, int maxDistance)
    : trigPin(trigPin), echoPin(echoPin), maxDistance(maxDistance), timeOut(maxDistance * 60), soundVelocity(340)
{
    // Constructor implementation, if needed
}

void Sonar::begin()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float Sonar::getDistance()
{
    unsigned long pingTime;
    float distance;
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pingTime = pulseIn(echoPin, HIGH, timeOut);
    distance = (float)pingTime * soundVelocity / 2 / 10000;
    return distance;
}
