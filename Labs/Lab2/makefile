output: main.o CountLetters.o OutputLetters.o
	g++ main.o CountLetters.o OutputLetters.o -o output

main.o: main.cpp
	g++ -c main.cpp

CountLetters.o: CountLetters.cpp CountLetters.hpp
	g++ -c CountLetters.cpp

OutputLetters.o: OutputLetters.cpp OutputLetters.hpp
	g++ -c OutputLetters.cpp

clean:
	rm *.o output