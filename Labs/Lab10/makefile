CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o InputVal.o Fibonacci.o
SRCS = main.cpp InputVal.cpp Fibonacci.cpp
HEADERS = InputVal.hpp Fibonacci.hpp

output: ${OBJS} 
	${CXX} ${OBJS} -o output

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o output
