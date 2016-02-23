EXE = defines
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -I.

SRCS = main.cpp
OBJS = main.o

$(EXE): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.cpp=.o)

debug:
	$(CXX) $(CXXFLAGS) $(SRCS) -D DEBUG -o $(EXE)

clean:
	rm -f *.o $(EXE) 
