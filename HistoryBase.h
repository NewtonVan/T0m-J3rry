#ifndef HistoryBase_h
#define HistoryBase_h

#include <cstdio>
#include <cstring>

class HistoryBase{
protected:
	char tme[73];
	int score;
public:
	HistoryBase(char *t, int s);
	HistoryBase(HistoryBase &his);
	~HistoryBase();
	char* GetTime();
	char* SetTime(char *src);
	int GetScore();
	int SetScore(int src);

	bool operator < (const HistoryBase &a) const;
};

#endif