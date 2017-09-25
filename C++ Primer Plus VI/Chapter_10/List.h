#pragma once

typedef int Item;

class List
{
 private:
	 const static int maxelements = 100;
	 Item item[maxelements];
	 int End=0;

 public:
	 List() { std::cout << "\nAnd the user said: 'LET THERE BE LIST!', and there was " << this <<" List."; };
	 ~List();

	bool AddItem(Item & item);
	bool isEmpty();
	bool isFull();
	void visit(void(*pf)(Item &));

};