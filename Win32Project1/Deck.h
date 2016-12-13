#ifndef __DECK_H__
#define __DECK_H__

#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Card.h"

class Deck{
	public:
		Deck();
		Card* showTop();
		Card* removeTop();
		bool isEmpty();
		void reShuffle(std::vector<Card*> cards); // swaps 2 random slots size * 3 times
	private:
		std::vector<Card*> cardList;
		void swapCards(int index1, int index2);

};
#endif