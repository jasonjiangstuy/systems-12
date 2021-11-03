all: main.o
	gcc -o myls main.o

main.o: main.c
	gcc -c main.c

run: myls
	./myls
