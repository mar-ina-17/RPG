#include "Field.h"


Field::Field()
{
	this->height = 12;
	this->width = 10;
	this->fieldSurface = calcSurface(10, 12);
	this->fieldPlaces = Vector<Place>(fieldSurface);
}

Field::Field(int w, int h) : width(w), height(h)
{
	this->fieldSurface = calcSurface(w,h);
	generatePlaces(this->fieldSurface);
}

size_t Field::calcSurface(int w, int h)
{
	return w*h;	
}

void Field::generatePlaces(size_t face)
{
for(size_t i = 0; i < face; i++)
	{
		Place place = Place(i);
		this->fieldPlaces.push_back(place);
	}
}

void Field::generateHeroes()
{
	size_t i = 0;
	while(i != 2)
	{
		Heroe *newHeroe1 = new Mage();
		newHeroe1->position = i;
		this->myHeroes.push_back(newHeroe1);
		
		Heroe *newHeroe2 = new Fighter();
		newHeroe1->position = i+1;
		this->myHeroes.push_back(newHeroe2);
		
		Heroe *newHeroe3 = new Archer();
		newHeroe1->position = i+2;
		this->myHeroes.push_back(newHeroe3);
		i++;
	}
}

int randomPosition() 
{
	srand (time(NULL));
	return rand() % this->field + 1;
}

void Field::addHeroes()
{
	std::cout <<"Please chose your heroe: m - mage, a - archer, f - fighter"<<std::endl;
	char h;
	std::cin>>h;
	switch(h)
	{
		case 'm' :
		Heroe *newHeroe1 = new Mage();
		newHeroe1->position = randomPosition();
		this->myHeroes.push_back(newHeroe1);
		break;
		case 'a' : 
		Heroe *newHeroe1 = new Archer();
		newHeroe1->position = randomPosition();
		this->myHeroes.push_back(newHeroe1);
		break;
		case 'f' : 
		Heroe *newHeroe1 = new Fighter();
		newHeroe1->position = randomPosition();
		this->myHeroes.push_back(newHeroe1);
		break;
	}
}
//add heroes option
//generate heroes option*/