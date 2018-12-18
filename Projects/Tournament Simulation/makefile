CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o InputVal.o Game.o gameMenu.o CharacterQueue.o LoserStack.o Character.o Barbarian.o BlueMen.o HarryPotter.o Medusa.o Vampire.o
SRCS = main.cpp InputVal.cpp Game.cpp gameMenu.cpp CharacterQueue.cpp LoserStack.cpp Character.cpp Barbarian.cpp BlueMen.cpp HarryPotter.cpp Medusa.cpp Vampire.cpp
HEADERS = Game.hpp InputVal.hpp Game.hpp gameMenu.hpp Node.hpp CharacterQueue.hpp LoserStack.hpp Character.hpp Barbarian.hpp BlueMen.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp

game: ${OBJS} 
	${CXX} ${OBJS} -o game

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o game
