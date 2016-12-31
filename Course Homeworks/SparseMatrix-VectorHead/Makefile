default: SparseMatrix.o main.o
	g++ -o SparseMatrix SparseMatrix.o main.o -g

hw1: SparseMatrix.o hw1.o
	g++ -o hw1 SparseMatrix.o hw1.o -g

hw2: SparseMatrix.o hw2.o
	g++ -o hw2 SparseMatrix.o hw2.o -g


SparseMatrix.o: SparseMatrix.cpp SparseMatrix.h
	g++ -c SparseMatrix.cpp -g

main.o: main.cpp SparseMatrix.h
	g++ -c main.cpp -g

hw1.o: hw1.cpp SparseMatrix.h
	g++ -c hw1.cpp -g

hw2.o: hw2.cpp SparseMatrix.h
	g++ -c hw2.cpp -g


clean:
	-rm *.o $(object) hw1 hw2 SparseMatrix
