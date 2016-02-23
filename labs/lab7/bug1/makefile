EXE = bug1
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -I.

HDRS = state.h
SRCS = gov_stats.cpp state.cpp
OBJS = $(@:.cpp=.o)

$(EXE): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.cpp=.o)

debug:
	$(CXX) $(CXXFLAGS) $(SRCS) -D DEBUG -g -o $(EXE)

clean:
	rm -f *.o #(EXE) 
