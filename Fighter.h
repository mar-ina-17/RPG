#ifndef FIGHTER_H
#define FIGHTER_H
#include "Heroe.h"
#include<iostream>

class Fighter : public Heroe
{
    public:
        Fighter();

        void superPunch();
        friend std::ostream &operator<<(std::ostream &out, const Fighter &other)
		{
			Heroe *newHeroe = new Fighter(other);
			out << *newHeroe;

			return out;
		}

};

Fighter::Fighter() : Heroe("Fighter", 60, 1, 1, 'f')
{}

void Fighter::superPunch()
{
    this->increaseAP(3);
    this->numOfAttacks++;
}

#endif