all: Test.o Polynomial.o Test.o
	g++ Test.o Polynomial.o test.o -o test

install: all
	mv test ../installed

Polynomial.o: ../src/Polynomial.cpp ../src/Polynomial.h
	g++ -c ../src/Polynomial.cpp -o Polynomial.o

Term.o: ../src/Term.cpp ../src/Term.h
	g++ -c ../src/Term.cpp -o Term.o

Test.o: Test.cpp
	g++ -c Test.cpp -o Test.o

clean:
	rm -f *.o test