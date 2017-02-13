/**
 * CPE-TP3 : Jeu de la patate chaude
 *
 * @file file.c
 * @brief      Useful tools to read / write players info into file
 * @author     Nathanaël SPRIET
 * @date       13/02/2017
 */

#include "file.h"

void saveTheLooserName(char* name)
{
	FILE *loosersFile = fopen("loosers.txt", "a+");
	if (loosersFile == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}

	fprintf(loosersFile, "%s\n", name);
	fclose(loosersFile);
}

void printBestThreePlayers()
{
	system("sort loosers.txt| uniq -c | sort -n | sed -r 's/[0-9]+\ //' | head -n 3");
}

void printBestPlayer()
{
	PlayerRanking rankingArray[MAX_PLAYER];
	PlayerRanking intermediatePlayer;
	int currentIndex = 0;
	FILE *loosersFile = fopen("loosers.txt", "r");
	if (loosersFile == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}
	char* currentLine = NULL;
	size_t length = 0;
	ssize_t read;
	int indexOfDesiredPlayer;
	// Read the file line by line
	while((read = getline(&currentLine, &length, loosersFile)) != -1)
	{
		indexOfDesiredPlayer = getPlayerByName(currentLine, rankingArray);
		// If the current player is not in the array yet
		if(indexOfDesiredPlayer == -1)
		{
			strcpy(intermediatePlayer.name,currentLine);
			intermediatePlayer.count = 1;
			rankingArray[currentIndex++] = intermediatePlayer;
		}
		else
		{	//else, just increment its counter
			rankingArray[indexOfDesiredPlayer].count++;
		}
	}
	fclose(loosersFile);

	intermediatePlayer = rankingArray[0];
	int i = 0;
	// Browse the array to find the smallest counter
	for(i = 0; i < currentIndex;i++)
	{
		if(rankingArray[i].count < intermediatePlayer.count)
		{
			intermediatePlayer = rankingArray[i];
		}
	}
	printf("Le meilleur joueur est : %s \n",intermediatePlayer.name);
}

int getPlayerByName(char* name, PlayerRanking* array)
{
	int i = 0;
	for(i = 0; i < MAX_PLAYER; i++)
	{
		if(!(strcmp(array[i].name,name)))
		{
			return(i);
		}
	}
	return(-1);
}
