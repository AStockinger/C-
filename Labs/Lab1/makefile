output: main.o determinant.o readMatrix.o
	g++ main.o determinant.o readMatrix.o -o output

determinant.o: determinant.cpp determinant.hpp
	g++ -std=c++0x -c determinant.cpp

readMatrix.o: readMatrix.cpp readMatrix.hpp
	g++ -std=c++0x -c readMatrix.cpp

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

clean:
	rm *.o output