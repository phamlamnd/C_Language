#include "Day7.h"
#include <stdio.h>
#include <string.h>


/*Question 1: Write a C program to read name and marks of n number of students from user and store them in a file*/
struct Student inputOneStudent()
{
	struct Student s;
	printf("\nEnter name: ");
	fflush(stdin);
	gets(s.name);
	printf("\nEnter mark: ");
	scanf("%f", &s.mark);
	return s;
}

void writeToFileNew(char *filename)
{
	int i, n;
	FILE *fp = fopen(filename, "w");
	if(!fp)
	{
		printf("\nCan't open");
		return;
	}
	printf("\nEnter number of student: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		struct Student s = inputOneStudent();
		fprintf(fp, "%s\t%.1f\n", s.name, s.mark);
	}
	fclose(fp);	
}

/*Question 2: Write a C program to read name and marks of n number of students from user and store them in a file.
If the file previously exits, add the information of n students.*/
void writeToFileAppended(char *filename)
{
	int i, n;
	FILE *fp = fopen(filename, "a");
	if(!fp)
	{
		printf("\nCan't open");
		return;
	}
	printf("\nEnter number of student: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		struct Student s = inputOneStudent();
		fprintf(fp, "%s\t%.1f\n", s.name, s.mark);
	}
	fclose(fp);		
}

/*Question 3: Write a C program to write all the members of an array of structures to a file using fwrite().
Read the array from the file and display on the screen.*/
void inputArrayStudent(struct Student Array[], int *n)
{
	do{
		printf("\nEnter number of student: ");
		scanf("%d", n);
		if(*n < 0 || *n > MAX)
		{
			printf("Number of student 1 ~ MAX");
		}
	}while(*n < 0 || *n > MAX);
	
	int i;
	for(i = 0; i < *n; i++)
	{
		Array[i] = inputOneStudent();
	}
}

void writeArrayToFile(struct Student Array[], int n, char *filename)
{	
	FILE *fp = fopen(filename, "w");
	if(!fp)
	{
		printf("\nCan't open");
		return;
	}
	
	int i;
	for(i = 0; i < n; i++)
	{
		fwrite(&Array[i], sizeof(struct Student), 1, fp);
	}
	fclose(fp);
}

void readFileAndDislay(char *filename)
{
	FILE *fp = fopen(filename, "r");
	if(!fp)
	{
		printf("\nCan't open");
		return;
	}
	struct Student Buf;
	while(fread(&Buf, sizeof(struct Student), 1, fp))
	{
		printf("%s   %.1f\n", Buf.name, Buf.mark);
	}	
	fclose(fp);	
}

/*Question 4: C program to copy contents of one file to another file*/
void copyFile(char *filename1, char *filename2)
{
	//read contents file2 and copy to file1
	FILE *fp2 = fopen(filename2, "r");
	FILE *fp1 = fopen(filename1, "w");
	while(!feof(fp2))
	{
		fputc(fgetc(fp2), fp1);
	}
	fclose(fp2);
	fclose(fp1);
}

/*Question 5: C Program to list all files and sub-directories in a directory*/

/*Question 6: C program to delete a file*/
void deleteFile(char *filename)
{
	remove(filename);
}

/*Question 7: C Program to merge contents of two files into a third file*/
void mergeFile(char *filename1, char *filename2, char *filename3)
{
	FILE *fp1 = fopen(filename1, "r");
	FILE *fp2 = fopen(filename2, "r");
	FILE *fp3 = fopen(filename3, "a");
	while(!feof(fp1))
	{
		fputc(fgetc(fp1), fp3);
	}
	while(!feof(fp2))
	{
		fputc(fgetc(fp2), fp3);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}

/*Question 8: C Program to count number of lines in a file*/
int countNumberLines(char *filename)
{
	int count = 0;
	FILE *fp = fopen(filename, "r");
	if(!fp)
	{
		printf("\nCan not open");
		return 0;
	}
	char c;
	for(c = fgetc(fp); c != EOF; c = fgetc(fp))
	{
		if(c = '\n')
		{
			count++;
		}
	}
	return count;
}
