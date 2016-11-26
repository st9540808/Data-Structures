main: SparseMatrix.o main.o
	g++ -o SparseMatrix SparseMatrix.o main.o -g

SparseMatrix.o: SparseMatrix.cpp SparseMatrix.h
	g++ -c SparseMatrix.cpp -g

#EntryNode.o: EntryNode.cpp EntryNode.h
#	g++ -c EntryNode.cpp -g

main.o: main.cpp SparseMatrix.h
	g++ -c main.cpp -g

clean:
	rm SparseMatrix *.o
