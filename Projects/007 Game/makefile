CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o InputVal.o Game.o Space.o Roof.o Bar.o Blackjack.o Card.o Hand.o deckOfCards.o Slots.o Roulette.o Exclusive.o Player.o Inventory.o Item.o StairKey.o CommDevice.o ExclusiveInvite.o
SRCS = main.cpp InputVal.cpp Game.cpp Space.cpp Roof.cpp Bar.cpp Blackjack.cpp Card.cpp Hand.cpp deckOfCards.cpp Slots.cpp Roulette.cpp Exclusive.cpp Player.cpp Inventory.cpp Item.cpp StairKey.cpp CommDevice.cpp ExclusiveInvite.cpp
HEADERS = Game.hpp InputVal.hpp Space.hpp Roof.hpp Bar.hpp Blackjack.hpp Card.hpp Hand.hpp deckOfCards.hpp Slots.hpp Roulette.hpp Exclusive.hpp Player.hpp Inventory.hpp Item.hpp StairKey.hpp CommDevice.hpp ExclusiveInvite.hpp

game: ${OBJS} 
	${CXX} ${OBJS} -o game

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o game
