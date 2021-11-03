#include "roulette_game.h"

void Roulette() {

   printf("\t\t\t _______________________________________ \n");
   printf("\t\t\t|         |         |         |         |\n");
   printf("\t\t\t|    1    |    2    |    3    |         |\n");
   printf("\t\t\t|  *RED*  | *BLACK* |  *RED*  |         |\n");
   printf("\t\t\t|_________|_________|_________|         |\n");
   printf("\t\t\t|         |         |         |         |\n");
   printf("\t\t\t|    4    |    5    |    6    |  *LOW*  |\n");
   printf("\t\t\t| *BLACK* |  *RED*  | *BLACK* |  1 - 18 |\n");
   printf("\t\t\t|_________|_________|_________|         |\n");
   printf("\t\t\t|         |         |         |         |\n");
   printf("\t\t\t|    7    |    8    |    9    |         |\n");
   printf("\t\t\t|  *RED*  | *BLACK* |  *RED*  |         |\n");
   printf("\t\t\t|_________|_________|_________|_________|\n");
   printf("\t\t\t|         |         |         |         |\n");
   printf("\t\t\t|    10   |    11   |    12   |         |\n");
   printf("\t\t\t| *BLACK* | *BLACK* |  *RED*  |         |\n");
   printf("\t\t\t|_________|_________|_________|         |\n");
   printf("\t\t\t|         |         |         |         |\n");
   printf("\t\t\t|    13   |    14   |    15   |  *EVEN* |\n");
   printf("\t\t\t| *BLACK* |  *RED*  | *BLACK* |         |\n");
   printf("\t\t\t|_________|_________|_________|         |\n");
   printf("\t\t\t|         |         |         |         |\n");
   printf("\t\t\t|    16   |    17   |    18   |         |\n");
   printf("\t\t\t|  *RED*  | *BLACK* |  *RED*  |         |\n");
   printf("\t\t\t|_________|_________|_________|_________|\n");
   printf("\t\t\t|         |         |         |         |\n");
   printf("\t\t\t|    19   |    20   |    21   |         |\n");
   printf("\t\t\t|  *RED*  | *BLACK* |  *RED*  |         |\n");
   printf("\t\t\t|_________|_________|_________|         |\n");
   printf("\t\t\t|         |         |         |         |\n");
   printf("\t\t\t|    22   |    23   |    24   |  *ODD*  |\n");
   printf("\t\t\t| *BLACK* |  *RED*  | *BLACK* |         |\n");
   printf("\t\t\t|_________|_________|_________|         |\n");
   printf("\t\t\t|         |         |         |         |\n");
   printf("\t\t\t|    25   |    26   |    27   |         |\n");
   printf("\t\t\t|  *RED*  | *BLACK* |  *RED*  |         |\n");
   printf("\t\t\t|_________|_________|_________|_________|\n");
   printf("\t\t\t|         |         |         |         |\n");
   printf("\t\t\t|    28   |    29   |    30   |         |\n");
   printf("\t\t\t| *BLACK* | *BLACK* |  *RED*  |         |\n");
   printf("\t\t\t|_________|_________|_________|         |\n");
   printf("\t\t\t|         |         |         |         |\n");
   printf("\t\t\t|    31   |    32   |    33   |  *HIGH* |\n");
   printf("\t\t\t| *BLACK* |  *RED*  | *BLACK* | 19 - 36 |\n");
   printf("\t\t\t|_________|_________|_________|         |\n");
   printf("\t\t\t|         |         |         |         |\n");
   printf("\t\t\t|    34   |    35   |    36   |         |\n");
   printf("\t\t\t|  *RED*  | *BLACK* |  *RED*  |         |\n");
   printf("\t\t\t|_________|_________|_________|_________|\n");
   printf("\n");

}

int spin_wheel() {

    srand(time(NULL));
    return rand() % 36 + 1;
}

_Bool single_bet(int betting_number) {

    int ball = spin_wheel();

    if (betting_number == ball) {
        return true;
    }

    return false;
}

_Bool even_odd_bet(int betting_type) {

    int ball = spin_wheel();

    if (ball % 2 == 0) {

        if (betting_type == 0) {
            return true;
        }

        return false;
    }

    else {

        if (betting_type == 1) {
            return true;
        }

        return false;
    }
}

_Bool color_bet(const int red[], const int black[], int betting_color) {

    int ball = spin_wheel();

    if (betting_color == 0) {
        for (size_t i = 0; i < sizeof(*red); i++) {
            if (red[i] == ball) {
                return true;
            }
        }
    }

    if (betting_color == 1) {
        for (size_t i = 0; i < sizeof(*black); i++) {
            if (black[i] == ball) {
                return true;
            }
        }
    }

    return false;
}

_Bool first_four_bet() {

    int ball = spin_wheel();

    if (ball >= 1 && ball <= 4) {
        return true;
    }

    return false;
}

_Bool low_high_bet(int low_high) {

    int ball = spin_wheel();

    if (low_high == 0) {
        if (ball >= 1 && ball <= 18) {
            return true;
        }
    }

    if (low_high == 1) {
        if (ball > 18 && ball <= 36) {
            return true;
        }
    }

    return false;
}
