#include "UsrSprite.h"

CUsrSprite::CUsrSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1)
:SpriteBase(x, y, width, height, dx, dy, img, r1)
{
	
}
CUsrSprite::CUsrSprite(CUsrSprite &spt) : SpriteBase(spt)
{

}
CUsrSprite::~CUsrSprite()
{

}

void CUsrSprite::move(rect r1)
{
	x= r1.x;
	y= r1.y;
	if (x< r.x){
		x= r.x;
	}
	if (x> r.x+r.width-width){
		x= r.x+r.width-width;
	}
	if (y< r.y){
		y= r.y;
	}
	if (y> r.y+r.height-height){
		x= r.y+r.height-height;
	}
}
void CUsrSprite::move(int key)
{
	switch(key){
		case VK_UP:
			y-= dy;
			if (y< r.y){
				y= r.y;
			}
			break;
		case VK_DOWN:
			y+= dy;
			if (y> r.y+r.height-height){
				y= r.y+r.height-height;
			}
			break;
		case VK_LEFT:
			x-= dx;
			if (x< r.x){
				x= r.x;
			}
			break;
		case VK_RIGHT:
			x+= dx;
			if (x> r.x+r.width-width){
				x= r.x+r.width-width;
			}
			break;
		default:
			break;
	}
}
int CUsrSprite::collision(rect rc)
{
	rect rr= {x, y, width, height};
	if (rr.x< rc.x && rr.x+rr.width > rc.x){
		if (rr.y< rc.y && rr.y+rr.height> rc.y){
			return 1;
		}
		if (rr.y> rc.y && rr.y< rc.y+rc.height){
			return 1;
		}
	}
	if (rr.x> rc.x && rr.x< rc.x+rc.width){
		if (rr.y< rc.y && rr.y+rr.height> rc.y){
			return 1;
		}
		if (rr.y> rc.y && rr.y< rc.y+rc.height){
			return 1;
		}
	}

	return 0;
}
int CUsrSprite::getScore()
{
	return score;
}
int CUsrSprite::setScore(int s)
{
	return score= s;
}
int CUsrSprite::addScore(int s)
{
	return score+= s;
}