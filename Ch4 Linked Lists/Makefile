all: DLLmain

objects =
CXX = g++-6
INCULDE = -I include -I .
CXXFLAGS = -g -Wall -std=gnu++14
SRC = src

DLLmain: ./src/DLLmain.cpp DLL.h $(objects)
	$(CXX) ./src/DLLmain.cpp -o main $(INCULDE) $(CXXFLAGS) $(objects)

SLLmain: ./src/SLLmain.cpp SLL.h $(objects)
	$(CXX) ./src/SLLmain.cpp -o main $(INCULDE) $(CXXFLAGS) $(objects)

merge: ./src/merge.cpp
	$(CXX) ./src/merge.cpp -o main $(INCULDE) $(CXXFLAGS)

check: ./src/check.cpp
	$(CXX) ./src/check.cpp -o main $(INCULDE) $(CXXFLAGS)


.PHONY: clean
clean:
	rm main $(objects)
