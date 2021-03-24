/*
 * Exception.cpp
 *
 *  Created on: Mar 24, 2021
 *      Author: ASUS
 */

#include "Exception.hpp"

#include <iostream>
#include <cstring>
using namespace std;

int Exception::errorCount = 0;
string Exception::errorMessage[EXCEPTION_POSSIBLE] = {
		"Tipe cell ini tidak sesuai untuk engimon",
		"Engimon bergerak ke luar peta",
		"Kedua engimon ini tidak dapat dikawinkan", "Cell ini sudah ditempati",
		"Command yang dimasukkan tidak ada",
		"Terima kasih sudah bermain Engimon~" };

Exception::Exception(int x) :
		errorNumber(x) {
	errorCount++;
}

Exception::Exception(const Exception& ee) :
		errorNumber(ee.errorNumber) {

}

void Exception::displayMessage() const {
	cout << errorMessage[errorNumber] << endl;
}

int Exception::getErrorNumber() const{
	return errorNumber;
}
