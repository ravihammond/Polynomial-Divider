#include <stdio.h>
#include <string>

#include "Term.h"
using namespace std;

//-------------------------------------------------------------------------------------//
//	TERM CONNSTRUCTOR
//- 
Term::Term(){}
Term::Term(int coefficient,int sign, int power){
	this->coefficient = coefficient;
	this->sign = sign;
	this->power = power;
}

Term::Term(int coefficient, int sign){
	power = 0;
	this->sign = sign;
	this->coefficient = coefficient;
}

void Term::setCoefficient(int coefficient){
	this->coefficient = coefficient;
}

void Term::setSign(int sign){
	this->sign = sign;
}

void Term::setPower(int power){
	this->power = power;
}

int Term::getCoefficient(){
	return coefficient;
}

int Term::getSign(){
	return sign;
}

int Term::getPower(){
	return power;
}

//empty destructor, because dragon.
Term::~Term(){
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
