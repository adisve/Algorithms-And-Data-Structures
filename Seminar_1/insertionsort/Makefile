SRC=src/
BIN=bin/
LIB=lib/
OBJ=obj/

test: $(OBJ)main.o $(OBJ)insertionsort.o $(OBJ)measurement.o
	gcc -Wall -Werror -o $(BIN)main $(OBJ)main.o $(OBJ)insertionsort.o $(OBJ)measurement.o

%.o: %.c
	gcc -c -Wall -Werror -o $@ $<

clean:
	rm -f $(OBJ)*.o test

build:
	gcc -Wall -Werror -c -o $(OBJ)main.o $(SRC)main.c
	gcc -Wall -Werror -c -o $(OBJ)insertionsort.o $(LIB)insertionsort.c
	gcc -Wall -Werror -c -o $(OBJ)measurement.o $(LIB)measurement.c