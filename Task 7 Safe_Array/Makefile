cc = g++

cflags = -Wall

stack:main.cpp
	$(cc) $(cflags) main.cpp safe_array.cpp -o main -O3

run:stack
	./main

clean:
	rm -rf main
	rm -rf *.o

