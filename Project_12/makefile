a.out:	Project12Classes.o Project12Main.o
		g++ -o a.out Project12Classes.o Project12Main.o

Project12Classes.o:	Project12Classes.cpp Project12Classes.h
		g++ -c Project12Classes.cpp

Project12Main.o:	Project12Main.cpp Project12Classes.cpp Project12Classes.h
		g++ -c Project12Main.cpp

clean:
		rm *.o a.out