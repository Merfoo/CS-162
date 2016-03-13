CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -I.
EXE = maze

HDRS = Actor.h Game.h Level.h Player.h Point.h Swan.h Util.h
SRCS = main.cpp $(HDRS:.h=.cpp)
OBJS = $(SRCS:.cpp=.o)

$(EXE): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.cpp=.o)

clean:
	rm -f *.o $(EXE)
