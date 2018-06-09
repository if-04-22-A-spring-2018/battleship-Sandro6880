/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			battleship_test_driver.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * checks the validity of credit card numbers
 *-----------------------------------------------------------------------------
*/
#include "shortcut.h"
#include "test_battleship.h"

int main(int arg, char *argv[])
{
	ADD_TEST(load_game);
	ADD_TEST(get_shot);
	ADD_TEST(get_shot_outside_field);
	ADD_TEST(shoot);
	ADD_TEST(get_my_guess);
	ADD_TEST(mark_surrounding_water);
	ADD_TEST(mark_at_border);

	run_tests();

	return 0;
}
