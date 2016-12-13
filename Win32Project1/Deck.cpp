#include "Deck.h"
Deck::Deck(){
	srand(time(NULL));
	//cardList = new std::vector<Card*>();
}
Card* Deck::showTop(){
	return cardList.back();
}
Card* Deck::removeTop(){
	Card* card = showTop();
	cardList.pop_back();
	return card;
}
bool Deck::isEmpty(){
	return cardList.empty();
}
void Deck::reShuffle(std::vector<Card*> cards){
	cardList = cards;
	for(int i = 0; i < cardList.size() * 3; i++){
		swapCards(rand() % cardList.size(), rand() % cardList.size());
	}
}
void Deck::swapCards(int index1, int index2){
	Card* tempcard = cardList[index1];
	cardList[index1] = cardList[index2];
	cardList[index2] = tempcard;
}