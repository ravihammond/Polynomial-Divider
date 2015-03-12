#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#include <string>
#include <vector>
#include "Term.h"

//-------------------------------------------------------------------------------------//
//	POLYNOMIAL CLASS
//- 
class Polynomial{
	public:
		Polynomial(std::string input);
		Polynomial();
		~Polynomial();
		void sort();
		void merge();
		void zero();
		void printArray();
		int getLength();
		Term getLeadTerm();
		void appendTerm(Term term);
		void multiply(Term term);
		std::vector<Term> getTermArray();
		void sum(Polynomial *subtract);
		void collapseZero();

	private:
		std::vector<Term*> temparray;
		std::vector<Term> termarray;
		std::vector <int> seenpowers;
};
#endif
