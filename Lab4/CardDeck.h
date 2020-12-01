#pragma once
#include "Card.h"

class CardDeck
{
public:
	CardDeck(bool jokers = true);
	~CardDeck(){delete[] deck;}

	void print();
private:
	Card* deck;
	int deckSize;
};

