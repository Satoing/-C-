#include "autoball.h"

AutoBall::AutoBall(int r,int x,int y,Color color,int speed):
Ball(r,x,y,color),_speed(speed){
    _speedX=_speed;
    _speedY=_speed;
    paint();
}
void AutoBall::paint(){
        beginPaint();
            setPenColor(_Color);
            setBrushColor(_Color);
            ellipse(_x-_radius,_y+_radius,_x+_radius,_y-_radius);
        endPaint();
}
void AutoBall::SBD(){
    if((_x-_radius)<0||(_x+_radius)>= winWidth)
        _speedX*=-1;
	if((_y-_radius)<0||(_y+_radius)>= winHeight)
        _speedY*=-1;
}
void AutoBall::move(){
    SBD();
    _x+=_speedX;
    _y-=_speedY;
    paint();
}
void AutoBall::eatfood(Food** food){
    int flag=0;
    for(int i=0;i<100;i++){
        if(food[i]==nullptr) continue;
        if(sqrt(fabs(_x-food[i]->_x)+
        fabs(_y-food[i]->_y))<=0.2*_radius){
            delete food[i];
            food[i]=nullptr;
            flag++;
        }
    }
    if(_radius<=30) _radius+=flag;
}