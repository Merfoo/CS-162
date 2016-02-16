CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -I.
EXE = creatureTest

HDRS = Util.h Unicorn.h Gollum.h Game.h Dice.h Creature.h BlueMen.h
HDRS += Barbarian.h BabaYaga.h
SRCS = $(HDRS:.h=.cpp) main.cpp
OBJS = $(SRCS:.cpp=.o)

$(EXE): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.cpp=.o)

clean:
	rm -f *.o $(EXE)
