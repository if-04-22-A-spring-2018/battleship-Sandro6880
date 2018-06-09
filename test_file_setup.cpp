/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			test_file_setup.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>

#include "battleship.h"
#include "test_file_setup.h"

/* ------------------------ Global data --------------------------------------- */
static CellContent my[FIELDSIZE][FIELDSIZE] = MY_FIELD;

static CellContent op[FIELDSIZE][FIELDSIZE] = OPPONENT_FIELD;


/* -------------------- Private function prototypes -------------------------- */
static void write_file(CellContent gamedata[FIELDSIZE][FIELDSIZE], FILE *fd);

/* -------------------- Public function implementation ----------------------- */
void setup()
{
	FILE *my_fd = fopen("battleship.my", "w");
	FILE *op_fd = fopen("battleship.op", "w");

	write_file(my, my_fd);
	write_file(op, op_fd);

	fclose(my_fd);
	fclose(op_fd);
}

/* ------------------- Implementation of private functions ------------------ */
static void write_file(CellContent gamedata[FIELDSIZE][FIELDSIZE], FILE *fd)
{
	int i;

	for (i = 0; i < FIELDSIZE; i++) {
		fwrite(gamedata[i], sizeof(CellContent), FIELDSIZE, fd);
	}
}
