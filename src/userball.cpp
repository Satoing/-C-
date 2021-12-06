#include "userball.h"

userBall::userBall(int r,int x,int y,Color color,int speed):
Ball(r,x,y,color),_speed(speed){
    paint();
}
void userBall::paint(){
    beginPaint();
        setPenColor(_Color);
        setBrushColor(_Color);
        ellipse(_x-_radius,_y+_radius,_x+_radius,_y-_radius);
    endPaint();
}
bool userBall::SBD(){
    if((_x-_radius)<0){
        _x+=_speed;
        return false;
    }
    if((_x+_radius)> winWidth){
        _x-=_speed;
        return true;
    }
	if((_y-_radius)<0){
        _y+=_speed;
        return false;
    }
    if((_y+_radius)> winHeight){
        _y-=_speed;
        return false;
    }
    return true;
}
void userBall::move(int key,int event){
    if(event!=KEY_DOWN||!SBD()) {
        paint();
        return;
    }
    if(key==0x41) _x-=_speed;
    if(key==0x44) _x+=_speed;
    if(key==0x57) _y-=_speed;
    if(key==0x53) _y+=_speed;
    paint();
}
void userBall::eatfood(Food** food){
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
    if(_radius<=40) _radius+=flag;
}

void userBall::eatball(AutoBall** autoball){
    for(int i=0;i<2;i++){
        if(autoball[i]==nullptr) continue;
        if(_radius<=autoball[i]->_radius) continue;
        if(sqrt(fabs(_x-(autoball[i]->_x))+
        fabs(_y-(autoball[i]->_y)))<=0.2*_radius){
            delete autoball[i];
            autoball[i]=nullptr;
            score++;
        }
    }
}

void userBall::Stung(ThornBall** thornball){
    for(int i=0;i<5;i++){
        if(sqrt(fabs(_x-thornball[i]->_x)+
        fabs(_y-thornball[i]->_y))<=0.2*_radius){
            std::cout<<"Your score is: "<<score<<'\n';
            msgBox("结束","You are died",0);
            exit(0);
        }
    }
}