#ifndef BALL_H
#define BALL_H
#include <acllib.h>
#include "macro.h"

class Ball{
protected:
    int _radius,_x,_y;
    Color _color;
    ACL_Color _Color;
public:
    Ball(int r,int x,int y,Color color);
};
#endif