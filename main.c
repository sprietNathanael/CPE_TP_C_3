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

#define MAX_ROUND 30

int main()
{
	int user_entry = 0;
	int userEntryLoop = 1;
	int playerQuantity = 5;
	int roundQuantity = 1;
	// While loop to choose the number of players
	do
	{
		printf("Combien de joueurs (de 1 à %d)?\n",MAX_PLAYER);
		scanf("%d", &playerQuantity);
		if(playerQuantity == 0 || playerQuantity > MAX_PLAYER)
		{
			printf(ANSI_COLOR_RED"Entrée invalide !\n"ANSI_COLOR_RESET,playerQuantity);
		}
	}while(playerQuantity == 0 || playerQuantity > MAX_PLAYER);

	// While loop to choose the mode
	do
	{
		printf("Quel mode ?\n");
		printf("\t 1- Jeu unique\n");
		printf("\t 2- Championnat\n\t");
		scanf("%d", &user_entry);
		switch (user_entry)
		{
			case 1:
				roundQuantity = 1;
				userEntryLoop = 0;
				break;
			case 2:
				// While loop to choose the number of rounds
				do
				{
					printf("Combien de tours (de 2 à %d) ?\n",MAX_ROUND);
					scanf("%d", &roundQuantity);
					if(roundQuantity < 2 || roundQuantity > MAX_ROUND)
					{
						printf(ANSI_COLOR_RED"Entrée invalide !\n"ANSI_COLOR_RESET);
					}
					else
					{
						userEntryLoop = 0;
					}
				} while(userEntryLoop);
				break;
			default:
				printf(ANSI_COLOR_RED"Entrée invalide !\n"ANSI_COLOR_RESET);
		}
	}while(userEntryLoop);
	Player winner;
	initialiseArray(playerQuantity);
	if(roundQuantity < 2)
	{
		winner = playGame();
		printf(ANSI_COLOR_GREEN"%s wins the game !\n"ANSI_COLOR_RESET,winner.name);
	}
	else
	{
		playMultiGame(roundQuantity);
		printf("Les trois meilleurs joueurs : \n");
		printBestThreePlayers();
	}
	return 0;
}
