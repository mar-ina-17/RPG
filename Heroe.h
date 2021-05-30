#ifndef HEROE_H
#define HEROE_H
#include <iostream>
#include "String.h"

class Heroe
{
	protected:
		String alias;
		char symbol;
		int healthPoints;
		int attackPoints;
		int fields;
		int level = 0;
		int numOfAttacks = 0;
		int numOfDeffenses = 0;

	public:
		int position;
		
		Heroe();
		Heroe(const char* alias, int hp, int ap, int fields, char symbol);
		~Heroe();

		char getSymbol() const { return symbol; }
		 //when someone is attacked by command this fn is called and the HP are decreased
		 //when someone is defending themself the AP are decreased
		 virtual void attack()
		{
			this->healthPoints -= this->attackPoints;
			this->numOfAttacks++;
			this->upgradeLevel();
		}

		virtual void deffend()
		{
			this->attackPoints -= (this->healthPoints/15);
			this->numOfDeffenses++;
			this->downgradeLevel();
		}

		void increaseAP(int p);
		void increaseHP(int p);

		void upgradeLevel();
		void downgradeLevel();

		void moveLeft();
		void moveRight();
		void moveForward();
		void moveBackward();
		void moveDiagonalLeftForward(); 
		void moveDiagonalRightForward(); 
		void moveDiagonalLeftBackward();
		void moveDiagonalRightBackward();

		friend std::ostream& operator<<(std::ostream& out, Heroe& other)
		{
			out<<"Alias: "<<other.alias<<std::endl;
			out<<"Symbol: "<<other.symbol<<std::endl;
			out<<"Health Points: "<<other.healthPoints<<std::endl;
			out<<"Attack Points: "<<other.attackPoints<<std::endl;
			out<<"Fields: "<<other.fields<<std::endl;
			out<<"Level: "<<other.level<<std::endl;
			out<<"Number of attacks: "<<other.numOfAttacks<<" Number of deffenses: "<<other.numOfDeffenses<<std::endl;
			return out;
		}
};


#endif