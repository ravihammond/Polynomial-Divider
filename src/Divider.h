#ifndef _DIVIDER_H
#define _DIVIDER_H

#include <string>
#include "Polynomial.h"
#include "Term.h"

//-------------------------------------------------------------------------------------//
//	Divider CLASS
//- 
class Divider{
	public:
		Divider(std::string num,std::string den);
		~Divider();
		void initializePrint();
		void findTerm();
		void printTop();
		void multiply();
		void divideLoop();
	private:
		Polynomial *numerator;
		Polynomial *denominator;
		Polynomial *remain;
		Polynomial *divided;
		Polynomial *subtract;
		Term rterm;
};
#endif
