#ifndef HEROE_H
#define HEROE_H
#include <iostream>
#include "String.h"

class Heroe
{
	private:
		String alias;
		int healthPoints;
		int attackPoints;
		int fields;
		int level = 0;

	public:
		Heroe();
		Heroe(const char* alias, int hp, int ap, int fields);
		~Heroe();

		void attack(double p); //when someone is attacked by command this fn is called and the HP are decreased
		void deffend(double p); //when someone is defending themself the AP are decreased

		void increaseAP(int p);
		void increaseHP(int p);

		friend std::ostream& operator<<(std::ostream& out, Heroe& other)
		{
			out<<"Alias: "<<other.alias<<std::endl;
			out<<"Health Points: "<<other.healthPoints<<std::endl;
			out<<"Attack Points: "<<other.attackPoints<<std::endl;
			out<<"Fields: "<<other.fields<<std::endl;
			return out;
		}
};


#endif