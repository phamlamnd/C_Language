#include <stdio.h>
#define MAX 100
struct Student
{
	int id;
	char name[30];
	char sex[30];
	float mark1;
	float mark2;
	float mark3;
	float avg;
};


void input(struct Student studentsList[], int *n)
{
	do{
		printf("\nEnter number of student: ");
		scanf("%d", n);
	}while(*n < 0 || *n > MAX);
	
	int i;
	for(i = 0; i < *n; i++)
	{
		printf("\nEnter ID: ");
		scanf("%d", &studentsList[i].id);
		
		printf("\nEnter name: ");
		fflush(stdin);
		gets(studentsList[i].name);
		
		printf("\nEnter sex: ");
		fflush(stdin);
		gets(studentsList[i].sex);
		
		printf("\nEnter Mark1: ");
		scanf("%f", &studentsList[i].mark1);
		
		printf("\nEnter Mark1: ");
		scanf("%f", &studentsList[i].mark2);
		
		printf("\nEnter Mark1: ");
		scanf("%f", &studentsList[i].mark3);
	}
}

void output(struct Student studentsList[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\n", studentsList[i].id, studentsList[i].name, studentsList[i].sex, studentsList[i].mark1, studentsList[i].mark2, studentsList[i].mark3);
	}
}

void avgCal(struct Student studentsList[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		studentsList[i].avg = (studentsList[i].mark1 + studentsList[i].mark2 + studentsList[i].mark3)/3;
	}
}


int main()
{
	struct Student studentsList[MAX];
	int n;
	input(studentsList, &n);
	output(studentsList, n);
	return 0;
}
