#ifndef FIELD_H
#define FIELD_H
#include <iostream>
#include "Vector.h"
#include "Place.h"
#include "Mage.h"
#include "Archer.h"
#include "Fighter.h"
#include "Heroe.h"

class Field
{
	private:
		int width;
		int height;
		size_t fieldSurface;
		Vector<Place> fieldPlaces;
		Vector<Heroe*> myHeroes;

		size_t calcSurface(int w, int h);

		int randomPosition();

		void generatePlaces(size_t face);
		void generateHeroes();

	public:
		Field();
		Field(int w, int h);

		

		friend std::istream& operator>>(std::istream& in, Field& other)
		{
			other.width = 0;
		
			while(other.width < 5 || other.height < 5)
			{
				std::cout<<"Enter width & height: ";
				in>>other.width;
				in>>other.height;
			}
				
			other.fieldSurface = other.calcSurface(other.width, other.height);
			other.generatePlaces(other.fieldSurface);
			
			return in;
		}

		friend std::ostream& operator<<(std::ostream& out, const Field &other)
		{
			out<<other.fieldPlaces;

			return out;
		}
};

#endif
