#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "logic.h"

int main() {
    srand(time(NULL));

    int length = 5;
    int maxNumberOfGroups = 2;
    Student* students = setStudents(length, maxNumberOfGroups);

    printStudents(students, length);
	printf("**************************\n");
	
    printf("Debtor students:\n");
    printDebts(students, length, 50);
    printf("\n\n");

    printf("Percentage of students who passed all exams with good and excellent results: %.2lf \n\n",
           (double)(printPassedStudents(students, length) * 100) / length);

   printf("Best passed subjects of all students\n\n");
    printBestSubject(students, length);
    printf("\n");

    printf("The worst group is: %d\n", theWorstGroup(students, length, maxNumberOfGroups));
    return 0;
}
