#pragma once

#include "Card.h"
#include <vector>

class Board{
	public:
		Board();
		void addCard(Card* card);
		int getCardValue();
		int getPointsValue();
	private:
		std::vector<Card*> cardList;
};
