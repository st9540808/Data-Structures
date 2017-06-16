objects =
CXX = g++-7.1
INCULDE = -I include -I .
CXXFLAGS = -g -Wall -std=gnu++14 

verify: ./src/verify.cpp
	$(CXX) ./src/verify.cpp -o main $(INCULDE) $(CXXFLAGS)

merge: ./src/merge.cpp
	$(CXX) ./src/merge.cpp -o main $(INCULDE) $(CXXFLAGS)


.PHONY: clean
clean:
	rm main $(objects)
