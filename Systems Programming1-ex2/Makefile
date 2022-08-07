CC=gcc
FLAGS= -Wall -g

all: lib

lib: main.o libclass.a 
	$(CC) $(FLAGS) -o connections main.o libclass.a

libclass.a: my_mat.o 
	$(AR) -rcs libclass.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a