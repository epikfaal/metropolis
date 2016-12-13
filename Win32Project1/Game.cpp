#include "game.h"
Game::Game(){
	
}
void Game::init(){
	phase = 0;
	allcards = std::vector<Card*>();
	player = new Player();
	deck = new Deck();
	stack = new Stack();
	board = new Board();
}

void Game::startNewGame(){
	for(int i = 0; i < 8; i++) allcards.push_back(new Card(1, 1, 0, "Cheap Draw Building"));
	for(int i = 0; i < 8; i++) allcards.push_back(new Card(1, 0, 1, "Cheap Point Building"));
	for(int i = 0; i < 6; i++) allcards.push_back(new Card(3, 1, 1, "Cheap All Round Building"));
	for(int i = 0; i < 5; i++) allcards.push_back(new Card(4, 2, 1, "Avarage Draw Building"));	
	for(int i = 0; i < 5; i++) allcards.push_back(new Card(4, 1, 2, "Avarage Point Building"));
	for(int i = 0; i < 3; i++) allcards.push_back(new Card(7, 5, 0, "Expensive Draw Buidling"));
	for(int i = 0; i < 3; i++) allcards.push_back(new Card(7, 0, 7, "Expensive Point Building"));

	deck->reShuffle(allcards);
	while(true){
		if(!loop()) break;
	}
}

bool Game::loop(){
	Card* tempcard;
	switch(phase){
		case 0:
		std::cout << "you have to discard 2 cards from your hand.\n";
		for(int i = 0; i < 7; i++) player->addCardToHand(deck->removeTop());
		system("PAUSE");
		stack->addCard(player->discardCard());
		stack->addCard(player->discardCard());
		break;
		case 1:
		tempcard = player->playCard();
		std::cout << "you have to pay " << tempcard->getCost() << " to play the card " << tempcard->getName().c_str() << std::endl;
		system("pause");
		for(int i = 0; i < tempcard->getCost(); i++){
			stack->addCard(player->discardCard());
		}
		board->addCard(tempcard);
		break;
		case 2:
		player->addScore(board->getPointsValue());
		for(int i = 0; i < board->getCardValue(); i++){
			if(deck->isEmpty()) stack->putCardsBackInDeck(deck);
			player->addCardToHand(deck->removeTop());
		}
		std::cout << "You currently have " << player->getScore() << " points\n";
		break;
	}
	phase++;
	if(phase > 2){
		phase = 1;
	}
	return true;
}