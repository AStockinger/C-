CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o InputVal.o DoublyLinkedList.o Node.o Menu.o
SRCS = main.cpp InputVal.cpp DoublyLinkedList.cpp Node.cpp Menu.cpp
HEADERS = InputVal.hpp DoublyLinkedList.hpp Node.hpp Menu.hpp

output: ${OBJS} 
	${CXX} ${OBJS} -o output

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o output
