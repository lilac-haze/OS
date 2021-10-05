#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bandit_logic.h"
#include "bandit_input.h"
#include "bandit_output.h"


int main()
{
    srand(time(NULL));
    printWelcome();
    int account = accountEnter();
    int len;
    len = EnterIntValue((char*)"Please enter length of numbers ", 3, 9);

    int play = 1;

    while (play) {
        int bet = betEnter(account);

        int* arr = generateNumbers(len);
        printArray(arr, len);

        if (isTwoThirdsNumbersTheSame(arr, len) || isArrayContainsNumber(arr, len, 7)) {
            printBetReturn();
        }
        else if (isAllNumbersEqualsNumber(arr, len, 7)) {
            printWin(3);
            account += bet * 3;
        }
        else if (isAllNumbersTheSame(arr, len)) {
            printWin(2);
            account += bet * 2;
        }
        else {
            printLose();
            account -= bet;
        }

        printAccountBalance(account);

        if (account <= 0) {
            printBankrot();
        }

        printCont();
        int continue_game = enterCont();

        if (continue_game == 0) {
            play = 0;
        }
        else if (continue_game == 1 && account <= 0) {
            account = accountEnter();
        }
    }

    return 0;
}

