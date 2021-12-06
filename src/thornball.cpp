#include "thornball.h"

ThornBall::ThornBall(int r,int x,int y,Color color):
Ball(r,x,y,color){paint();}
void ThornBall::paint(){
    POINT p[]={{(int)(_x),(int)(_y-_radius*sqrt(3))},
    {(int)(_x+_radius/2),(int)(_y-_radius*sqrt(3)/2)},
    {(int)(_x+_radius*3/2),(int)(_y-_radius*sqrt(3)/2)},
    {(int)(_x+_radius),(int)(_y)},
    {(int)(_x+_radius*3/2),(int)(_y+_radius*sqrt(3)/2)},
    {(int)(_x+_radius/2),(int)(_y+_radius*sqrt(3)/2)},
    {(int)(_x),(int)(_y+_radius*sqrt(3))},
    {(int)(_x-_radius/2),(int)(_y+_radius*sqrt(3)/2)},
    {(int)(_x-_radius*3/2),(int)(_y+_radius*sqrt(3)/2)},
    {(int)(_x-_radius),(int)(_y)},
    {(int)(_x-_radius*3/2),(int)(_y-_radius*sqrt(3)/2)},
    {(int)(_x-_radius/2),(int)(_y-_radius*sqrt(3)/2)}};
    beginPaint();
        setPenColor(_Color);
        setBrushColor(_Color);
        polygon(p,12);
    endPaint();
}