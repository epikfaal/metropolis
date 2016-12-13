#ifndef __GAME_H__
#define __GAME_H__

#include "Player.h"
#include "Deck.h"
#include "Stack.h"
#include "Card.h"
#include "Board.h"
#include <vector>
#include <iostream>
class Game{
	public:
	Game();
	void startNewGame();
	bool loop();
	void init();
	private:
	int phase; // 0 = discard 2 at start of game 1 = choose a card 2 = pay the cost 3 = gain profits;
	Player* player;
	Deck* deck;
	Stack* stack;
	Board* board;
	std::vector<Card*> allcards;
};
#endif