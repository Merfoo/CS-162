CXX = g++
SRCS = main.cpp Rational.cpp
HDRS = Rational.h
OBJS = main.o Rational.o
EXE = rational

CXXFLAGS = -std=c++0x -Wall -pedantic-errors -I.

$(EXE): $(SRCS) $(HDRS)
	$(CXX) $(SRCS) $(CXXFLAGS) -o $@

$(OBJS): $(SRCS)
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm -f *.o $(EXE)
