default: SparseMatrix.o main.o
	g++ -o SparseMatrix SparseMatrix.o main.o -g

multiplication: SparseMatrix.o multiplication.o
	g++ -o multiplication SparseMatrix.o multiplication.o -g

transpose: SparseMatrix.o transpose.o
	g++ -o transpose SparseMatrix.o transpose.o -g


SparseMatrix.o: SparseMatrix.cpp SparseMatrix.h
	g++ -c SparseMatrix.cpp -g

main.o: main.cpp SparseMatrix.h
	g++ -c main.cpp -g

multiplication.o: multiplication.cpp SparseMatrix.h
	g++ -c multiplication.cpp -g

transpose.o: transpose.cpp SparseMatrix.h
	g++ -c transpose.cpp -g


clean:
	rm SparseMatrix *.o
