EXE = list
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -I.

HDRS = LinkedList.h
SRCS = main.cpp LinkedList.cpp
OBJS = main.o LinkedList.o

$(EXE): $(SRCS) $(HDRS)
	$(CXX) $(SRCS) $(CXXFLAGS) -o $@

$(OBJ): $(SRCS)
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm -f *.o $(EXE) 

