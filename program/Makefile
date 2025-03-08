CC=gcc
CFLAGS=-I.

all: main

main: main.o database.o
	$(CC) -o main main.o database.o

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

database.o: database.c
	$(CC) -c database.c $(CFLAGS)

clean:
	rm -f *.o main
