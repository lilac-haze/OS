#include <stdio.h>

void printWelcome()
{
	printf ("* * * * * * * Welcome * * * * * * *\n\n");
	printf ("You need to insert money to play.\n\n");
}

void printBetReturn()
{
    printf("Bet return\n\n");
}

void printWin(int number)
{
    printf("Victory x%d!\n\n", number);
}

void printLose()
{
    printf("You losed!\n\n");
}

void printAccountBalance(int account)
{
    printf("Your account balance is now %d\n\n", account);
}

void printBankrot()
{
    printf("Chel ti bankrot\n\n");
}

void printCont()
{
    //printf("Do you want to continue?\n1 => Yes\n0 => No\nYour choose: ");
    printf (">> Do you want to continue? (yes => 1 | no => 0):\n");
}

void incorrectBetPr()
{
    printf("Incorrect bet count");
}

void incorrectBudgetPr()
{
    printf("Incorrect budget count");
}
