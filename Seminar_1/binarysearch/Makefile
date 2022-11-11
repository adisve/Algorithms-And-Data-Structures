SRC=src/
BIN=bin/
LIB=lib/
OBJ=obj/

test: $(OBJ)main.o $(OBJ)binarysearch.o
	gcc -Wall -Werror -o $(BIN)main $(OBJ)main.o $(OBJ)binarysearch.o $(OBJ)measurement.o

%.o: %.c
	gcc -c -Wall -Werror -o $@ $<

clean:
	rm -f $(OBJ)*.o test

build:
	gcc -Wall -Werror -c -o $(OBJ)main.o $(SRC)main.c
	gcc -Wall -Werror -c -o $(OBJ)binarysearch.o $(LIB)binarysearch.c
	gcc -Wall -Werror -c -o $(OBJ)measurement.o $(LIB)measurement.c