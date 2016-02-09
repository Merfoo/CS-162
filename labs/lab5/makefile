CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -I.
SRCS = main.cpp
OBJS = main.o

EXE = encrypt

$(EXE): $(SRCS)
	$(CXX) $(SRCS) $(CXXFLAGS) -o $@

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.cpp=.o)

clean:
	rm -f *.o $(EXE)
