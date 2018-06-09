/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class name here>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * File:			test_file_setup.h
 * Author:			Peter Bauer
 * Due Date:		#due#
 * ----------------------------------------------------------
 * Description:
 * <Add description>
 * ----------------------------------------------------------
 */
#ifndef TEST_FILE_SETUP_H
#define TEST_FILE_SETUP_H

/**
*** The initial setup of my field.
*/
#define MY_FIELD { \
	{	Water,	Water,	Water,	Water,	Water,	Boat,	Water,  Water,  Water,  Water}, \
	{	Boat,	Water,	Water,	Boat,	Water, 	Water, 	Water,  Water,  Water,  Water}, \
	{	Water,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,	Water,	Water,	Water,	Water,	Boat,   Water,	Water,	Water,	Water}, \
	{	Water,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Boat }, \
	{	Water,  Water, Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Boat,   Water,  Water}, \
	{	Water,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}  \
}

/**
*** The initial setup of the opponent's field.
*/
#define OPPONENT_FIELD { \
	{	Water,	Boat,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Boat,   Water}, \
	{	Boat,   Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Boat }, \
	{	Water,	Water,	Water,	Boat,   Water,	Water,	Water,	Water,	Water,  Water}, \
	{	Water,  Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water,	Water}, \
	{	Water,	Water,	Water,	Water,	Water,	Boat,   Water,	Water,	Water,	Water}  \
}

/**
*** Writes the content of the constants OPPONENT_FIELD and MY_FIELD into the files
*** battleship.op and battleship.my. This function is already implemented and is
*** to setup proper test data for the unit tests.
*/
void setup();

#endif
