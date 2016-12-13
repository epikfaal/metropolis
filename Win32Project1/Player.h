#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <vector>
#include "Card.h"

class Player{
	public:
	Player();
	Player(std::string name);
	Card* playCard();
	Card* discardCard();
	void addCardToHand(Card* card);
	void addScore(int scoretoadd);
	int getScore();
	private:
	std::vector<Card*> hand;
	int score;
	void printHand();

};
#endif