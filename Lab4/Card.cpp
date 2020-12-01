#include "Card.h"
#include <cassert>
#include <iostream>

Card::Card(int _value, color _col)
{
	assert(_value >= 0 && _value < 14);
	val = _value;
	col = _col;
}

void Card::print()
{
	const char* tab1[] = { "Clubs","Diamonds","Hearts","Spades" };
	const char* tab2[] = { "Jack","Queen","King" };
	if (val==0)
	{
		std::cout << "Joker";
	}
	else if (val == 1)
	{
		std::cout << "Ace";
	}
	else if (val <= 10)
	{
		std::cout << val;
	}
	else
		std::cout << tab2[val - 11];
	if (val!=0)
		std::cout <<" of "<< tab1[col];
}
