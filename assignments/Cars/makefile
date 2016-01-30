CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -I.

HDRS = List.h Automobile.h AutomobileList.h Motorcycle.h MotorcycleList.h Util.h Vehicule.h
 
SRCS = main.cpp Automobile.cpp AutomobileList.cpp Motorcycle.cpp MotorcycleList.cpp Util.cpp Vehicule.cpp

OBJS = $(SRCS:.cpp=.o)

EXE = cars

$(EXE): $(SRCS) $(HDRS)
	$(CXX) $(SRCS) $(CXXFLAGS) -o $(EXE)

$(OBJS): $(SRCS)
	$(CXX) -c $(@:.o=.cpp)

clean:
	rm -f *.o $(EXE)
