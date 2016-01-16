EXE = ticTacToe
CXX = g++
SRCS = main.cpp GameBoard.cpp TicTacToe.cpp Util.cpp
HEADERS = GameBoard.h TicTacToe.h Util.h
OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -I.

$(EXE): $(SRCS) $(HEADERS)
	$(CXX) $(SRCS) $(CXXFLAGS) -o $@

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm -f *.o $(EXE)
