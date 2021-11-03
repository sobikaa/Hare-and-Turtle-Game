CFLAGS=-std=c99 -Wall

roulette_game: roulette_game.o main.o
	gcc $(CFLAGS) roulette_game.o main.o -o roulette_game

main.o: main.c roulette_game.h
	gcc $(CFLAGS) -c main.c

roulette_game.o: roulette_game.h roulette_game.c
	gcc $(CFLAGS) -c roulette_game.c

clean:
	rm -f stats main.o roulette_game.o
