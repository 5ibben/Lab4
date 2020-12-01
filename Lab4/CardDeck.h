#pragma once
#include "Card.h"

class CardDeck
{
public:
	CardDeck(bool jokers = true);//constructor
	~CardDeck(){delete[] deck;}//destructor

	void print();
private:
	Card* deck;//arra
	int deckSize;
};

