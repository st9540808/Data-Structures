all: main

objects = Graph.o
CXX = g++-6
INCULDE = .
CXXFLAGS = -g -Wall -Wextra -std=gnu++14 

main: main.cpp $(objects)
	$(CXX) -I $(INCULDE) $(CXXFLAGS) $(objects) -o main main.cpp

Graph.o: Graph.h Graph.cpp

.PHONY: clean
clean:
	rm main $(objects)
