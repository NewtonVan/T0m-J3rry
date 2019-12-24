#ifndef AvoidSprite_h
#define AvoidSprite_h

#include "AutoSprite.h"

class CAvoidSprite : public CAutoSprite{
	int oldx, oldy;
	bool bfirst;
protected:
	bool danger(rect rr);
public:
	CAvoidSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1, int score);
	CAvoidSprite(CAvoidSprite &spt);
	virtual ~CAvoidSprite();

	void move(rect rr);
};

#endif