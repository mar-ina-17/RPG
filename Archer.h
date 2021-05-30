#ifndef ARCHER_H
#define ARCHER_H
#include "Heroe.h"
#include<iostream>

class Archer : public Heroe
{
    private:
        int arrows;

    public:
        Archer();

        void fireArrowAttack();
        void reloadArrows();

        void attack() override
        {
            this->arrows--;
        }

        friend std::ostream &operator<<(std::ostream &out, const Archer &other)
		{
			Heroe *newHeroe = new Archer(other);
			out << *newHeroe;
			out << "Arrows: " << other.arrows << '\n';

			return out;
		}
};

Archer::Archer() : Heroe("Archer", 45, 4, 3, 'a')
{
    this->arrows = 20;
}

void Archer::fireArrowAttack()
{
    this->increaseAP(2);
    this->numOfAttacks++;
}

void Archer::reloadArrows()
{
    this->arrows = 20;
}


#endif