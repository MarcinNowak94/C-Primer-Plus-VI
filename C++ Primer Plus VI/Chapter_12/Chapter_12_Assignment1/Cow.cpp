#include "../../stdafx.h"
#include "Cow.h"

/*class Cow
{
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow &c);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const;  // display all cow data
};*/

Cow::Cow()
{
	char defaultname[] = "Mysterious cow";
	for (size_t i = 0; i < sizeof(name)/sizeof(name[0]); i++)
	{
		if (i < (sizeof(defaultname) / sizeof(defaultname[0]))) { this->name[i] = defaultname[i]; continue; };
		this->name[i] = NULL;
	};
	char* chrptr = new char[1];
	this->hobby = chrptr;
	this->hobby[0] = NULL;
	this->weight = NULL;
};

Cow::Cow(const char * nm, const char * ho, double wt)
{	
	//std::cout << "\nstrlen of nm " << std::strlen(nm) << "\n";
	//std::cout << "sizeof nm(" << sizeof(nm) << "), sizeof nm[0](" << sizeof(nm[0]) << "), sizeof(nm)/sizeof(nm[0]) (" << sizeof(nm) / sizeof(nm[0]) << ")";
	for (size_t i = 0; i <= std::strlen(nm) && i<20; i++)
	{
		if (i == std::strlen(nm)+1 || i==19) this->name[i] = NULL;
		this->name[i] = nm[i];
	};
	
	char* chrptr = new char[std::strlen(ho) + 1];
	this->hobby = chrptr;
	for (size_t i = 0; i <= std::strlen(ho); i++)
	{
		if (i == std::strlen(ho)+1) { this->hobby[i] = NULL; break;};
		this->hobby[i] = ho[i];
	};
	this->weight = wt;
};

Cow::Cow(const Cow &c)
{
	std::strcpy(this->name, c.name);
	char* chrptr = new char[std::strlen(c.hobby) + 1];
	this->hobby = chrptr;
	std::strcpy(this->hobby, c.hobby);
	this->weight = weight;
};

Cow::~Cow()
{
	std::cout << "\nUnfortunately " << this->name << " passed away [*]\n";
	delete[] this->hobby;
};

Cow & Cow::operator=(const Cow & c)
{
	std::strcpy(this->name, c.name);
	char* chrptr = new char[std::strlen(c.hobby) + 1];
	this->hobby = chrptr;
	std::strcpy(this->hobby, c.hobby);
	this->weight = weight;
	return *this;
};

void Cow::ShowCow() const
{
	std::cout << "\tName:\t" << this->name
		<< "\n\tHobby:\t" << this->hobby
		<< "\n\tWeight:\t" << this->weight << "kg\n";
};