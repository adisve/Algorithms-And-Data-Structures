SRC=src/
BIN=bin/
LIB=lib/
OBJ=obj/

test: $(OBJ)main.o $(OBJ)balancing.o $(OBJ)stack.o 
	gcc -Wall -Werror -o $(BIN)main $(OBJ)main.o $(OBJ)balancing.o $(OBJ)stack.o 

%.o: %.c
	gcc -c -g -Wall -Werror -o $@ $<

clean:
	rm -f $(OBJ)*.o test

build:
	gcc -Wall -Werror -c -g -o $(OBJ)main.o $(SRC)main.c
	gcc -Wall -Werror -c -g -o $(OBJ)balancing.o $(LIB)balancing.c
	gcc -Wall -Werror -c -g -o $(OBJ)stack.o $(LIB)stack.c