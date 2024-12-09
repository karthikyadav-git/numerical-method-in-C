# Define compiler and flags
CC = gcc

# Targets and dependencies
all: directories bisection.o gauss_seidel.o
	$(CC) -o build/bisection obj/bisection.o
	$(CC) -o build/gauss_seidel obj/gauss_seidel.o

bisection: directories bisection.o
	$(CC) -o build/bisection obj/bisection.o

bisection.o: directories src/bisection.c
	$(CC) -c src/bisection.c -o obj/bisection.o

gauss_seidel: directories gauss_seidel.o
	$(CC) -o build/gauss_seidel obj/gauss_seidel.o

gauss_seidel.o: directories src/gauss_seidel.c
	$(CC) -c src/gauss_seidel.c -o obj/gauss_seidel.o

directories:
	mkdir build obj

clean:
	rm -rf obj/ build/
