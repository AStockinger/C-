CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o InputVal.o Menu.o RecursiveFunctions.o
SRCS = main.cpp InputVal.cpp Menu.cpp RecursiveFunctions.cpp
HEADERS = InputVal.hpp Menu.hpp RecursiveFunctions.hpp

output: ${OBJS} 
	${CXX} ${OBJS} -o output

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o output
