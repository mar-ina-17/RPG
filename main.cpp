#include <iostream>
#include "Field.h"
#include "Mage.h"


//add a class Player 

int main()
{
	/*Field f = Field(10, 20);
	std::cout<<f;/**/

	/*Field f1;
	std::cin>>f1;
	std::cout<<f1;*/

	Mage h;
	h.magicSpellCast();
	std::cout<<h;

	return 0;
}