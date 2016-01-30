CXX = g++
HDRS = item.h List.h
SRCS = main.cpp itemfunctions.cpp List.cpp
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -I. -std=c++0x -Wall -pedantic-errors
EXE = groceries

$(EXE): $(SRCS) $(HDRS)
	$(CXX) $(SRCS) $(CXXFLAGS) -o $@

$(OBJS): $(SRCS) $(HDRS)
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm -f *.o $(EXE)
