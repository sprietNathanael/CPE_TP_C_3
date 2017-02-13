CC=gcc
CFLAGS=-W -Wall -g
EXEC=hotPotatoGame

all: $(EXEC)

hotPotatoGame: main.o hotPotato.o file.o
	$(CC) -o hotPotatoGame main.o hotPotato.o file.o

main.o: main.c hotPotato.h
	$(CC) -o main.o -c main.c $(CFLAGS)

hotPotato.o: hotPotato.c file.h
	$(CC) -o hotPotato.o -c hotPotato.c $(CFLAGS)

file.o: file.c
	$(CC) -o file.o -c file.c $(CFLAGS)

clean:
	rm -rf *.o *.h.gch

mrproper: clean
	rm -rf $(EXEC)
