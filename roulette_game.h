#ifndef ROULETTE_GAME_H
#define ROULETTE_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*
 * Purpose:
    Make a rough figure of a roulette wheel.
*/

void Roulette();
/*
 * Purpose:
    Simulate spinning the roulette wheel.

 * Return:
    The result of spinning the rouletter wheel.
*/

int spin_wheel();

/*
 * Purpose:
    Determines whether the bet number given by the user is as same as the value
    obtained by spinning the wheel or not.

 * Parameter:
    betting_number - the bet value given by the user.

 * Return:
    true if the value obtained from the user and spinning the wheel are same,
    false otherwise.
*/

_Bool single_bet(int betting_number);

/*
 * Purpose:
    Determines whether the bet type (even or odd) given by the user is as same
    as the type obtained by spinning the wheel or not.

 * Parameter:
    betting_type - the bet type (even or odd) given by the user.

 * Return:
    true if the bet type obtained from the user and spinning the wheel are same,
    false otherwise.
*/

_Bool even_odd_bet(int betting_type);

/*
 * Purpose:
    Determines whether the bet color (red or black) given by the user is as same
    as the color obtained by spinning the wheel or not.

 * Parameter:
    red - an array of values which fall under the color red.
    black - an array of values which fall under the color black.
    betting_color - the bet color (red or black) given by the user.

 * Return:
    true if the bet color obtained from the user and spinning the wheel are same,
    false otherwise.
*/

_Bool color_bet(const int red[], const int black[], int betting_color);

/*
 * Purpose:
    Determines whether the value obtained by spinning the wheel is between one
    to four or not.

 * Return:
    true if the obtained value is between one to four, false otherwise.
*/

_Bool first_four_bet();

/*
 * Purpose:
    Determines whether the bet type (low or high) given by the user is as same
    as the type obtained by spinning the wheel or not.

 * Parameter:
    low_high - the bet type (low or high) given by the user.

 * Return:
    true if the bet type obtained from the user and spinning the wheel are same,
    false otherwise.
*/

_Bool low_high_bet(int low_high);

#endif
