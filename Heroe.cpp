#include "Heroe.h"

Heroe::Heroe() : alias("Test"), healthPoints(10), attackPoints(1), fields(2) {};

Heroe::Heroe(const char* alias, int hp, int ap, int fields)
{
	this->alias = String(alias);
	this->healthPoints = hp;
	this->attackPoints = ap;
	this->fields = fields;
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

void Heroe::attack(double p)
{
	this->healthPoints -= p;
}

void Heroe::deffend(double p)
{
	this->attackPoints -= p;
}