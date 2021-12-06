#include <acllib.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "autoball.h"
#include "background.h"
#include "ball.h"
#include "callback.h"
#include "food.h"
#include "macro.h"
#include "shapedfood.h"
#include "thornball.h"
#include "userball.h"

int score=0;
userBall* myball;
background* bg;
Food* food[100];
ThornBall* thornball[5];
AutoBall* autoball[2];

int Setup(){
    initWindow("Sprite",0,0,winWidth,winHeight);
	initConsole();
	startTimer(0,1000);
	startTimer(1,10);
	
	//生成随机数序列
	srand((unsigned)time(NULL));
	int randColor=rand()%6;
	int randX=rand()%winWidth;
	int randY=rand()%winHeight;
	
	//创建对象
	bg=new background(20,RGB(54,51,52),RGB(70,70,70));
	myball=new userBall(20,randX,randY,(Color)randColor,5);
	for(int i=0;i<2;i++) 
		autoball[i]=new AutoBall(20,rand()%winWidth,
		rand()%winHeight,(Color)(rand()%6),1);
	for(int i=0;i<5;i++) 
		thornball[i]=new ThornBall(25,rand()%winWidth,
		rand()%winHeight,green);
	for(int i=0;i<100;i++){
		if(rand()%2==0)
			food[i]=new rFood((Color)(rand()%6),
			rand()%winWidth,rand()%winHeight,2);
		else 
			food[i]=new tFood((Color)(rand()%6),
			rand()%winWidth,rand()%winHeight,5);
	}
	myball->eatfood(food);
	//回调函数
	registerKeyboardEvent(KeyEvent);
	registerTimerEvent(TimeEvent);	
	return 0;
}