#include "PrizeSprite.h"
CPrizeSprite::CPrizeSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1, int score)
: CAutoSprite(x, y, width, height, dx, dy, img, r1, score)
{

}
CPrizeSprite::CPrizeSprite(CPrizeSprite &spt)
: CAutoSprite(spt)
{

}
CPrizeSprite::~CPrizeSprite()
{

}

int CPrizeSprite::Gift(int tp)
{
	return tp%4;
}
