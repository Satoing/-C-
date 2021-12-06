#ifndef SHAPEDFOOD_H
#define SHAPEDFOOD_H
#include <acllib.h>
#include <cmath>
#include "food.h"

class rFood:public Food{
public:
    rFood(Color color,int x,int y,int size);
    void paint();
};

class tFood:public Food{
public:
    tFood(Color color,int x,int y,int size);
    void paint();
};
#endif