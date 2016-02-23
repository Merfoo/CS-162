CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -I.

SRCS = main.cpp
OBJS = main.o

EXE = lab8

$(EXE): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

$(OBJ): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm -f *.o $(EXE)
