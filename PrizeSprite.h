#ifndef PrizeSprite_h
#define PrizeSprite_h
#include "AutoSprite.h"
class CPrizeSprite :
public CAutoSprite{
public:
	CPrizeSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1, int score);
	CPrizeSprite(CPrizeSprite &spt);
	~CPrizeSprite();

	int Gift(int tp);
};

#endif