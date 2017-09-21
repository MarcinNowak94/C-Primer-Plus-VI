#pragma once

class Plorg
{
private:
	static const int m_characters = 14;
	char m_name[m_characters];
	int m_CI;

public:
	Plorg(char* name = "Plorga", int Contentment = 50);
	void updateCI();
	void Report(char* name, int CI);
	void Display();
	~Plorg();
};