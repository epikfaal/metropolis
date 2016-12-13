#include "Stack.h"
Stack::Stack(){
	cardList = std::vector<Card*>();
}
void Stack::addCard(Card* card){
	cardList.push_back(card);
	card->setPosition(0);
}
void Stack::putCardsBackInDeck(Deck* deck){
	deck->reShuffle(cardList);
}