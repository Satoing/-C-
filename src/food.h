#ifndef FOOD_H
#define FOOD_H
#include <acllib.h>
#include "macro.h"

class userBall;
class AutoBall;

class Food{
    friend class userBall;
    friend class AutoBall;
protected:
    Color _color;
    int _x,_y,_size;
    ACL_Color _Color;
public:
    Food(Color color,int x,int y,int size);
    virtual void paint()=0;
};
#endif