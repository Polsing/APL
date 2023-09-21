all: main.o Arraylist.o
	g++ main.o Arraylist.o -o Arraylist
main.o: main.cpp
	g++ -c main.cpp -o main.o
Arraylist.o: Arraylist.cpp
	g++ -c Arraylist.cpp -o Arraylist.o
clean:
	rm -f *.o Arraylist