# Course: Object Oriented Programming
# Practical 9
# Author: Ravi Hammond
# Student ID: 1672048
# Description: Makefile for Border Class Example

all: Main.o Divider.o Polynomial.o Term.o
	g++ Main.o Divider.o Polynomial.o -ggdb Term.o -o ld

install: all
	mv ld ../installed

Main.o: Main.cpp
	g++ -c Main.cpp -o Main.o

Divider.o: Divider.cpp Divider.h
	g++ -c Divider.cpp -o Divider.o

Polynomial.o: Polynomial.cpp Polynomial.h
	g++ -c Polynomial.cpp -o Polynomial.o

Term.o: Term.cpp Term.h
	g++ -c Term.cpp -o Term.o

clean:
	rm -f *.o main