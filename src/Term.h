#ifndef _TERM_H
#define _TERM_H

#include <string>

//-------------------------------------------------------------------------------------//
//	TERM CLASS
//- 
class Term{
	public:
		Term();
		Term(int coefficient,int sign, int power);
		Term(int coefficient, int sign);
		~Term();
		void setCoefficient(int coefficient);
		void setSign(int sign);
		void setPower(int power);
		int getCoefficient();
		int getSign();
		int getPower();
	private:
		int coefficient;
		int sign;
		int power;
};
#endif
