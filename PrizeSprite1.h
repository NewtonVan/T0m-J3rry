#ifndef PrizeSprite1_h
#define PrizeSprite1_h

#include "PrizeSprite1.h"
#include "AvoidSprite.h"

class CPrizeSprite1:
public CAvoidSprite{
public:
	CPrizeSprite1(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1, int score);
	CPrizeSprite1(CPrizeSprite1 &spt);
	~CPrizeSprite1();

	int Gift(int tp);
};

#endif