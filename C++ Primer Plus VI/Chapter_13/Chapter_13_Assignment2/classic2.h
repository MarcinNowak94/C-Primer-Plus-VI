#pragma once

#include "cd2.h"

namespace Cd2
{
	class Classic : public Cd
	{
	private:
		char* primarywork;
	public:
		Classic(char* primwrk, char* perf, char* label, int sel, double playtime) :Cd(perf, label, sel, playtime)
		{
			primarywork = new char[std::strlen(primwrk) + 1];
			std::strcpy(primarywork, primwrk);
		};
		Classic(const Classic & c);
		Classic() :Cd() { primarywork = new char[1]; };
		~Classic();
		virtual void Report() const;
		Classic & operator=(const Classic & cl);
	};
}

//date of creation: 01.05.2017
//Created by: Marcin Nowak