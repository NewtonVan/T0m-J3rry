#ifndef UsrSprite_h
#define UsrSprite_h

#include "SpriteBase.h"

class CUsrSprite :
public SpriteBase
{
	int score;
	int health;
	struct Shield{
		int times;
		int num;
		Shield(){}
		Shield(int t, int n) : times(t), num(n) {}
	}shield;
	struct Weapon{
		int times;
		int num;
		Weapon(){}
		Weapon(int t, int n) : times(t), num(n) {}
	}weapon;
	struct Rush{
		int time;
		int shoes;
		Rush(){}
		Rush(int t, int s) : time(t), shoes(s){}
	}rush;
public:
	CUsrSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1);
	CUsrSprite(CUsrSprite &spt);
	~CUsrSprite();

	void GetPrize(int type);
	void move(int key);
	void move(rect r);
	void RushOn();
	void RushOff();
	
	int ShoeFade();
	int collision(rect r1);
	int getScore();
	int setScore(int s);
	int addScore(int s);
	int ShowHealth();
	int AddHealth(int h);
	int LoseHealth(int h);
	int Equipped();
	int Protected();
	int GetWeapon();
	int LoseWeapon();
	int GetShield();
	int LoseShield();
	int GetShoes();
};

#endif