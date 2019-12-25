#include "HistoryBase.h"

HistoryBase::HistoryBase(char *t, int s) :score(s) 
{
	strcpy(tm, t);
}
HistoryBase::HistoryBase(HistoryBase &his) : score(his.score) 
{
	strcpy(tm, his.tm);
}
HistoryBase::~HistoryBase()
{}

char* HistoryBase::GetTime()
{
	return tm;
}
char* HistoryBase::SetTime(char *src)
{
	return strcpy(tm, src);
}

int HistoryBase::GetScore()
{
	return score;
}
int HistoryBase::SetScore(int src)
{
	return score= src;
}

bool HistoryBase::operator < (const HistoryBase &a) const
{
	return score< a.score;
}