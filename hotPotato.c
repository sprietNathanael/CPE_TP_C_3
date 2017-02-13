#include "hotPotato.h"

void initialiseArray(int playerQuantity)
{
	Player currentPlayer;
	int i = 0;
	// For each player, create a structure and pushes it into the array
	for(i = 0; i < playerQuantity; i++)
	{
		strcpy(currentPlayer.name,namesArray[i]);
		currentPlayer.previousPlayer = i-1;
		currentPlayer.nextPlayer = i+1;
		playerArray[i] = currentPlayer;
	}
	// Return back to the last player
	i--;
	playerArray[i].nextPlayer = 0;
	playerArray[0].previousPlayer = i;
	// Print the result array
	for(i = 0; i < playerQuantity; i++)
	{
		printf("%d : %d -> %s -> %d\n",i, playerArray[i].previousPlayer,playerArray[i].name,playerArray[i].nextPlayer);
	}
}
