#include <stdio.h>
#include <string>
#include <stdlib.h>

#include "Polynomial.h"
using namespace std;

//-------------------------------------------------------------------------------------//
//	POLYNOMIAL CONSTRUCTOR
//- 
Polynomial::Polynomial(){}
Polynomial::Polynomial(string input){
	int start, end;
	bool first = true;
	bool bpower;
	start = 0;
	int sign = 1;
	bool term;
	string coefficient;
	string power;
	for(int i = 0; i < input.size(); ++i){
		if(first){
			first = false;
		}
		if(((input[i+1]=='-' || input[i+1]=='+') && !first) || input.size()==i+1){
			term = false; 
			coefficient = "";
			power = "1";
			bpower = false;	
			for(int j = start; j <= i; ++j){
				if(input[j]=='x')
					term = true;
				if(j==start && (input[j]=='-' || input[j]=='+')){
					if(input[j]=='-')
						sign = -1;
					else
						sign = 1;
				}else if(!term)
					coefficient += input[j];
				if(input[j]=='^'){
					power = "";
					bpower = true;
				}else if(term && bpower)
					power += input[j];
			}
			int cobuff= atoi(coefficient.c_str());
			if(cobuff==0) cobuff = 1;
			if(term)
				temparray.push_back(new Term(cobuff,sign,atoi(power.c_str())));
			else
				temparray.push_back(new Term(cobuff,sign));
			start = i+1; 
		}
	}
}

void Polynomial::merge(){
	bool seenpower;
	int tempco = 0;
	int size = seenpowers.size();
	seenpowers.erase(seenpowers.begin(),seenpowers.begin()+size);
	for (int i = 0; i < temparray.size(); ++i){
		seenpower = false;
		for (int j = 0; j < seenpowers.size(); ++j){
			if(temparray[i]->getPower()==seenpowers[j]){
				seenpower = true;
			}
		}
		if(!seenpower){
			seenpowers.push_back(temparray[i]->getPower());
			termarray.push_back(*temparray[i]);
		}else{
			for (int j = 0; j < termarray.size(); ++j){
				if(termarray[j].getPower()==temparray[i]->getPower()){
					tempco = termarray[j].getSign()*termarray[j].getCoefficient() + 
					temparray[i]->getSign()*temparray[i]->getCoefficient();
					if(tempco<0)
						termarray[j].setSign(-1);
					else
						termarray[j].setSign(1);
					termarray[j].setCoefficient(abs(tempco));
				}
			}
		}
	}
}

void Polynomial::zero(){
	int highestpower = 0;
	for (int i = 0; i < seenpowers.size(); ++i){
		if(seenpowers[i]>highestpower)
			highestpower = seenpowers[i];
	}
	bool pownotin;
	for (int i = 0; i <= highestpower; ++i){
		pownotin = true;
		for (int j = 0; j < seenpowers.size(); ++j){
			if(termarray[j].getPower()==i)
				pownotin = false;
		}
		if(pownotin)
			termarray.push_back(Term(0,1,i));
	}
}

//-------------------------------------------------------------------------------------//
//	SORT METHOD
//- 
void Polynomial::sort(){
	int j;
	Term placeholder;
	for (int i = 1; i < termarray.size(); ++i){
		placeholder = termarray[i];
		j = i;
		while (j>0 && termarray[j-1].getPower()<placeholder.getPower()){
			termarray[j] = termarray[j-1];
			--j;
		}
		termarray[j] = placeholder;
	}
}

void Polynomial::printArray(){
	int power, coefficient, sign;
	bool first = true;
	for (int i = 0; i < termarray.size(); ++i){
		power = termarray[i].getPower();
		coefficient = termarray[i].getCoefficient();
		sign = termarray[i].getSign();
		if (!first){
			if(sign==1)
				printf("+");
		}
		first = false;
		if(sign==-1)
			printf("-");
		if(coefficient>1 || power==0 || coefficient==0)
			printf("%d",coefficient); 	
		if(power>=1){
			printf("x");
			if(power>1){
				printf("^");
				printf("%d",power);
			}
		}
	}
}

int Polynomial::getLength(){
	int length = 0;
	char buffer [20];
	string sbuff;
	if(termarray[0].getSign()==-1) length ++;
	for (int i = 0; i < termarray.size(); ++i){
		if(i!=0) length++;
		sprintf(buffer,"%d",termarray[i].getCoefficient());
		sbuff = buffer;
		length += sbuff.size();
		if(termarray[i].getPower()>0 && termarray[i].getCoefficient()==1) length--;	
		if(termarray[i].getPower()>=1){
			length++;
			if(termarray[i].getPower()>1){
				length++;
				sprintf(buffer,"%d",termarray[i].getPower());
				sbuff = buffer;
				length += sbuff.size();
			}
		}
	}
	return length;
}

Term Polynomial::getLeadTerm(){
	return termarray[0];
}

void Polynomial::appendTerm(Term term){
	termarray.push_back(term);
}

void Polynomial::multiply(Term term){
for (int i = 0; i < termarray.size(); ++i){
		termarray[i].setCoefficient(termarray[i].getCoefficient()*term.getCoefficient());
		termarray[i].setSign(termarray[i].getSign()*term.getSign());
		termarray[i].setPower(termarray[i].getPower()+term.getPower());
	}
}

vector<Term> Polynomial::getTermArray(){
	return termarray;
}

void Polynomial::sum(Polynomial *subtract){
	int size = temparray.size();
	temparray.erase(temparray.begin(),temparray.begin()+size);
	for (int i = 0; i < subtract->getTermArray().size(); ++i){
		termarray.push_back(subtract->getTermArray()[i]);
	}
	for (int i = 0; i < termarray.size(); ++i){
		temparray.push_back(&(termarray[i]));
	}
	size = termarray.size();
	termarray.erase(termarray.begin(),termarray.begin()+size);
	merge();
	sort();
	collapseZero();
}

void Polynomial::collapseZero(){
	vector<Term> temp= termarray;
	int size = termarray.size();
	termarray.erase(termarray.begin(),termarray.begin()+size);
	bool notfront = false;
	for (int i = 0; i < temp.size(); ++i){
		if(i==0 && termarray[i].getCoefficient()==0){else
		}33333
			termarray.push_back(temp[i]);
	}
}

//empty destructor, because dragon.
Polynomial::~Polynomial(){
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
