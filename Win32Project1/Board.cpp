#include "Board.h"

Board::Board(){
	//cardList = std::vector<Card*>();
}

void Board::addCard(Card* card){
	cardList.push_back(card);
	card->setPosition(2);
}

int Board::getCardValue(){
	int value = 0;
	for(int i = 0; i < cardList.size(); i++){
		value += cardList[i]->getDraw();
	}
	return value;
}

int Board::getPointsValue(){
	int value = 0;
	for(int i = 0; i < cardList.size(); i++){
		value += cardList[i]->getPoints();
	}
	return value;
}