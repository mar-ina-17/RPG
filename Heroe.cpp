#include "Heroe.h"

Heroe::Heroe() : alias("Test"), healthPoints(10), attackPoints(1), fields(2), symbol('t') {};

Heroe::Heroe(const char* alias, int hp, int ap, int fields, char symbol) 
{
	this->alias = String(alias);
	this->healthPoints = hp;
	this->attackPoints = ap;
	this->fields = fields;
	this->symbol = symbol;
}

Heroe::~Heroe()
{
	this->alias.~String();
}

void Heroe::increaseAP(int p)
{
	 this->attackPoints += p;
}

void Heroe::increaseHP(int p)
{
	 this->healthPoints += p;
}

void Heroe::upgradeLevel()
{
	if(this->numOfAttacks == 7)
	{
		this->healthPoints = (this->healthPoints*0.25) + 50;
		this->attackPoints = (this->attackPoints*0.5) + 3;
		this->numOfAttacks = 0;
		this->numOfDeffenses = 0;
		this->level++;
		std::cout<<"Your heroe just upgraded to next level!: "<<this->level<<std::endl;
	}
	
}

void Heroe::downgradeLevel()
{
	if(this->numOfDeffenses == 7 && this->level >= 1)
	{
		this->healthPoints = (this->healthPoints*0.25) - 10;
		this->attackPoints = (this->attackPoints*0.5) - 1;
		this->numOfAttacks = 0;
		this->numOfDeffenses = 0;
		this->level--;
		std::cout<<"Your heroe just downgraded to prev level: "<<this->level<<std::endl;
	}
}

void Heroe::moveLeft(int p)
{
	this->position -= p;
}

void Heroe::moveRight(int p)
{
	this->position += p;
}

void Heroe::moveForward(int p)
{
	this->position += 6*p;
}

void Heroe::moveBackward(int p)
{
	this->position -= 6*p;
}