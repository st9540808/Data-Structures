all: main

objects =
CXX = g++-6
INCULDE = include
CXXFLAGS = -g -Wall -std=gnu++14 

main: main.cpp SLL.h $(objects)
	$(CXX) main.cpp -o main -I $(INCULDE) $(objects) $(CXXFLAGS)

run:
	./main

.PHONY: clean
clean:
	rm main $(objects)
