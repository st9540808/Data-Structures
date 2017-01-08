all: main

objects =
CXX = g++-6
INCULDE = .
CXXFLAGS = -g -Wall -std=gnu++14 

main: main.cpp SinglyLinkedList.h $(objects)
	$(CXX) -I $(INCULDE) $(objects) $(CXXFLAGS) -o main main.cpp



.PHONY: clean
clean:
	rm main $(objects)
