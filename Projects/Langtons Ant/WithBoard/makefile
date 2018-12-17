CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o InputVal.o AntMenu.o Board.o Ant.o Space.o
SRCS = main.cpp InputVal.cpp AntMenu.cpp Board.cpp Ant.cpp Space.cpp
HEADERS = InputVal.hpp AntMenu.hpp Board.hpp Ant.hpp Space.hpp

ant: ${OBJS}
	${CXX} ${OBJS} -o ant

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o ant
