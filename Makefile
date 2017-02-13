CC=gcc
CFLAGS=-W -Wall -g
EXEC=hotPotatoGame

all: $(EXEC)

hotPotato.o: hotPotato.c
	$(CC) -o hotPotato.o -c hotPotato.c $(CFLAGS)

hotPotatoGame: main.o hotPotato.o
	$(CC) -o hotPotatoGame main.o hotPotato.o

main.o: main.c hotPotato.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o *.h.gch

mrproper: clean
	rm -rf $(EXEC)
