Assign-4: Assign-4.o
	g++ Assign-4.o -o Assign-4
Assign-4.o: Assign-4.cpp
	g++ -c Assign-4.cpp
clean:
	rm *.o Assign-4
