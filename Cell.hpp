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
		string entity;
	public:
		Cell();
		Cell(int, int, string, string);
		Cell(const Cell&);
		Cell& operator=(const Cell&);
		~Cell();
		int getX();
		int getY();
		string getType();
		string getEntity();
		void setX(int);
		void setY(int);
		void setType(string);
		void setEntity(string);
		friend ostream& operator<<(ostream&, const Cell&);
};

#endif
