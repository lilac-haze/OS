#include <stdio.h>
#include <stdlib.h>

#include "bandit_input.h"
#include "bandit_output.h"
#include "bandit_logic.h"


int accountEnter()
{
    int n;
    while (1)
    {
        printf("\nEnter money: ");
        n = scanInt();
        if (n <= 0)
            incorrectBudgetPr();
        else
            return n;
    }
    return n;
}

  int EnterIntValue(char *Announcement, int LMargin, int UMargin){
	int Value = -32768;
	printf("%s", Announcement);
	while ((Value < LMargin) || (Value > UMargin)){
		printf("(Value shall be bigger than %d and less than %d): ", LMargin, UMargin);
		if (scanf ("%d", &Value) != 1) fseek(stdin, 0, SEEK_END); 
	}
	return Value;
} 


int betEnter(int budget)
{
    int n;
    while (1)
    {
        printf("\nEnter bet: ");
        n = scanInt();
        if (n > budget || n <= 0)
            incorrectBetPr();
        else
            return n;
    }
    return n;
}

int enterCont()
{
   
 /*  char choice[20];
   // scanf("%s", choice);
   // scanf("%c", &choice);
   // char answer[100];
    //int n;
    scanf("%s", choice);
    
    if (choice == "y" ||  choice == "yes")
	        return 1;
    
    else
        return 0;*/

int input;
    input = scanInt();
    if (input == 1)
        return 1;
    else
        return 0;

}

int scanInt()
{
    char answer[100];
    int n;
    scanf("%s", answer);
    while (sscanf(answer, "%d", &n) != 1)
    {
        printf("Incorrect data. Enter value again: ");
        scanf("%s", answer);
    }
    return n;
}
