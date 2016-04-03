CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -I.
EXE = maze

HDRS = Actor.h Game.h Level.h Player.h Point.h Swan.h Util.h
SRCS := main.cpp $(HDRS:.h=.cpp)
OBJS := $(SRCS:.cpp=.o)

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp $(HDRS) 
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
	
clean:
	rm -f *.o $(EXE)
