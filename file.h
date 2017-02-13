/**
 * CPE-TP3 : Jeu de la patate chaude
 *
 * @file file.h
 * @brief      Useful tools to read / write players info into file
 * @author     Nathanaël SPRIET
 * @date       13/02/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FILE_H
#define FILE_H

#define WORD_MAX_SIZE 100
#define MAX_PLAYER	50

/*
***************************** Structures *************************
*/


/**
 * @brief      Represents a player ranking structure
 */
struct playerRanking
{
	char name[WORD_MAX_SIZE];/*!< The player's name */
	int count;/*!< The player's looses count */
};

/**
* @brief      A type defined over the Player structure
*/
typedef struct playerRanking PlayerRanking;

/*
***************************** Functions *************************
*/


/**
 * @brief      Saves the looser name.
 *
 * @param      name  The name of the looser player
 */
void saveTheLooserName(char* name);

/**
 * @brief      Print the best three players from file (the leass appearing players)
 */
void printBestThreePlayers();


/**
 * @brief      Print the best three players from file
 */
void printBestPlayer();

/**
 * @brief      Gets the player index in the array by its name.
 *
 * @param      name   The name of the desired player
 * @param      array  The array to search in
 *
 * @return     The player
 */
int getPlayerByName(char* name, PlayerRanking* array);

#endif
