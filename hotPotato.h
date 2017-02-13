/**
 * CPE-TP3 : Je de la patate chaude
 *
 * @file hotPotato.h
 * @brief      Tools to manage a hot potato game
 * @author     Nathanaël SPRIET
 * @date       13/02/2017
 */

#ifndef HOT_POTATO_H
#define HOT_POTATO_H

#include <stdlib.h>
#include <stdio.h>

#include <time.h>
#include <string.h>
#include "file.h"

#define WORD_MAX_SIZE 100
#define POTATO_LIFE_MAX 20
#define MAX_PLAYER	50

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

/*
***************************** Structures *************************
*/


/**
 * @brief      Represents a player structure
 */
struct player
{
	char name[WORD_MAX_SIZE];/*!< The player's name itself */
	int nextPlayer;/*!< The player's next neighbour */
	int previousPlayer;/*!< The player's previous neighbour */
};

/**
* @brief      A type defined over the Player structure
*/
typedef struct player Player;

/*
***************************** Static variables *************************
*/
static Player currentPlayer;
static Player playerArray[MAX_PLAYER];
static char *namesArray[] =
{
	"Patrina",
	"Annie",
	"Tyesha",
	"Thuy",
	"Eugenie",
	"Neil",
	"Fletcher",
	"Moira",
	"Jacquie",
	"Janey",
	"Leota",
	"Wendi",
	"Tonette",
	"Ted",
	"Madge",
	"Roseanne",
	"Tyisha",
	"Kristle",
	"Melissia",
	"Susanne",
	"Hee",
	"Tomas",
	"Sol",
	"Adan",
	"Mireya",
	"Priscilla",
	"Mahalia",
	"Allyn",
	"Mitch",
	"Frances",
	"Alejandra",
	"Jerrod",
	"Tatyana",
	"Dorothea",
	"Isidra",
	"Inger",
	"Dagny",
	"Rick",
	"Matthew",
	"Enrique",
	"Yadira",
	"Gay",
	"Cathrine",
	"Kendal",
	"Serena",
	"Doria",
	"Vicki",
	"Nilda",
	"Jonie",
	"Lucilla"
};

/*
***************************** Functions *************************
*/

/**
 * @brief      Initialise the players array
 *
 * @param[in]  playerQuantity  The player quantity
 */
void initialiseArray(int playerQuantity);

/**
 * @brief      Play a whole game
 *
 * @return     The player that wins the game
 */
Player playGame();

/**
 * @brief      Play a whole game
 *
 * @param[in]  roundQuantity  The round quantity
 */
void playMultiGame(int roundQuantity);

/**
 * @brief      Play a single round
 *
 * @param[in]  potatoLife  The potato life for this round
 *
 * @return     The last player to have sent the potato
 */
Player playRound(int potatoLife);

#endif
