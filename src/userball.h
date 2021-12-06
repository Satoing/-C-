#ifndef USERBALL_H
#define USERBALL_H
#include <acllib.h>
#include <iostream>
#include <cmath>
#include "ball.h"
#include "macro.h"
#include "shapedfood.h"
#include "thornball.h"
#include "autoball.h"

extern int score;

class userBall:public Ball{
private:
    int _speed;
public:
    userBall(int r,int x,int y,Color color,int speed);
    void paint();
    bool SBD();
    void move(int key,int event);
    void eatfood(Food** food);
    void Stung(ThornBall** thornball);
    void eatball(AutoBall** autoball);
};
#endif