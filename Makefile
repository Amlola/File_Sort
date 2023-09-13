all: text_sort

text_sort: Hamlet.o sort.o 
	g++ -o myprog.exe Hamlet.o sort.o -o text_sort

Hamlet.o: Hamlet.cpp
	g++ -c Hamlet.cpp

sort.o: sort.cpp
	g++ -c  sort.cpp

clean:
	rm *.o text_sort