#ifndef SONAR_H
#define SONAR_H

class Sonar
{
public:
    Sonar(int trigPin, int echoPin, int maxDistance);
    void begin();
    float getDistance();

private:
    int trigPin;
    int echoPin;
    int maxDistance;
    float timeOut;
    int soundVelocity;
};

#endif
