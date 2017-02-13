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

#define WORD_MAX_SIZE 100

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

#endif
