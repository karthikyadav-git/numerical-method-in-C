# Define compiler and flags
CC = gcc

# Main build command for all methods
all: bisection gauss_seidel

# Indivisual method build
bisection: clean directories bisection.o
	$(CC) -o build/bisection obj/bisection.o

gauss_seidel: clean directories gauss_seidel.o
	$(CC) -o build/gauss_seidel obj/gauss_seidel.o

# Create object files
bisection.o: directories src/bisection.c
	$(CC) -c src/bisection.c -o obj/bisection.o

gauss_seidel.o: directories src/gauss_seidel.c
	$(CC) -c src/gauss_seidel.c -o obj/gauss_seidel.o

# Prepare directories for build
directories:
	mkdir build obj

# Clean/delete build and object files
clean:
	rm -rf obj/ build/
