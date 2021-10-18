#ifndef _LOGIC_H_
#define _LOGIC_H_


#define SUBJECTS 3

typedef struct {
    double mark;
    char subjectName[30];
} Subject;

typedef struct {
    char surname[20];
    int group;
    Subject subjects[SUBJECTS];
} Student;




Student* setStudents(int length, int maxNumberOfGroups);
void printStudents(Student* students, int length);
void printDebts(Student* students, int length, int number);
int printPassedStudents(Student* students, int length);
void printBestSubject(Student* students, int length);
double averageMarks(Student* students, int length, int groupNumber);
int theWorstGroup(Student* students, int length, int maxNumberOfGroups);

#endif
