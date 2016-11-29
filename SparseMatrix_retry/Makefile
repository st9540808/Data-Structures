SparseMatrix: SparseMatrix.o main.o
	g++ -o SparseMatrix SparseMatrix.o main.o -g

SparseMatrix.o: SparseMatrix.cpp SparseMatrix.h
	g++ -c SparseMatrix.cpp -g

main.o: main.cpp SparseMatrix.h
	g++ -c main.cpp -g


clean:
	-rm *.o $(object) hw1 hw2 SparseMatrix
