#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "logic.h"


#define SUBJECTS 3

Student* setStudents(int length, int maxNumberOfGroups) {
    Student* students = (Student*) malloc(sizeof(Student) * length);
	const char *a[5]; 
    a[0] = "Buzko";
    a[1] = "Ivanov";
    a[2] = "Pashkov";
    a[3] = "Sergeev";
    a[4] = "Romanenko";
    
   //int index;
   int i;
   
    for (i = 0; i < length; i++) {
        // surname
        strcpy(students[i].surname, a[i]);

        // group
        students[i].group = rand() % maxNumberOfGroups + 1;

        // subject marks
        students[i].subjects[0].mark = rand() % 100 + 1;
        strcpy(students[i].subjects[0].subjectName, "Web technology");
        students[i].subjects[1].mark = rand() % 100 + 1;
        strcpy(students[i].subjects[1].subjectName, "Ukranian");
        students[i].subjects[2].mark = rand() % 100 + 1;
        strcpy(students[i].subjects[2].subjectName, "Information Systems Design");
    
}
    return students;
}

void printStudents(Student* students, int length) {
    int i, j;
    printf("----------Students---------\n\n");
    for (i = 0; i < length; i++) {
    	printf("**************************\n");
        printf("Surname: %s; Group:%d\n\n", students[i].surname, students[i].group);
       
        printf("Subject marks:\n");
        for (j = 0; j < SUBJECTS; j++) {
            printf("%-30s|Mark: %5.2lf|\n", students[i].subjects[j].subjectName, students[i].subjects[j].mark);
        }
        printf("\n");
    }
}

void printDebts(Student* students, int length, int number) {
    int i, j;
    for (i = 0; i < length; i++) {
        for (j = 0; j < SUBJECTS; j++) {
            if (students[i].subjects[j].mark < number) {
                printf("%s\n", students[i].surname);
                break;
            }
        }
    }
}


int printPassedStudents(Student* students, int length) {
    int counter = 0;
    int i, j;
    for (i = 0; i < length; i++) {
        int allMarksWellOrExcellent = 1;
        for (j = 0; j < SUBJECTS; j++) {
            if (students[i].subjects[j].mark >= 50) {
                allMarksWellOrExcellent = 0;
                break;
            }
        }

        if (allMarksWellOrExcellent) {
            counter++;
        }
    }

    return counter;
}

void printBestSubject(Student* students, int length) {
    int i, j;
    for (i = 0; i < length; i++) {
        int index1 = 0;
        for (j = 1; j < SUBJECTS; j++) {
            if (students[i].subjects[j].mark > students[i].subjects[index1].mark) {
                index1 = j;
            }
        }
printf("%-20s   ''%s''\n", students[i].surname, students[i].subjects[index1].subjectName);
     
    }
}



double averageMarks(Student* students, int length, int groupNumber) {
    int i, j;
    int countOfSubjects = 0;
    double sumOfMarks = 0;

    for (i = 0; i < length; i++) {
        if (students[i].group == groupNumber) {
            for (j = 0; j < SUBJECTS; j++) {
                countOfSubjects++;
                sumOfMarks += students[i].subjects[j].mark;
            }
        }
    }

    return sumOfMarks / countOfSubjects;
}


int theWorstGroup(Student* students, int length, int maxNumberOfGroups) {
    int groupNumber;
    int worstGroupNumber = 1;
    int worstAverageMarks = averageMarks(students, length, 1);

    for (groupNumber = 2; groupNumber <= maxNumberOfGroups; groupNumber++) {
        int groupAverageMarks = averageMarks(students, length, groupNumber);
        if (groupAverageMarks < worstAverageMarks) {
            worstAverageMarks = groupAverageMarks;
            worstGroupNumber = groupNumber;
        }
    }

    return worstGroupNumber;
}
