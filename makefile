all: playlist.o linkedlist.o main.o
	gcc -o my_tunez playlist.o linkedlist.o main.o

playlist.o: playlist.c playlist.h
	gcc -c playlist.c playlist.h

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c linkedlist.h

main.o: main.c
	gcc -c main.c

run: all
	./my_tunez

clean:
	rm *.o
	rm *~