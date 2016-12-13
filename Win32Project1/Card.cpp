#include "Card.h"

Card::Card(){
	this->cost = 0;
	this->draw = 0;
	this->points = 0;
	position = 0;
	name = "voidcard";
}
Card::Card(int cost, int draw, int points, std::string name){
	this->cost = cost;
	this->draw = draw;
	this->points = points;
	position = 0;
	this->name = name;
}
bool Card::isInDeck(){
	return position == 0;
}
bool Card::isInHand(){
	return position == 1;
}
bool Card::isOnField(){
	return position == 2;
}

void Card::setPosition(int position){
	this->position = position;
}

int Card::getCost(){
	return cost;
}
int Card::getDraw(){
	return draw;
}
int Card::getPoints(){
	return points;
}
std::string Card::getName(){
	return name;
}