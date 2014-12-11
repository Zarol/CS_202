Project5.exe:	Project5.o strLib.o
		g++ -o Project5.exe Project5.o strLib.o

Project5.o:	Project5.cpp strLib.h
		g++ -c Project5.cpp

strLib.o:	strLib.cpp strLib.h
		g++ -c strLib.cpp

clean:
		rm *.o
