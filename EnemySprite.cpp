#include <cmath>
#include "EnemySprite.h"

CEnemySprite::CEnemySprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1, int score)
: CAutoSprite(x, y, width, height, dx, dy, img, r1, score)
{
	attack= 1;
	health= 2;
}
CEnemySprite::CEnemySprite(CEnemySprite &spt)
: CAutoSprite(spt)
{
	attack= 1;
	health= 2;
}
CEnemySprite::~CEnemySprite()
{}

bool CEnemySprite::Bite(rect ur)
{
	if (x< ur.x && x+width> ur.x){
		if (y< ur.y && y+height> ur.y){
			return true;
		}
		else if (y> ur.y && y< ur.y+ur.height){
			return true;
		}

	}
	else if (x> ur.x && x< ur.x+ur.width){
		if (y< ur.y && y+height> ur.y){
			return true;
		}
		else if (y> ur.y && y< ur.y+ur.height){
			return true;
		}
	}

	return false;
}
bool CEnemySprite::Hitd()
{
	return false;
}

void CEnemySprite::move(rect ur)
{
	if (Bite(ur)){
		dx= x< ur.x ? -abs(dx) : abs(dx);
		dy= y< ur.y ? -abs(dy) : abs(dy);

		x+= 3*dx;
		y+= 3*dy;
		BHurtd();
	}
	else{
		x+= dx;
		y+= dy;
	}

	if (dx< 0 && x< r.x-width/2){
		x= r.x+ r.width-width/2;
	}
	if (dx> 0 && x> r.x+r.width-width/2){
		x= r.x-width/2;
	}
	if (dy< 0 && y< r.y-height/2){
		y= r.y+r.height-height/2;
	}
	if (dy> 0 && y> r.y+r.height-height/2){
		y= r.y-height/2;
	}

}

int CEnemySprite::BHurtd()
{
	return --health;
}
int CEnemySprite::ShowHealth()
{
	return health;
}