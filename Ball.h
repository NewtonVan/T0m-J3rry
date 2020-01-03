#ifndef Ball_h
#define Ball_h

#include "SpriteBase.h"
class CBall :
public SpriteBase
{
	int health;
	CBall *next;
public:
	CBall(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1);
	CBall(CBall &bl);
	~CBall();

	void move(rect r);
	void SetNext(CBall * nxt);
	void LoseHealth();

	CBall* GetNext();
	
	int ShowHealth();
	int Collision(rect rc);
};

#endif
