all: main

objects = Graph_basic.o Graph.o
CXX = g++-6
INCULDE = .
CXXFLAGS = -g -Wall -std=gnu++14 

main: main.cpp $(objects)
	$(CXX) -I $(INCULDE) $(CXXFLAGS) $(objects) -o main main.cpp

Graph.o: Graph.h
Graph_basic.o: Graph.h

.PHONY: clean
clean:
	rm main $(objects)
