#include "PrizeSprite1.h"
CPrizeSprite1::CPrizeSprite1(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1, int score)
: CAvoidSprite(x, y, width, height, dx, dy, img, r1, score)
{

}
CPrizeSprite1::CPrizeSprite1(CPrizeSprite1 &spt)
: CAvoidSprite(spt)
{

}
CPrizeSprite1::~CPrizeSprite1()
{

}

int CPrizeSprite1::Gift(int tp)
{
	return tp%4;
}