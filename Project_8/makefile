Project8.exe:	Project8Main.o Project8Classes.o
		g++ -o Project8.exe Project8Main.o Project8Classes.o

Project8.o:	Project8Main.cpp Project8Classes.h
		g++ -c Project8Main.cpp

Project8Classes.o:	Project8Classes.cpp Project8Classes.h
		g++ -c Project8Classes.cpp

clean:
		rm *.o
