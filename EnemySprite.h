#ifndef EnemySprite_h
#define EnemySprite_h

#include "AutoSprite.h"
class CEnemySprite
: public CAutoSprite
{
	int attack;
	int health;
protected:
	bool Hitd();
public:
	CEnemySprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1, int score);
	CEnemySprite(CEnemySprite &spt);
	~CEnemySprite();

	void move(rect ur);

	bool Bite(rect ur);
	int BHurtd();
	int ShowHealth();
	
};

#endif