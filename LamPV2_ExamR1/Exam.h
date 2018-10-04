#ifndef _EXAM_H_
#define _EXAM_H_

#include <stdio.h>

struct Trainee
{
	char Name[30];
	float Math;
	float Lite;
	float Eng;
	float His;
	float Phy;
	float Avg;
};

/*Question 1: Create data file*/
void writeToFile(FILE *fp, char name[], float math, float lite, float eng, float his, float phy);
void createDataFile(FILE *fp);

/*Question 2*/
void loadContentData(FILE *fp, struct Trainee* Data[], int *n);
char selectMenu();
void displayMarkTable(struct Trainee* traneeList[], int n);
void displayTop5AverageMark(struct Trainee* traneeList[], int n);
void AvgCal(struct Trainee* traneeList[], int n);
void freeArray(struct Trainee* traneeList[], int n);

#endif
