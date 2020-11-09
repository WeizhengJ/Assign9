.DEFAULT_GOAL := heap.exe
heap.o: heap.cc
	g++ -c heap.cc -Wall -std=c++11

heap.exe: heap.o
	g++ -o heap.exe heap.o -Wall -std=c++11

clean:
	rm *.o heap.exe
