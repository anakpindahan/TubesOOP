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
		char symbol;
	public:
		Cell();
		Cell(int, int, string, string, char);
		Cell(const Cell&);
		Cell& operator=(const Cell&);
		~Cell();
		int getX();
		int getY();
		string getType();
		string getEntity();
		char getSymbol();
		void setX(int);
		void setY(int);
		void setType(string);
		void setEntity(string);
		void setSymbol(char);
		void setNaturalSymbol(); 			// Mengembalikan symbol ke o atau - sesuai tipe cell
		friend ostream& operator<<(ostream&, const Cell&);
};

#endif
