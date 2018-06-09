/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			test_battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Unit tests for battleship
 *-----------------------------------------------------------------------------
*/
#include "battleship.h"

#include "test_file_setup.h"
#include "test_battleship.h"

/* --------------------------- Test functions -------------------------------- */

/******************************************************************************
 * test_load_game
 *
 * tests function load_game
 ******************************************************************************/
TEST(load_game)
{
	int i;
	int j;

	setup();
	load_game();
	ASSERT_EQUALS(Water, get_shot(0, 0));
	ASSERT_EQUALS(Boat, get_shot(0, 5));
	ASSERT_EQUALS(Boat, get_shot(5, 9));

	for (i = 0; i < FIELDSIZE; i++) {
		for (j = 0; j < FIELDSIZE; j++) {
			ASSERT_EQUALS(Unknown, get_my_guess(i, j));
		}
	}
}

/******************************************************************************
 * test_get_shot
 *
 * tests the function get_shot
 ******************************************************************************/
TEST(get_shot)
{
	setup();
	load_game();

	ASSERT_EQUALS(Water, get_shot(0, 0));
	ASSERT_EQUALS(Boat, get_shot(1, 0));
	ASSERT_EQUALS(Boat, get_shot(1, 3));

	for (int i = 0; i < FIELDSIZE; i++) {
		ASSERT_EQUALS(Water, get_shot(2, i));
	}

	ASSERT_EQUALS(Water, get_shot(0, FIELDSIZE - 1));
	ASSERT_EQUALS(Water, get_shot(FIELDSIZE - 1, 0));
	ASSERT_EQUALS(Water, get_shot(FIELDSIZE - 1 , FIELDSIZE - 1));
}

TEST(get_shot_outside_field) {
	setup();
	load_game();

	ASSERT_EQUALS(OutOfRange, get_shot(-1, 0));
	ASSERT_EQUALS(OutOfRange, get_shot(FIELDSIZE, 0));
	ASSERT_EQUALS(OutOfRange, get_shot(0, -1));
	ASSERT_EQUALS(OutOfRange, get_shot(0, FIELDSIZE));
	ASSERT_EQUALS(OutOfRange, get_shot(FIELDSIZE, FIELDSIZE));
}

/******************************************************************************
 * test_shoot
 *
 * tests function shoot
 ******************************************************************************/
TEST(shoot)
{
	setup();
	load_game();

	ASSERT_FALSE(shoot(-1, -1), "Shot to (-1, -1) must NOT be possible");
	ASSERT_FALSE(shoot(-1, FIELDSIZE), "Shot to (-1, FIELDSIZE) must NOT be possible");
	ASSERT_FALSE(shoot(FIELDSIZE, -1), "Shot to (FIELDSIZE, -1) must NOT be possible");
	ASSERT_FALSE(shoot(FIELDSIZE, FIELDSIZE), "Shot to (FIELDSIZE, FIELDSIZE) must NOT be possible");
	ASSERT_FALSE(shoot(-1, 5), "Shot to (-1, 5) must NOT be possible");

	ASSERT_TRUE(shoot(0, 0), "Shot to (0, 0) must be possible");
	ASSERT_EQUALS(Water, get_my_guess(0, 0));

	ASSERT_TRUE(shoot(3, 8), "Shot to (3, 8) must be possible");
	ASSERT_EQUALS(Boat, get_my_guess(3, 8));
}

/******************************************************************************
 * test_get_my_guess
 *
 * tests function get_my_guess
 ******************************************************************************/
TEST(get_my_guess)
{
	setup();
	load_game();

	ASSERT_TRUE(shoot(4, 4), "Shot to (4, 4) must be possible");
	ASSERT_EQUALS(Water, get_my_guess(4, 4));

	ASSERT_TRUE(shoot(3, 8), "Shot to (3, 8) must be possible");
	ASSERT_EQUALS(Boat, get_my_guess(3, 8));

	for (int i = 0; i < FIELDSIZE; i++) {
		ASSERT_TRUE(get_my_guess(1, i) == Unknown, "Row #1: Unknown expected");
	}

	for (int i = 0; i < FIELDSIZE; i++) {
		ASSERT_TRUE(get_my_guess(7, i) == Unknown, "Col #1: Unknown expected");
	}

	ASSERT_TRUE(get_my_guess(-1, -1) == OutOfRange, "(-1, -1): OutOfRange expected");
}

/******************************************************************************
 * test_mark_surrounding_water
 *
 * tests whether shoot hits a boat all cells around are marked with water
 ******************************************************************************/
TEST(mark_surrounding_water)
{
	setup();
	load_game();

	shoot(3, 8);
	ASSERT_EQUALS(Water, get_my_guess(2, 7));
	ASSERT_EQUALS(Water, get_my_guess(2, 8));
	ASSERT_EQUALS(Water, get_my_guess(2, 9));
	ASSERT_EQUALS(Water, get_my_guess(3, 7));
	ASSERT_EQUALS(Boat, get_my_guess(3, 8));
	ASSERT_EQUALS(Water, get_my_guess(3, 9));
	ASSERT_EQUALS(Water, get_my_guess(4, 7));
	ASSERT_EQUALS(Water, get_my_guess(4, 8));
	ASSERT_EQUALS(Water, get_my_guess(4, 9));

	for (int i = 0; i < FIELDSIZE; i++) {
		for (int j = 0; j < FIELDSIZE; j++) {
			if (i != 2 && i != 3 && i != 4 && j != 7 && j != 8 && j != 9) {
				ASSERT_EQUALS(Unknown, get_my_guess(i, j));
			}
		}
	}
}

/******************************************************************************
 * test_mark_at_border
 *
 * tests water marking at field borders
 ******************************************************************************/
TEST(mark_at_border)
{
	setup();
	load_game();

	shoot(0, 1);
	ASSERT_EQUALS(Water, get_my_guess(0, 0));
	ASSERT_EQUALS(Boat, get_my_guess(0, 1));
	ASSERT_EQUALS(Water, get_my_guess(0, 2));
	ASSERT_EQUALS(Water, get_my_guess(1, 0));
	ASSERT_EQUALS(Water, get_my_guess(1, 1));
	ASSERT_EQUALS(Water, get_my_guess(1, 2));

	shoot(4, 0);
	ASSERT_EQUALS(Water, get_my_guess(3, 0));
	ASSERT_EQUALS(Water, get_my_guess(3, 1));
	ASSERT_EQUALS(Boat, get_my_guess(4, 0));
	ASSERT_EQUALS(Water, get_my_guess(4, 1));
	ASSERT_EQUALS(Water, get_my_guess(5, 0));
	ASSERT_EQUALS(Water, get_my_guess(5, 1));

	shoot(9, 5);
	ASSERT_EQUALS(Water, get_my_guess(8, 4));
	ASSERT_EQUALS(Water, get_my_guess(8, 5));
	ASSERT_EQUALS(Water, get_my_guess(8, 6));
	ASSERT_EQUALS(Water, get_my_guess(9, 4));
	ASSERT_EQUALS(Boat, get_my_guess(9, 5));
	ASSERT_EQUALS(Water, get_my_guess(9, 6));
}
