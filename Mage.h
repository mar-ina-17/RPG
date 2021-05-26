#ifndef MAGE_H
#define MAGE_H
#include <iostream>
#include "Heroe.h"

class Mage : public Heroe
{
	private:
		double stamina;
		int numOfAttacks = 0;
		int numOfDeffenses = 0;

	public:
		Mage();
		
		void magicSpellCast();
		void healPotion();
		void addStamina();

		friend std::ostream &operator<<(std::ostream &out, const Mage &other)
		{
			Heroe *newHeroe = new Mage(other);
			out << *newHeroe;
			out << "Stamina: " << other.stamina << '\n';

			return out;
		}


};

Mage::Mage() : Heroe("Mage", 50, 3, 4)
{
	this->stamina = 30;
}

void Mage::healPotion()
{
	if(this->stamina >= 0.35)
	{
		this->stamina -= 0.35;
		this->increaseHP(5);
		return;
	}
	std::cout<<"The stamina is not enough to use a heal potion!\n";
	
}

void Mage::magicSpellCast()
{
	if(this->stamina >= 0.25)
	{
		this->stamina -= 0.25;
		this->increaseAP(1);
		return;
	}
	std::cout<<"The stamina is not enough to cast a magic spell!\n";
}
#endif