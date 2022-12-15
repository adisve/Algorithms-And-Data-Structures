SRC=src/
BIN=bin/
LIB=lib/
OBJ=obj/

test: $(OBJ)main.o $(OBJ)puzzle.o $(OBJ)hashtable.o
	gcc -Wall -Werror -o $(BIN)main $(OBJ)main.o $(OBJ)puzzle.o $(OBJ)hashtable.o

%.o: %.c
	gcc -c -g -Wall -Werror -o $@ $<

clean:
	rm -f $(OBJ)*.o test

build:
	gcc -Wall -Werror -c -g -o $(OBJ)main.o $(SRC)main.c
	gcc -Wall -Werror -c -g -o $(OBJ)puzzle.o $(SRC)puzzle.c
	gcc -Wall -Werror -c -g -o $(OBJ)hashtable.o $(SRC)hashtable.c