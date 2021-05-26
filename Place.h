#ifndef PLACE_H
#define PLACE_H
#include <iostream>

class Place
{
	private:
		size_t placeNum;
		//bool isThereFugure;

	public:
		Place();
		Place(size_t num);

		friend std::ostream& operator<<(std::ostream& out, Place other)
		{
			out<<"|  |";
			if(other.placeNum % 6 == 0) out<<std::endl;
			return out;
		}
};

#endif