SRC=src/
BIN=bin/
LIB=lib/
OBJ=obj/

test: $(OBJ)main.o $(OBJ)probing_hash.o $(OBJ)chaining_hash.o $(OBJ)test_chaining.o $(OBJ)test_probing.o
	gcc -Wall -Werror -o $(BIN)main $(OBJ)main.o $(OBJ)probing_hash.o $(OBJ)chaining_hash.o $(OBJ)test_chaining.o $(OBJ)test_probing.o

%.o: %.c
	gcc -c -g -Wall -Werror -o $@ $<

clean:
	rm -f $(OBJ)*.o test

build:
	gcc -Wall -Werror -c -g -o $(OBJ)main.o $(SRC)main.c
	gcc -Wall -Wno-unused-function -Werror -c -g -o $(OBJ)probing_hash.o $(SRC)probing_hash.c
	gcc -Wall -Wno-unused-function -Werror -c -g -o $(OBJ)chaining_hash.o $(SRC)chaining_hash.c
	gcc -Wall -Werror -c -g -o $(OBJ)test_probing.o $(SRC)test_probing.c
	gcc -Wall -Werror -c -g -o $(OBJ)test_chaining.o $(SRC)test_chaining.c