all: linkedlist.o playlist.o main.o
	gcc -o my_tunez linkedlist.o playlist.o main.o

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c linkedlist.h

playlist.o: playlist.c playlist.h
	gcc -c playlist.c playlist.h

main.o: main.c
	gcc -c main.c

run: all
	./my_tunez

clean:
	rm -f *.o
	rm -f *~
