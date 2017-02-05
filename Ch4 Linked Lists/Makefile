all: DoublyLList

objects =
CXX = g++-6
INCULDE = -I include -I .
CXXFLAGS = -g -Wall -std=gnu++14

DoublyLList: ./src/DoublyLList_main.cpp DoublyLList.h $(objects)
	$(CXX) ./src/DoublyLList_main.cpp -o main $(INCULDE) $(CXXFLAGS) $(objects)

SinglyLList: ./src/SinglyLList_main.cpp SinglyLList.h $(objects)
	$(CXX) ./src/SinglyLList_main.cpp -o main $(INCULDE) $(CXXFLAGS) $(objects)

Stack: ./src/Stack_main.cpp SinglyLList.h Stack.h
	$(CXX) ./src/Stack_main.cpp -o main $(INCULDE) $(CXXFLAGS) $(objects)


merge: ./src/merge.cpp
	$(CXX) ./src/merge.cpp -o main $(INCULDE) $(CXXFLAGS)

check: ./src/check.cpp
	$(CXX) ./src/check.cpp -o main $(INCULDE) $(CXXFLAGS)


.PHONY: clean
clean:
	rm main $(objects)
