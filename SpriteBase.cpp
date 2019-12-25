#include "SpriteBase.h"

SpriteBase::SpriteBase(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1)
{
	this->x= x;
	this->y= y;
	this->width= width;
	this->height= height;
	this->dx= dx;
	this->dy= dy;
	this->img= img;
	r= r1;
}
SpriteBase::SpriteBase(SpriteBase &spt)
{
	x= spt.x;
	y= spt.y;
	width= spt.width;
	height= spt.height;
	dx= spt.dx;
	dy= spt.dy;
	img= spt.img;
	r= spt.r;
}
SpriteBase::~SpriteBase()
{

}

void SpriteBase::drawSprite(int width, int height)
{
	putImageScale(img, x, y, width, height);

}
void SpriteBase::drawSprite()
{
	putImageScale(img, x, y, width, height);
}
rect SpriteBase::getRect()
{
	rect rr= {x, y, width, height};
	return rr;
}
int SpriteBase::ShowHealth()
{
	return 0;
}