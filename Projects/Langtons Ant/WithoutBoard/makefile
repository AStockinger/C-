output: main.o AntMenu.o Ant.o Space.o
	g++ main.o AntMenu.o Ant.o Space.o -o output

main.o: main.cpp
	g++ -c main.cpp

AntMenu.o: AntMenu.cpp AntMenu.hpp
	g++ -c AntMenu.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp

clean:
	rm *.o output
