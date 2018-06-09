/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class name here>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * File:			battleship.h
 * Author:			Peter Bauer
 * Due Date:		#due#
 * ----------------------------------------------------------
 * Description:
 * <Add description>
 * ----------------------------------------------------------
 */
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#define FIELDSIZE 10

/**
*** The values assigned to each cell of the players, the opponents and the
*** guesses field. The player's and the opponent's field only hold the values
*** Water or Boat. The guesses field may also hold Unknowns. If a reference of
*** a shot or a guess (pair of row/col) is outside the field the value OutOfRange
*** is used.
*/
typedef enum {Water, Boat, Unknown, OutOfRange} CellContent;

/**
*** Loads the two files battleship.my and battleship.op which hold the fields
*** of the players. The files hold a stream of 10 times 10 values of type
*** CellContent.
*/
void load_game();

/**
*** @param row The row where we get the shot.
*** @param col The col where we get the shot.
*** @return The value of cell indicated by row and column of the own field (filled
*** with the values of battleship.my). If row/col point outside the field the
*** value OutOfRange is returned.
*/
CellContent get_shot(int row, int col);

/**
*** Sets the row and column of the my guesses table to the value held in the
*** opponents field. If this is a boat all surrounding cells are marked as water.
*** @param row The row where we place the shot
*** @param col The columnt where we place the shot.
*** @return True if target field is valid, i.e., inside the field, False otherwise.
*/
bool shoot(int row, int col);

/**
*** @param row The row where we want to get our own guess.
*** @param col The column where we want to get our own guess.
*** @return The value of the table with my guesses at row and column. If row/col
*** is outside the field OutOfRange is returned.
*/
CellContent get_my_guess(int row, int col);

#endif
