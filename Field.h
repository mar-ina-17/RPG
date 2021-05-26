#ifndef FIELD_H
#define FIELD_H
#include <iostream>
#include "Vector.h"
#include "Place.h"

class Field
{
	private:
		int width;
		int height;
		size_t fieldSurface;
		Vector<Place> fieldPlaces;

		size_t calcSurface(int w, int h);
		void generatePlaces(size_t face);

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
			//out<<other.fieldSurface<<std::endl;

			// for(size_t i = 0; i < other.width; i++)
			// {
			// 	out<<"___";
			// 	for(size_t j = 0; j < other.height; j++)
			// 	{
			// 		out<<"|   |";
			// 	}
			// 	out<<std::endl;
			// }

			out<<other.fieldPlaces;

			return out;
		}
};

#endif
