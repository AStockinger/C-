CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o InputVal.o Queue.o Menu.o
SRCS = main.cpp InputVal.cpp Queue.cpp Menu.cpp
HEADERS = InputVal.hpp Queue.hpp Menu.hpp

output: ${OBJS} 
	${CXX} ${OBJS} -o output

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o output
