#include "hotPotato.h"

void initialiseArray(int playerQuantity)
{
	Player currentPlayer;
	int i = 0;
	// Initialise randomisation
	srand(time(NULL));
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

Player playGame()
{
	currentPlayer = playerArray[0];
	Player winnerOfRound;
	do
	{
		// Pick a random number between 1 and POTATO_LIFE_MAX
		int potatoLife = (rand()%(POTATO_LIFE_MAX-1))+1;
		winnerOfRound = playRound(potatoLife);
		playerArray[currentPlayer.previousPlayer].nextPlayer = currentPlayer.nextPlayer;
		playerArray[currentPlayer.nextPlayer].previousPlayer = currentPlayer.previousPlayer;
		printf(ANSI_COLOR_RED"(%d->%s->%d) lost : %d.N = %d ; %d.P = %d \n"ANSI_COLOR_RESET,currentPlayer.previousPlayer,currentPlayer.name,currentPlayer.nextPlayer,currentPlayer.previousPlayer, playerArray[currentPlayer.previousPlayer].nextPlayer,currentPlayer.nextPlayer,playerArray[currentPlayer.nextPlayer].previousPlayer);
		currentPlayer = winnerOfRound;
	}while(currentPlayer.nextPlayer != currentPlayer.previousPlayer);
	return(currentPlayer);
}

Player playRound(int potatoLife)
{
	printf("Round of : %d\n",potatoLife);
	int i = 0;
	Player lastPlayerToPlay;
	for(i = 0; i < potatoLife;i++)
	{
		// Save the lastPlayerToPlay
		lastPlayerToPlay = currentPlayer;
		// Pick a random decision (1 or 0)
		if(rand() & 1)
		{
			currentPlayer = playerArray[currentPlayer.nextPlayer];
		}
		else
		{
			currentPlayer = playerArray[currentPlayer.previousPlayer];
		}
		printf("\t%d : %s -> %s\n",i,lastPlayerToPlay.name, currentPlayer.name);
	}
	return(lastPlayerToPlay);
}
