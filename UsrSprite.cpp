#include "UsrSprite.h"

/*CUsrSprite::CUsrSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1)
:SpriteBase(x, y, width, height, dx, dy, img, r1)
{

}*/
CUsrSprite::CUsrSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1)
:SpriteBase(x, y, width, height, dx, dy, img, r1), score(0), health(3), weapon(0, 0), shield(0, 0), rush(0, 2, 0)
{
}
CUsrSprite::CUsrSprite(CUsrSprite &spt) : SpriteBase(spt)
{
	score= spt.score;
	health= spt.health;
	weapon= spt.weapon;
	shield= spt.shield;
	rush= spt.rush;
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
	if (0== ShoeFade()){
		RushOff();
	}
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
		case 0x52:
			RushOn();
			break;
		default:
			break;
	}
}
void CUsrSprite::RushOn()
{
	if (0>= rush.shoes){
		return;
	}
	else{
		--rush.shoes;
		rush.on= 1;
		if (0== rush.time){
			dx*= 4;
			dy*= 4;
		}
		rush.time+= 1<<10;
	}
}
void CUsrSprite::RushOff()
{
	if (0< rush.time){
		return;
	}
	rush.on= 0;
	rush.time= 0;
	dx/= 4;
	dy/= 4;
}
int CUsrSprite::ShoeFade()
{
	return rush.time> 0 ? --rush.time : -1;
}

int CUsrSprite::collision(rect rc)
{
	rect rr= {x, y, width, height};
	if (rr.x< rc.x && rr.x+rr.width > rc.x){
		if (rr.y< rc.y && rr.y+rr.height> rc.y){
			return 1;
		}
		else if (rr.y> rc.y && rr.y< rc.y+rc.height){
			return 1;
		}
	}
	else if (rr.x> rc.x && rr.x< rc.x+rc.width){
		if (rr.y< rc.y && rr.y+rr.height> rc.y){
			return 1;
		}
		else if (rr.y> rc.y && rr.y< rc.y+rc.height){
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
int CUsrSprite::ShowHealth()
{
	return health;
}
int CUsrSprite::AddHealth(int h)
{
	return health+= h;
}
int CUsrSprite::LoseHealth(int h)
{
	return health-= h;
}
int CUsrSprite::Equipped()
{
	return weapon.num;
}
int CUsrSprite::Protected()
{
	return shield.num;
}
int CUsrSprite::GetWeapon()
{
	return ++weapon.num;
}
int CUsrSprite::LoseWeapon()
{
	return --weapon.num;
}
int CUsrSprite::GetShield()
{
	return ++shield.num;
}
int CUsrSprite::LoseShield()
{
	return --shield.num;
}