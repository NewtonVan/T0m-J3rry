#include "Ball.h"
CBall::CBall(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1)
: SpriteBase(x, y, width, height, dx, dy, img, r1), health(1), next(NULL)
{

}
CBall::CBall(CBall &bl) : SpriteBase(bl), health(bl.health), next(bl.next)
{

}
CBall::~CBall()
{

}

void CBall::move(rect r1)
{
	if (x< r.x || x> (r.x+r.width-width)){
		dx*= -1;
	}
	if (y< r.y || y> (r.y+r.height-height)){
		dy*= -1;
	}
	x+= dx;
	y+= dy;
}
void CBall::SetNext(CBall *nxt)
{
	next= nxt;
}
void CBall::LoseHealth()
{
	--health;
}

CBall* CBall::GetNext()
{
	return next;
}

int CBall::ShowHealth()
{
	return health;
}
int CBall::Collision(rect rc)
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