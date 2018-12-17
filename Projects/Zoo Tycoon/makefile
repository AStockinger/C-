XX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o InputVal.o ZooMenu.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o
SRCS = main.cpp InputVal.cpp ZooMenu.cpp Zoo.cpp Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp
HEADERS = InputVal.hpp ZooMenu.hpp Zoo.hpp Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp

zoo: ${OBJS} 
	${CXX} ${OBJS} -o zoo

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o zoo
