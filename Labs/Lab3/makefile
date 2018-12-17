CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o InputVal.o Die.o LoadedDie.o Game.o
SRCS = main.cpp InputVal.cpp Die.cpp LoadedDie.cpp Game.cpp
HEADERS = InputVal.hpp Die.hpp LoadedDie.hpp Game.hpp

game: ${OBJS} 
	${CXX} ${OBJS} -o game

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o game
