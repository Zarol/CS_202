a.out: InLab3.o parser.o
	g++ InLab3.o parser.o
InLab3.o: InLab3.cpp parser.h
	g++ -c InLab3.cpp
