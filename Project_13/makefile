a.out:	Project13Classes.o Project13Main.o
		g++ -o a.out Project13Classes.o Project13Main.o

Project12Classes.o:	Project13Classes.cpp Project13Classes.h
		g++ -c Project13Classes.cpp

Project12Main.o:	Project13Main.cpp Project13Classes.cpp Project13Classes.h
		g++ -c Project13Main.cpp

clean:
		rm *.o a.out