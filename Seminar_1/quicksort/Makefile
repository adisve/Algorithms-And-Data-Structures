SRC=src/
BIN=bin/
LIB=lib/
OBJ=obj/

test: $(OBJ)main.o $(OBJ)quicksort.o $(OBJ)measurement.o $(OBJ)math.o
	gcc -Wall -Werror -o $(BIN)main $(OBJ)main.o $(OBJ)quicksort.o $(OBJ)measurement.o $(OBJ)math.o

%.o: %.c
	gcc -c -g -Wall -Werror -o $@ $<

clean:
	rm -f $(OBJ)*.o test

build:
	gcc -Wall -Werror -c -g -o $(OBJ)main.o $(SRC)main.c
	gcc -Wall -Werror -c -g -o $(OBJ)quicksort.o $(LIB)quicksort.c
	gcc -Wall -Werror -c -g -o $(OBJ)measurement.o $(LIB)measurement.c
	gcc -Wall -Werror -c -g -o $(OBJ)math.o $(LIB)math.c