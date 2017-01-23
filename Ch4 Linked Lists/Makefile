all: main

objects =
CXX = g++-6
INCULDE = .
CXXFLAGS = -g -Wall -std=gnu++14 

main: main.cpp SLL.h $(objects)
	$(CXX) main.cpp -o main -I $(INCULDE) $(objects) $(CXXFLAGS)

merge:
	$(CXX) merge.cpp -o main $(CXXFLAGS)

.PHONY: clean
clean:
	rm main $(objects)
