Project7.exe:	Project7Main.o strLib.o Project7Classes.o
		g++ -o Project7.exe Project7Main.o strLib.o Project7Classes.o

Project7.o:	Project7Main.cpp strLib.h Project7Classes.h
		g++ -c Project7Main.cpp

Project7Classes.o:	Project7Classes.cpp Project7Classes.h strLib.h
		g++ -c Project7Classes.cpp

strLib.o:	strLib.cpp strLib.h
		g++ -c strLib.cpp

clean:
		rm *.o
