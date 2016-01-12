CXX = g++
SRCS = main.cpp average.cpp summation.cpp
HEADERS = average.h summation.h
OBJS = main.o average.o summation.o

CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

program1: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} ${CXXFLAGS} -o program1

${OBJS}: ${SRCS}
	${CXX} -c $(@:.o=.cpp)

clean:
	rm -f *.o program1
