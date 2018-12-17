CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o InputVal.o Menu.o University.o Building.o Person.o Student.o Instructor.o
SRCS = main.cpp InputVal.cpp Menu.cpp University.cpp Building.cpp Person.cpp Student.cpp Instructor.cpp
HEADERS = InputVal.hpp Menu.hpp University.hpp Building.hpp Person.hpp Student.hpp Instructor.hpp

game: ${OBJS} 
	${CXX} ${OBJS} -o game

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o game
