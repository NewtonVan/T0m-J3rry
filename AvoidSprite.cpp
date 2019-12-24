#include <cmath>
#include "AvoidSprite.h"

CAvoidSprite::CAvoidSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1, int score)
:CAutoSprite(x, y, width, height, dx, dy, img, r1, score)
{
	oldx= dx;
	oldy= dy;
	bfirst= true;
}
CAvoidSprite::CAvoidSprite(CAvoidSprite &spt)
: CAutoSprite(spt)
{
	oldx= dx;
	oldy= dy;
	bfirst= true;
}
CAvoidSprite::~CAvoidSprite()
{
}

void CAvoidSprite::move(rect ur)
{
	if (danger(ur)){
		dx= x< ur.x ? -abs(dx) : abs(dx);
		dy= y< ur.y ? -abs(dy) : abs(dy);

		x+= 1.5*dx;
		y+= 1.5*dy;
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
bool CAvoidSprite::danger(rect ur)
{
	int cx= x+width/2;
	int cy= y+height/2;
	int ux= ur.x+ur.width/2;
	int uy= ur.y+ur.height/2;

	float dist= sqrt((cx-ux)*(cx-ux)+(cy-uy)*(cy-uy));
	return dist< 150 ? true : false;
}