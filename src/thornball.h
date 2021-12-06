#ifndef THORNBALL_H
#define THORNBALL_H
#include "ball.h"
#include <cmath>

class userBall;
class AutoBall;

class ThornBall:public Ball{
    friend class userBall;
    friend class AutoBall;
public:
    ThornBall(int r,int x,int y,Color color);
    void paint();
};
#endif