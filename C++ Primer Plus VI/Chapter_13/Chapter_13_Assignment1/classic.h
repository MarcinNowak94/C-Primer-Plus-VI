#include "cd.h"

class Classic : public Cd
{
private:
	char primarywork[200];
public:
	Classic(char* primwrk, char* perf, char* label, int sel, double playtime) :Cd(perf, label, sel, playtime)
	{
		strcpy_s(primarywork, primwrk);
	};
	Classic(const Classic & c);
	Classic() :Cd() {};
	virtual void Report() const;
	Classic & operator=(const Classic & cl);
};

//date of creation: 29.04.2017
//Created by: Marcin Nowak