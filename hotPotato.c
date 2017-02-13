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
		// Save the winner
		winnerOfRound = playRound(potatoLife);
		// The previous player of the looser takes for its next player the next player of the looser
		playerArray[currentPlayer.previousPlayer].nextPlayer = currentPlayer.nextPlayer;
		// The next player of the looser takes for its previous player the previous player of the looser
		playerArray[currentPlayer.nextPlayer].previousPlayer = currentPlayer.previousPlayer;
		// Print the result
		printf(ANSI_COLOR_RED"(%d->%s->%d) lost : %d.N = %d ; %d.P = %d \n"ANSI_COLOR_RESET,currentPlayer.previousPlayer,currentPlayer.name,currentPlayer.nextPlayer,currentPlayer.previousPlayer, playerArray[currentPlayer.previousPlayer].nextPlayer,currentPlayer.nextPlayer,playerArray[currentPlayer.nextPlayer].previousPlayer);
		// Set the current player to the winner
		currentPlayer = winnerOfRound;
	// If the current player has the value for next and previous player, it means he's the last one
	}while(currentPlayer.nextPlayer != currentPlayer.previousPlayer);
	// Return the winner of the game
	return(currentPlayer);
}

void playMultiGame(int roundQuantity)
{
	int roundIncrement = 0;
	Player winnerOfRound;
	currentPlayer = playerArray[0];
	for(roundIncrement = 0;roundIncrement < roundQuantity; roundIncrement++)
	{
		printf(ANSI_COLOR_BLUE"Round n° : %d\n"ANSI_COLOR_RESET,roundIncrement+1);
		// Pick a random number between 1 and POTATO_LIFE_MAX
		int potatoLife = (rand()%(POTATO_LIFE_MAX-1))+1;
		// Save the winner
		winnerOfRound = playRound(potatoLife);
		// Print the result
		printf(ANSI_COLOR_RED"%s lost\n"ANSI_COLOR_RESET,currentPlayer.name);
		// Save the looser name into the file
		if(roundQuantity > 1)
		{
			saveTheLooserName(currentPlayer.name);
		}
		// Set the current player to the winner
		currentPlayer = winnerOfRound;
	}
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
		// Print the result
		printf("\t%d : %s -> %s\n",i,lastPlayerToPlay.name, currentPlayer.name);
	}
	return(lastPlayerToPlay);
}
