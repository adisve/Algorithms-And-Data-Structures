SRC=src/
BIN=bin/
LIB=lib/
OBJ=obj/

test: $(OBJ)main.o $(OBJ)heap.o $(OBJ)task_one.o $(OBJ)measurement.o
	gcc -Wall -Werror -o $(BIN)main $(OBJ)main.o $(OBJ)heap.o $(OBJ)task_one.o $(OBJ)measurement.o

%.o: %.c
	gcc -c -g -Wall -Werror -o $@ $<

clean:
	rm -f $(OBJ)*.o test

build:
	gcc -Wall -Werror -c -g -o $(OBJ)main.o $(SRC)main.c
	gcc -Wall -Werror -c -g -o $(OBJ)heap.o $(SRC)heap.c
	gcc -Wall -Werror -c -g -o $(OBJ)task_one.o $(SRC)task_one.c
	gcc -Wall -Werror -c -g -o $(OBJ)measurement.o $(SRC)measurement.c