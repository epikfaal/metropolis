#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>
#include "SpecialRules.h"

class Card {
	public:
		Card();
		Card(int cost, int draw, int points, std::string name);
		std::string getImagePath();
		//void setRules(SpecialRules rules);
		void isSpecialRules();
		void setPosition(int position);
		bool isInDeck();
		bool isInHand();
		bool isOnField();
		int getCost();
		int getDraw();
		int getPoints();
		std::string getName();
	private:
		//SpecialRules rules;
		bool specialRules;
		int position; // 0 = deck 1 = hand 2 = field
	protected:
		std::string name;
		std::string imgpath;
		int cost;
		int draw;
		int points;
		char* symbols;
};
#endif