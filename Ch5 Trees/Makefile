all: main

objects = 
CC = gcc-6
INCULDE = .
CFLAGS = -g -Wall -Wextra -std=c99 

main: main.c $(objects)
	$(CC) -o main main.c -I $(INCULDE) $(CFLAGS) $(objects)


.PHONY: clean
clean:
	rm main $(objects)
