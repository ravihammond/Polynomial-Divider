#include <stdio.h>
#include <iostream>

#include "Divider.h"
using namespace std;

//-------------------------------------------------------------------------------------//
//	Divider CONNSTRUCTOR
//- 
Divider::Divider(string num,string den){
	numerator = new Polynomial(num);
	denominator = new Polynomial(den);
	numerator->merge();
	numerator->sort();
	denominator->merge();
	denominator->sort();
	remain = new Polynomial();
	*remain = *numerator;
	remain->zero();
	remain->sort();
	divided = new Polynomial();
	subtract = new Polynomial();
}

void Divider::initializePrint(){
	printf("\033[9;2H");
	denominator->printArray();
	if(numerator->getLeadTerm().getSign()==-1) printf(" |");
	else printf(" | ");
	remain->printArray();
	printf("\033[8;%dH\033[4m",denominator->getLength()+4);
	int negshift = 1;
	if(remain->getLeadTerm().getSign()==-1) negshift = 0;
	for (int i = 0; i < remain->getLength()+negshift; ++i){
		printf(" ");
	}
	printf("\033[0m");
}

void Divider::findTerm(){
		Term numterm = remain->getLeadTerm();
		Term denterm = denominator->getLeadTerm();
		int rcoefficient = numterm.getCoefficient() / denterm.getCoefficient();
		int rsign;
		if(numterm.getSign()!=denterm.getSign()){
		rsign = -1;
		}else{
		rsign = 1;
		}
		int rpower = numterm.getPower() - denterm.getPower();
		Term tempterm(rcoefficient,rsign,rpower);
		rterm = tempterm;
		divided->appendTerm(rterm);
}

void Divider::printTop(){
	int negshift = 5;
	if(divided->getLeadTerm().getSign()==-1) negshift = 4;
	printf("\033[8;%dH\033[4m",denominator->getLength()+negshift);
	divided->printArray();
	printf("\033[0m");
}

void Divider::multiply(){
	*subtract = *denominator;
	subtract->multiply(rterm);
	Term negterm(1,-1,0);
	subtract->multiply(negterm);
}

void Divider::divideLoop(){
	bool end = false;
	int negshift = 5;
	for(int i = 0; end==false;){
		findTerm();
		multiply();
		if(subtract->getLeadTerm().getSign()==-1) negshift = 4;
		else negshift = 5;
		printf("\033[%d;%dH\033[4m",10+i*2,denominator->getLength()+negshift+i*2);
		subtract->printArray();
		printf("\033[0m");
		remain->sum(subtract);
		if(remain->getLeadTerm().getSign()==-1) negshift = 4;
		else negshift = 5;
		printf("\033[%d;%dH",11+i*2,denominator->getLength()+negshift+i*4);
		remain->printArray();
		
		if(remain->getLeadTerm().getPower()<denominator->getLeadTerm().getPower()) 
			end = true;
		i++;
	}
	printTop();
}

//empty destructor, because dragon.
Divider::~Divider(){
 //             ______________
 //       ,===:'.,            `-._
 //            `:.`---.__         `-._
 //              `:.     `--.         `.
 //                \.        `.         `.
 //        (,,(,    \.         `.   ____,-`.,
 //     (,'     `/   \.   ,--.___`.'
 // ,  ,'  ,--.  `,   \.;'         `
 //  `{D, {    \  :    \;
 //    V,,'    /  /    //
 //    j;;    /  ,' ,-//.    ,---.      ,
 //    \;'   /  ,' /  _  \  /  _  \   ,'/
 //          \   `'  / \  `'  / \  `.' /
 //           `.___,'   `.__,'   `.__,'  
}
