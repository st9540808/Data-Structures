all: main

objects = Graph.o
CXX = g++
INCULDE = .
CXXFLAGS = -g -Wall -std=gnu++14

main: main.cpp $(objects)
	$(CXX) -I $(INCULDE) $(CXXFLAGS) $(objects) -o main main.cpp

Graph.o: Graph.h


.PHONY: clean
clean:
	rm main $(objects)
