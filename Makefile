# Makefile for ECE3090 Complex Calculator Assignment
# Mac Clayton

CXX=g++
CXXFLAGS = -g

calculator:	calculator.o complex.o string-parse.o
	@echo Linking calculator
	$(CXX) -o calculator calculator.o complex.o string-parse.o

clean:
	rm -f calculator *.o
	@echo Cleaned!


