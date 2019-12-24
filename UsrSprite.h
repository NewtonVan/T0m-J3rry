#ifndef UsrSprite_h
#define UsrSprite_h

#include "SpriteBase.h"

class CUsrSprite :
public SpriteBase
{
	int score;
/*	int health;
	int weapon;*/
public:
	CUsrSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1);
	CUsrSprite(CUsrSprite &spt);
	~CUsrSprite();

	void move(int key);
	void move(rect r);

	int collision(rect r1);
	int getScore();
	int setScore(int s);
	int addScore(int s);
};

#endif