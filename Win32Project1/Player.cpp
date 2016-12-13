#include "player.h"

Player::Player(){
	score = 0;
	hand = std::vector<Card*>();
}
Player::Player(std::string name){
	score = 0;
	hand = std::vector<Card*>();
}

void Player::addCardToHand(Card* card){
	hand.push_back(card);
	card->setPosition(1);
}

Card* Player::discardCard(){
	printHand();
	int input;
	while(true){
		std::cout << "Please enter the number of which card to discard";
		std::cin >> input;
		if (input < hand.size()) break;
		else std::cout << "\nYou tried to discard an invalid card\n";
	}
	Card* tempcard = hand[input];
	hand.erase(hand.begin() + input);
	return tempcard;
}
Card* Player::playCard(){
	printHand();
	int input;
	while(true){
		std::cout << "Please enter the number of which card to play (enter 12 for architect) ";
		std::cin >> input;
		if (input < hand.size()) break;
		else std::cout << "\nYou tried to play an invalid card\n";
	}
	Card* tempcard = hand[input];
	hand.erase(hand.begin() + input);
	return tempcard;
}
void Player::printHand(){
	std::cout << "Your current hand contains the following cards: \n\n";
	for(int i = 0; i < hand.size(); i++){
		std::cout << "[" << i << "] " << hand[i]->getName().c_str() << " Cost: " << hand[i]->getCost() << " Draw: " << hand[i]->getDraw() << " Points: " << hand[i]->getPoints() << std::endl;
	}
}
void Player::addScore(int scoretoadd){
	score += scoretoadd;
}
int Player::getScore(){
	return score;
}

