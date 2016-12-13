#ifndef __STACK_H__
#define __STACK_H__

#include <vector>
#include "Card.h"
#include "Deck.h"
class Stack{
	public:
	Stack();
	void addCard(Card* card);
	void putCardsBackInDeck(Deck* deck);
	private:
	std::vector<Card*> cardList;

};
#endif