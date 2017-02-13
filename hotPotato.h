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

#include <time.h>
#define WORD_MAX_SIZE 100
#define POTATO_LIFE_MAX 20
#define MAX_PLAYER	50

/*
***************************** Structures *************************
*/


/**
 * @brief      Represents a player structure
 */
struct player
{
	char name[WORD_MAX_SIZE];/*!< The player's name itself */
	int rightPlayer;/*!< The player's right neighbour */
	int leftPlayer;/*!< The player's left neighbour */
};

/**
* @brief      A type defined over the Player structure
*/
typedef struct player Player;

/*
***************************** Static variables *************************
*/

static int playerQuantity;
static Player playerArray[MAX_PLAYER];

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
 * @brief      Play a single round
 *
 * @param[in]  potatoLife  The potato life for this round
 */
void playRound(int potatoLife);

#endif
