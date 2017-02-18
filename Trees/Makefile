all: main

objects = #BST.o
CC = gcc-6
INCULDE = .
CFLAGS = -g -Wall -Wextra -std=c99 

main: main.c BST.h $(objects)
	$(CC) -o main main.c $(objects) -I $(INCULDE) $(CFLAGS)

BST.o: BST.h BST.c
	$(CC) -c BST.c -I $(INCULDE) $(CFLAGS)


.PHONY: clean
clean:
	rm main $(objects)
