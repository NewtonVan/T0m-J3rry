#include "acllib.h"
#include "AutoSprite.h"
#include "UsrSprite.h"
#include "AvoidSprite.h"
#include "EnemySprite.h"
#include "HistoryBase.h"
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxNum= 1<<6;
const int winWidth= 800, winHeight= 600;

CAutoSprite *autosprite[maxNum]= {0};
CUsrSprite *usr= NULL;
HistoryBase *record[10+3];
int autoWidth= 100, autoHeight= 100;
int usrWidth= 100, usrHeight= 100;
int nowNum= 0, rk= 0, gdt= 1578239999;
ACL_Image img, imgUsr, imgHeart, imgEnm;
rect winRect;

void CreateData(CAutoSprite **autospt);
void CreateData(CUsrSprite **usr);
void TimerEvent(int id);
void Paint();
void KeyEvent(int key, int event);
void GameOver();
void ReadRecord();
void WriteRecord();

int Setup()
{
	winRect.x= winRect.y= DEFAULT;
	winRect.width= winWidth;
	winRect.height= winHeight;
	initWindow("Tom.Eureka.Newton's game", DEFAULT, DEFAULT, winWidth, winHeight);
	srand((unsigned)time(NULL));
	ReadRecord();

	loadImage(".\\picture\\jerry.bmp", &img);
	loadImage(".\\picture\\tom.bmp", &imgUsr);
	loadImage(".\\picture\\duck.jpg", &imgHeart);
	loadImage(".\\picture\\dog.bmp", &imgEnm);

	CreateData(autosprite);
	CreateData(&usr);
	registerTimerEvent(TimerEvent);
	registerKeyboardEvent(KeyEvent);
	startTimer(0, 40);
	startTimer(1, 1000);

	WriteRecord();

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
	if (t< 70){
		autospt[nowNum++]= new CAutoSprite(x, y, autoWidth, autoHeight, dx, dy, &img, winRect, 1);
	}
	else if (t< 90){
		autospt[nowNum++]= new CAvoidSprite(x, y, autoWidth, autoHeight, dx, dy, &imgHeart, winRect, 5);
	}
	else{
		autospt[nowNum++]= new CEnemySprite(x, y, autoWidth, autoHeight, dx, dy, &imgEnm, winRect, 7);
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
char aa[]= { 72, 52, 99, 107, 51, 114, 32, 73, 100, 33, 48, 116, 78, 51, 0};
void TimerEvent(int id)
{
	int i= 0; 
	switch(id){
		case 0:
			for (i= 0; i< nowNum; ++i){
				if (autosprite[i]){
					rect ur= usr->getRect();
					if (autosprite[i]->Bite(ur)){
						usr->LoseHealth(1);
						if (usr->ShowHealth()<= 0){
							GameOver();
						}
					}
					autosprite[i]->move(ur);
				}
			}
			if (0== usr->ShoeFade()){
				usr->RushOff();
			}
			break;
		case 1:
			if (nowNum< maxNum){
				CreateData(autosprite);
			}
			if (0== usr->ShoeFade()){
				usr->RushOff();
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

		char txt[30];
		setTextSize(16);
		sprintf(txt, "Score Record: %d", record[0]->GetScore());
		paintText(10, 5, txt);
		sprintf(txt, "Score:  %d", usr->getScore());
		paintText(10, 20, txt);
		if (time(0)>= gdt){
			paintText(671, 575, aa);
		}
		sprintf(txt, "Helath: %d", usr->ShowHealth());
		paintText(10, 35, txt);
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
				if (0== autosprite[i]->ShowHealth()){	
					delete(autosprite[i]);
					autosprite[i]= NULL;
				}
			}
		}
	}
	Paint();
}
void GameOver()
{
	WriteRecord();
	exit(0);
}
void ReadRecord()
{
	char tm[23];
	int scr;
	FILE *fp;
	fp= fopen(".\\History\\rank.txt", "r");
	while ('\n'!= fgetc(fp)){
		continue;
	}
	while ('\n'!= fgetc(fp)){
		continue;
	}
	while (EOF!= fscanf(fp, "%s %d", tm, &scr) && rk< 10){
		record[rk++]= new HistoryBase(tm, scr);
	}
	fclose(fp);
}
void WriteRecord()
{
	FILE *fp;
	int scr= usr->getScore(), i= rk, lb= min(rk+1, 10);
	char tm[23];

	sprintf(tm, "%d", time(0));
	record[rk]= new HistoryBase(tm, scr);
	while (i> 0 &&  *record[i-1]< *record[i]){
		HistoryBase *tmp= record[i];
		record[i]= record[i-1];
		record[i-1]= tmp;
		--i;
	}

	fp= fopen(".\\History\\record.txt", "a");
	fputc('\n', fp);
	fprintf(fp, "%s\t%d", tm, scr);
	fclose(fp);

	fp= fopen(".\\History\\rank.txt", "w");
	fprintf(fp, "Top 10 Rank:\n");
	fprintf(fp, "Time\t\tScore\n");
	for (i= 0; i< lb; ++i){
		fprintf(fp, "%s\t%d\n", record[i]->GetTime(), record[i]->GetScore());
	}
	fclose(fp);
}