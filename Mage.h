#ifndef MAGE_H
#define MAGE_H
#include <iostream>
#include "Heroe.h"

class Mage : public Heroe
{
	private:
		double stamina;

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

Mage::Mage() : Heroe("Mage", 50, 3, 4, 'm')
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
	if(this->stamina >= 0.55)
	{
		this->stamina -= 0.55;
		this->increaseAP(1);
		return;
	}
	std::cout<<"The stamina is not enough to cast a magic spell!\n";
}

void Mage::addStamina()
{
	if(this->level >= 2)
	{
		this->stamina += (this->level*2.25);
	}
}
#endif