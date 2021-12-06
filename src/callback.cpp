#ifndef CALLBACK_H
#define CALLBACK_H
#include "userball.h"
#include "background.h"
#include "food.h"
#include "thornball.h"
#include "autoball.h"

extern userBall* myball;
extern background* bg;
extern Food* food[100];
extern ThornBall* thornball[5];
extern AutoBall* autoball[2];

void KeyEvent(int key,int event){
	myball->move(key,event);
	myball->eatfood(food);
	myball->eatball(autoball);
	myball->Stung(thornball);
	for(int i=0;i<5;i++){
		thornball[i]->paint();
	}
}

void TimeEvent(int id){
	if(id==0){
		for(int i=0;i<100;i++){
			if(food[i]==nullptr)
				if(rand()%2==0)
				food[i]=new rFood((Color)(rand()%6),
				rand()%winWidth,rand()%winHeight,2);
			else 
				food[i]=new tFood((Color)(rand()%6),
				rand()%winWidth,rand()%winHeight,4);
		}
		for(int i=0;i<2;i++){
			if(autoball[i]==nullptr)
				autoball[i]=new AutoBall(20,rand()%winWidth,
				rand()%winHeight,(Color)(rand()%6),1);
		}
	}
	if(id==1){
		bg->paintbg();
		for(int i=0;i<100;i++){
			if(food[i]==nullptr) continue;
			food[i]->paint();
		}
		for(int i=0;i<2;i++){
			if(autoball[i]==nullptr) continue;
			autoball[i]->move();
			autoball[i]->eatfood(food);
		}
		myball->eatfood(food);
		myball->eatball(autoball);
		myball->paint();
		for(int i=0;i<5;i++){
			thornball[i]->paint();
		}
	}
}
#endif