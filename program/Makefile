CC=gcc
CFLAGS=-I.

all: students_database

students_database: students_database.o
	$(CC) -o students_database students_database.o

students_database.o: students_database.c
	$(CC) -c students_database.c $(CFLAGS)

clean:
	rm -f *.o students_database
