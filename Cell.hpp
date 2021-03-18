#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include <cstring>
using namespace std;

class Cell{
	private:
		int X;
		int Y;
		string type;
	public:
		Cell();
		Cell(int, int, string);
		Cell(const Cell&);
		Cell& operator=(const Cell&);
		~Cell();
		int getX();
		int getY();
		string getType();
		void setX(int);
		void setY(int);
		void setType(string);
};

#endif
