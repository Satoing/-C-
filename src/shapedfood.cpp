#include "shapedfood.h"

rFood::rFood(Color color,int x,int y,int size):
Food(color,x,y,size){
    paint();
}
void rFood::paint(){
    POINT p[]={{(int)(_x-sqrt(2)*_size),(int)(_y+sqrt(2)*_size)},
                {(int)(_x+sqrt(2)*_size),(int)(_y+sqrt(2)*_size)},
                {(int)(_x+sqrt(2)*_size),(int)(_y-sqrt(2)*_size)},
                {(int)(_x-sqrt(2)*_size),(int)(_y-sqrt(2)*_size)}};
    beginPaint();
        setPenColor(_Color);
        setBrushColor(_Color);
        polygon(p,4);
    endPaint();
}

tFood::tFood(Color color,int x,int y,int size):
Food(color,x,y,size){
    paint();
}
void tFood::paint(){
    POINT p[]={{(int)(_x),(int)(_y-_size)},
    {(int)(_x-sqrt(3)*_size/2),(int)(_y+_size/2)},
    {(int)(_x+sqrt(3)*_size/3),(int)(_y+_size/2)}};
    beginPaint();
        setPenColor(_Color);
        setBrushColor(_Color);
        polygon(p,3);
    endPaint();
}