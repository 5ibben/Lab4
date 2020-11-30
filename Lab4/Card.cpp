#include "Card.h"
#include <cassert>
#include <iostream>
using namespace std;

Card::Card(color _col, int _value)
{
	assert(_value >= 1 && _value <= 13);
	col = _col;
	val = _value;
}

void Card::print()
{
	const char* tab1[] = { "Clubs","Diamonds","Hearts","Spades" };
	const char* tab2[] = { "Jack","Queen","King" };
	if (val==0)
	{
		cout << "Joker";
	}
	else if (val == 1)
	{
		cout << "Ace";
	}
	else if (val <= 10)
	{
		cout << val;
	}
	else
		cout << tab2[val - 11];
	if (val!=0)
		cout <<" of "<< tab1[col];
}
