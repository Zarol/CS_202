a.out:	main.o Queue2.o
		g++ -o a.out main.o Queue2.o

main.o:	main.cpp Queue.h
		g++ -c main.cpp

Queue2.o:	Queue2.cpp Queue.h
		g++ -c Queue2.cpp

clean:
		rm *.o
