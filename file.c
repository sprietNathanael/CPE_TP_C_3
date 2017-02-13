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
