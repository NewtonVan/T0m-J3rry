#include "HistoryBase.h"

HistoryBase::HistoryBase(char *t, int s) :score(s) 
{
	strcpy(tme, t);
}
HistoryBase::HistoryBase(HistoryBase &his) : score(his.score) 
{
	strcpy(tme, his.tme);
}
HistoryBase::~HistoryBase()
{}

char* HistoryBase::GetTime()
{
	return tme;
}
char* HistoryBase::SetTime(char *src)
{
	return strcpy(tme, src);
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