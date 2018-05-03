#pragma once

namespace Cd2
{
	// base class 
	class Cd { // represents a CD disk 
	private:
		char* performers;
		char* label;
		int selections;   // number of selections 
		double playtime;  // playing time in minutes 
	public:
		Cd(char * s1, char * s2, int n, double x);
		Cd(const Cd & d);
		Cd();
		~Cd();
		virtual void Report() const;  // reports all CD data
		Cd & operator=(const Cd & d);
	};
};
//date of creation: 01.05.2017
//Created by: Marcin Nowak