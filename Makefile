all: Database.o Sequence.o main.cpp
	g++ Database.o Sequence.o main.cpp -o main
Database.o: Sequence.o Database.cpp
	g++ Sequence.o -c Database.cpp
Sequence.o: Sequence.cpp
	g++ -c Sequence.cpp
clean:
	rm *.o
