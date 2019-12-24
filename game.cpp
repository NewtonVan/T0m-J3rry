#include "acllib.h"
#include "AutoSprite.h"
#include "UsrSprite.h"
#include "AvoidSprite.h"
#include <ctime>
#include <cstdio>
using namespace std;

const int maxNum= 50;
const int winWidth= 800, winHeight= 600;
CAutoSprite *autosprite[maxNum]= {0};
CUsrSprite *usr= NULL;
int autoWidth= 100, autoHeight= 100;
int usrWidth= 100, usrHeight= 100;
ACL_Image img, imgUsr, imgHeart;
rect winRect;
int nowNum= 0;

void CreateData(CAutoSprite **autospt);
void CreateData(CUsrSprite **usr);
void TimerEvent(int id);
void Paint();
void KeyEvent(int key, int event);

int Setup()
{
	winRect.x= winRect.y= DEFAULT;
	winRect.width= winWidth;
	winRect.height= winHeight;
	initWindow("Tom.Eureka.Newton's game", DEFAULT, DEFAULT, winWidth, winHeight);
	srand((unsigned)time(NULL));

	loadImage("jerry.bmp", &img);
	loadImage("tom.bmp", &imgUsr);
	loadImage("duck.jpg", &imgHeart);

	CreateData(autosprite);
	CreateData(&usr);
	registerTimerEvent(TimerEvent);
	registerKeyboardEvent(KeyEvent);
	startTimer(0, 40);
	startTimer(1, 1000);

	return 0;
}

void CreateData(CAutoSprite **autospt)
{
	int x= rand()%winWidth-autoWidth;
	int y= rand()%winHeight-autoHeight;
	int dx= rand()%5+1, dy= rand()%5+1;
	if (x< 0){
		x= 0;
	}
	if (y< 0){
		y= 0;
	}
;
	int t= rand()%100;
	if (t< 80){
		autospt[nowNum++]= new CAutoSprite(x, y, autoWidth, autoHeight, dx, dy, &img, winRect, 1);
	}
	else{
		autospt[nowNum++]= new CAvoidSprite(x, y, autoWidth, autoHeight, dx, dy, &imgHeart, winRect, 5);
	}
}
void CreateData(CUsrSprite **usr)
{
	int x= rand()%winWidth-usrWidth;
	int y= rand()%winHeight-usrHeight;
	int dx=5, dy= 5;
	if (x< 0){
		x= 0;
	}
	if (y< 0){
		y= 0;
	}

	*usr= new CUsrSprite(x, y, usrWidth, usrHeight, dx, dy, &imgUsr, winRect);
}
void TimerEvent(int id)
{
	int i= 0; 
	switch(id){
		case 0:
			for (i= 0; i< nowNum; ++i){
				if (autosprite[i]){
					rect ur= usr->getRect();
					autosprite[i]->move(ur);
				}
			}
			break;
		case 1:
			if (nowNum< maxNum){
				CreateData(autosprite);
			}
			break;
		default:
			break;
	}
	Paint();
}
void Paint()
{
	beginPaint();
	clearDevice();
	int i= 0;
	for (i= 0; i< nowNum; ++i){
		if (autosprite[i]){
			autosprite[i]->drawSprite();
		}
	}
	if (usr){
		usr->drawSprite();

		char txt[10];
		sprintf(txt, "%d", usr->getScore());
		setTextSize(20);
		paintText(10, 10, txt);
	}
	endPaint();
}
void KeyEvent(int key, int event)
{
	if (KEY_DOWN!= event){
		return;
	}

	if (usr){
		usr->move(key);
	}
	for (int i= 0; i< nowNum; ++i){
		if (autosprite[i]){
			if (usr->collision(autosprite[i]->getRect())){
				int s= autosprite[i]->getScore();
				if (usr){
					usr->addScore(s);
				}
				delete(autosprite[i]);
				autosprite[i]= NULL;
			}
		}
	}
	Paint();
}