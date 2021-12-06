#ifndef AUTOBALL_H
#define AUTOBALL_H
#include <acllib.h>
#include <cmath>
#include "ball.h"
#include "food.h"

class userBall;

class AutoBall:public Ball{
    friend class userBall;
private:
    int _speed,_speedX,_speedY;
public:
    AutoBall(int r,int x,int y,Color color,int speed);
    void paint();
    void SBD();
    void move();
    void eatfood(Food** food);
};
#endif