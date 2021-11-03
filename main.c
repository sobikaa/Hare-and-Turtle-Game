#include <stdio.h>
#include "roulette_game.h"

int main (int argc, char **argv) {

    if (argc != 3) {
        printf("Usage: %s <Number of bets> <Output file>.\n", argv[0]);
        return 1;
    }

    // stores the number of times the user wants to bet.
    int num_of_bets = atoi(argv[1]);

    if (num_of_bets > 10) {
        printf("Error: Too many bets.");
        return 2;
    }

    FILE *fp_to_write = fopen(argv[2], "a");

    if (fp_to_write == NULL) {
        printf("Error opening %s for writing\n", argv[2]);
        return 3;
    }

    // stores the amount of money he won or lost during bets.
    int money_won = 0, money_owed = 0;

    // stores the number of times he won or lost the bets.
    int count_win = 0, count_lost = 0;

    Roulette();

    for (int i = 0; i < num_of_bets; i++) {

        // stores the type of bet the user wants to do and performs accordingly.
        int type_of_bet;

        printf("\n");
        printf("Enter 1, if you'd like to make a single bet.\n");
        printf("Enter 2, if you'd like to make a even/odd bet.\n");
        printf("Enter 3, if you'd like to make a color bet.\n");
        printf("Enter 4, if you'd like to make a first-fours bet. This means "
               "that you win if the ball falls between 1-4.\n");
        printf("Enter 5, if you'd like to make a low/high bet. Low = 1-18 and "
               "High = 19-36.\n\n");

        scanf("%i", &type_of_bet);

        // stores the value obtained by spinning the roulette wheel.
        int ball = spin_wheel();

        fprintf(fp_to_write, "The ball landed on %i.\n", ball);

        int red[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30,
                    32, 34, 36};
        int black[] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29,
                      31, 33, 35};

        if (type_of_bet == 1) {

            int betting_number;

            printf("Enter the betting number: ");
            scanf("%i", &betting_number);

            // stores the true or false value obtained from the function.
            int single = single_bet(betting_number);

            if (single == 1) {

                // the user receives $1000 since, he/she won the bet.
                money_won = money_won + 1000;
                count_win++;

                fprintf(fp_to_write, "You won the single bet.\n");
            }

            else {

                // the user has to pay $1000 since, he/she lost the bet.
                money_owed = money_owed + 1000;
                count_lost++;

                fprintf(fp_to_write, "You lost the single bet.\n");
            }
        }

        if (type_of_bet == 2) {

            int betting_type;

            printf("Enter 0 for an even bet and 1 for an odd bet: ");
            scanf("%i", &betting_type);

            // stores the true or false value obtained from the function.
            int even_odd = even_odd_bet(betting_type);

            if (even_odd == 1) {

                // the user receives an additional $500 since,
                // he/she won the bet.
                money_won = money_won + 500;
                count_win++;

                fprintf(fp_to_write, "You won the even/odd bet.\n");
            }

            else {

                // the user has to pay an additional $500 since,
                // he/she lost the bet.
                money_owed = money_owed + 500;
                count_lost++;

                fprintf(fp_to_write, "You lost the even/odd bet.\n");
            }
        }

        if (type_of_bet == 3) {

            int betting_color;

            printf("Enter 1 for red and 2 for black: ");
            scanf("%i", &betting_color);

            // stores the true or false value obtained from the function.
            int red_black = color_bet(red, black, betting_color);

            if (red_black == 1) {

                // the user receives an additional $500 since,
                // he/she won the bet.
                money_won = money_won + 500;
                count_win++;

                fprintf(fp_to_write, "You won the color bet.\n");
            }

            else {

                // the user has to pay an additional $500 since,
                // he/she lost the bet.
                money_owed = money_owed + 500;
                count_lost++;

                fprintf(fp_to_write, "You lost the color bet.\n");
            }
        }

        if (type_of_bet == 4) {

            // stores the true or false value obtained from the function.
            int first_four = first_four_bet();

            if (first_four == 1) {

                // the user receives and additional $800 since,
                // he/she won the bet.
                money_won = money_won + 800;
                count_win++;

                fprintf(fp_to_write, "You won the first_four bet.\n");
            }

            else {

                // the user has to pay an additional $800 since,
                // he/she lost the bet.
                money_owed = money_owed + 800;
                count_lost++;

                fprintf(fp_to_write, "You lost the first_four bet.\n");
            }
        }

        if (type_of_bet == 5) {

            int low_high;

            printf("Enter 0 for low bet and 1 for high bet: ");
            scanf("%i", &low_high);

            // stores the true or false value obtained from the function.
            int low__high = low_high_bet(low_high);

            if (low__high == 1) {

                // the user receives and additional $500 since,
                // he/she won the bet.
                money_won = money_won + 500;
                count_win++;

                fprintf(fp_to_write, "You won the low/high bet.\n");
            }

            else {

                // the user has to pay an additional $500 since,
                // he/she lost the bet.
                money_owed = money_owed + 500;
                count_lost++;

                fprintf(fp_to_write, "You lost the low/high bet.\n");
            }
        }
    }

    fprintf(fp_to_write,"\n");

    fprintf(fp_to_write, "You won the bets %i times and lost %i times.\n", \
            count_win, count_lost); \

    fprintf(fp_to_write,"\n");

    if (money_won > money_owed) {
        fprintf(fp_to_write, "You've won $%i.\n", money_won - money_owed);
    }

    else if (money_won < money_owed) {
        fprintf(fp_to_write, "You owe the casino $%i.\n",
                money_owed - money_won);
    }

    else {
        fprintf(fp_to_write, "Good news: You don't owe anything to the casino. \
                \n Bad news: You didn't win any money.\n"); \
    }

    fclose(fp_to_write);

    return 0;

}
