/**
 * CPE-TP3 : Jeu de la patate chaude
 *
 * @file main.c
 * @brief      Implement a mere game of hot potato with a player struct array
 * @author     Nathanaël SPRIET
 * @date       13/02/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hotPotato.h"

int main()
{
	int playerQuantity = 5;
	Player winner;
	initialiseArray(playerQuantity);
	winner = playGame();
	printf(ANSI_COLOR_GREEN"%s wins the game !\n"ANSI_COLOR_RESET,winner.name);
	return 0;
}
