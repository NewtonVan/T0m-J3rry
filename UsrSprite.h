#ifndef UsrSprite_h
#define UsrSprite_h

#include "SpriteBase.h"
#include "Ball.h"

class CUsrSprite :
public SpriteBase
{
	int score;
	int health;
	struct Weapon{
		int num;
		CBall *head, *tail;
		Weapon(){}
		Weapon(int n) : num(n) 
		{
			head= new CBall(0, 0, 0, 0, 0, 0, NULL, {0, 0, 0, 0});
			tail= head;
		}
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
	void UseWeapon(ACL_Image *img, int w, int h, int ddx, int ddy);
	void UseOutWeapon(CBall *wpn);
	
	CBall* ShowWeaponHead();

	int ShoeFade();
	int collision(rect r1);
	int getScore();
	int setScore(int s);
	int addScore(int s);
	int ShowHealth();
	int AddHealth(int h);
	int LoseHealth(int h);
	int Equipped();
	int SpeedUp();
	int GetWeapon();
	int GetShoes();

};

#endif