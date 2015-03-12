#include <stdio.h>
#include <iostream>
#include <string>

#include "Divider.h"
using namespace std;

//-------------------------------------------------------------------------------------//
//	MAIN FUNCTION
//- 
int main() {
	string num;
	string den;
	printf("\033[1;1H\033[2J");
	printf("\033[1;60HPOLYNOMIAL DIVISION");
	printf("\033[3;40HType the numerator polynomial : "); cin >> num;
	printf("\033[5;40HType the denominator polynomial : "); cin >> den;

	Divider polyset(num,den);
	polyset.initializePrint();
	polyset.divideLoop();
	printf("\033[40;1H");
	return 0; 
}