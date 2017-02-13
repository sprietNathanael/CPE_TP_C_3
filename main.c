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
	int user_entry = 0;
	int userEntryLoop = 1;
	int playerQuantity = 5;
	do
	{
		printf("Combien de joueurs (de 1 à %d)?\n",MAX_PLAYER);
		scanf("%d", &playerQuantity);
		if(playerQuantity == 0 || playerQuantity > MAX_PLAYER)
		{
			printf("Entrée invalide : %d!\n",playerQuantity);
		}
	}while(playerQuantity == 0 || playerQuantity > MAX_PLAYER);
	Player winner;
	initialiseArray(playerQuantity);
	winner = playGame();
	printf(ANSI_COLOR_GREEN"%s wins the game !\n"ANSI_COLOR_RESET,winner.name);
	return 0;
}
