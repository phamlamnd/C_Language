#ifndef _DAY7_H_
#define _DAY7_H_
#define MAX 100
#include <stdio.h>

struct Student
{
	char name[30];
	float mark;
};

/*Question 1*/
extern struct Student inputOneStudent();
extern void writeToFileNew(char *filename);

/*Question 2*/
extern void writeToFileAppended(char *filename);

/*Question 3*/
extern void inputArrayStudent(struct Student Array[], int *n);
extern void writeArrayToFile(struct Student Array[], int n, char *filename);
extern void readFileAndDislay(char *filename);

/*Question 4*/
extern void copyFile(char *filename1, char *filename2);

/*Question 5*/

/*Question 6*/
extern void deleteFile(char *filename);

/*Question 7*/
extern void mergeFile(char *filename1, char *filename2, char *filename3);

/*Question 8*/
extern int countNumberLines(char *filename);

#endif

