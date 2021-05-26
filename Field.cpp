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