/*
 * Exception.h
 *
 *  Created on: Mar 24, 2021
 *      Author: ASUS
 */

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_
#define EXCEPTION_POSSIBLE 8

#include <iostream>
#include <cstring>
using namespace std;

const int UNSUITABLE_CELL_TYPE = 0;
const int CELL_OUT_OF_RANGE = 1;
const int UNSUITABLE_BREED = 2;
const int OCCUPIED_CELL = 3;
const int WRONG_COMMAND = 4;
const int EXIT_COMMAND = 5;
const int NO_WILD_ENGIMON = 6;
const int NO_SKILL = 7;

class Exception {
public:
	Exception(int);
	Exception(const Exception&);
	void displayMessage() const;
	int getErrorNumber() const;

private:
	const int errorNumber;
	static string errorMessage[EXCEPTION_POSSIBLE];
	static int errorCount;
};

#endif /* EXCEPTION_HPP_ */
