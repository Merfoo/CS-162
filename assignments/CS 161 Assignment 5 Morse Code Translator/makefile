CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -I.
EXE = morse

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

$(EXE): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.cpp=.o)

clean:
	rm -f *.o $(EXE)
