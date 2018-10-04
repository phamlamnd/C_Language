#include "Exam.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Question 1*/
void writeToFile(FILE *fp, char name[], float math, float lite, float eng, float his, float phy)
{
	fp = fopen("EXAM.txt", "a+");
	if (!fp)
	{
		printf("\nCan not open");
	}
	fprintf(fp, "\n%s\t\t|%.1f\t|%.1f\t|%.1f\t|%.1f\t|%.1f", name, math, lite, eng, his, phy);
	fclose(fp);
}

void createDataFile(FILE *fp)
{
	fp = fopen("EXAM.txt", "w+");
	if (!fp)
	{
		printf("\nCan not open");
	}
	fprintf(fp, "%s\t\t\t|%s\t|%s\t|%s\t|%s\t|%s", "Name", "Math", "Lite", "Eng", "His", "Phy");
	fclose(fp);
	writeToFile(fp, "Nguyen Van A", 8, 6.5, 7.5, 7.0, 4.3);
	writeToFile(fp, "Nguyen Van B", 9, 6.5, 0.5, 0.0, 3.3);
	writeToFile(fp, "Nguyen Van C", 8, 6.5, 7.5, 7.0, 3.3);
	writeToFile(fp, "Nguyen Van D", 4, 6.5, 8.5, 7.0, 3.3);
	writeToFile(fp, "Nguyen Van E", 8, 6.5, 7.5, 7.0, 5.3);
	writeToFile(fp, "Nguyen Van F", 5, 6.5, 7.5, 5.0, 3.3);
	writeToFile(fp, "Nguyen Van G", 8, 6.5, 7.5, 7.0, 3.3);
	writeToFile(fp, "Nguyen Van H", 3, 6.5, 5.5, 6.0, 7.3);
	writeToFile(fp, "Nguyen Van I", 4, 6.5, 7.5, 7.0, 3.3);
	writeToFile(fp, "Nguyen Van J", 8, 6.5, 3.5, 7.0, 9.3);
	writeToFile(fp, "Nguyen Van K", 8, 6.5, 7.5, 7.0, 3.3);
	writeToFile(fp, "Nguyen Van L", 2, 6.5, 7.5, 7.0, 9.3);
	writeToFile(fp, "Nguyen Van M", 1, 6.5, 7.5, 7.0, 3.3);
	writeToFile(fp, "Nguyen Van N", 3, 6.5, 7.5, 7.0, 5.3);
	writeToFile(fp, "Nguyen Van O", 8, 6.5, 7.5, 8.0, 9.3);	
}

/*Question 2*/
void loadContentData(FILE *fp, struct Trainee* traneeList[], int *n)
{
	fp = fopen("EXAM.txt", "r");
	if (!fp)
	{
		printf("\nCan not open");
		return;
	}

	char name[30];
	float math;
	float lite;
	float eng;
	float his;
	float phy;

	while(!feof(fp))
	{
		while(fgetc(fp) != '\n');
		
		char c;
		int i = 0;
		while((c = fgetc(fp))!= '|')
		{
			name[i] = c;
			i++;
		}
		name[i] = '\0';
		
		fscanf(fp,"%f",&math);
		
		while(fgetc(fp) != '|');
		fscanf(fp,"%f",&lite);
		
		while(fgetc(fp) != '|');
		fscanf(fp,"%f",&eng);
		
		while(fgetc(fp) != '|');
		fscanf(fp,"%f",&his);
		
		while(fgetc(fp) != '|');
		fscanf(fp,"%f",&phy);
		
		traneeList[*n] = (struct Trainee*)malloc(sizeof(struct Trainee));
		strcpy((traneeList[*n])->Name, name);
		traneeList[*n]->Math = math;
		traneeList[*n]->Lite = lite;
		traneeList[*n]->Eng  = eng;
		traneeList[*n]->His  = his;
		traneeList[*n]->Phy  = phy;
		(*n)++;
	}
	fclose(fp);
}

char selectMenu()
{
	char select;
	printf("\nWelcome to Mark Calculator utility");
	printf("\n\tPress 1 to display mark table");
	printf("\n\tPress 2 to display top 5 average mark");
	printf("\n\tPress 'q' or 'Q' to quit program");
	do
	{
		printf("\nEnter your choise: ");
		fflush(stdin);
		select = getchar();
		if(select != '1' && select != '2' && select != 'q' && select != 'Q')
		{
			printf("\nPlease choise '1', '2', 'q' or 'Q'");
		}
	}
	while(select != '1' && select != '2' && select != 'q' && select != 'Q');
	return select;
}

void displayMarkTable(struct Trainee* traneeList[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%s|%.1f\t|%.1f\t|%.1f\t|%.1f\t|%.1f\n", traneeList[i]->Name,traneeList[i]->Math, 
		traneeList[i]->Lite, traneeList[i]->Eng, traneeList[i]->His, traneeList[i]->Phy);
	}
}

void AvgCal(struct Trainee* traneeList[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		traneeList[i]->Avg = (traneeList[i]->Math + traneeList[i]->Lite + traneeList[i]->His + traneeList[i]->Phy + traneeList[i]->Eng)/5;
	}
}

void displayTop5AverageMark(struct Trainee* traneeList[], int n)
{
	struct Trainee *Buf[100];
	int i, j;
	AvgCal(traneeList, n);
	for(i = 0; i < n; i++)
	{
		Buf[i] = traneeList[i];
	}
	
	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(Buf[i]->Avg < Buf[j]->Avg)
			{
				struct Trainee *tmp = Buf[i];
				Buf[i] = Buf[j];
				Buf[j] = tmp;
			}
		}
	}
	
	for(i = 0; i < 5; i++)
	{
		printf("%s|%.1f\t|%.1f\t|%.1f\t|%.1f\t|%.1f\t|%.1f\n", Buf[i]->Name,Buf[i]->Math, 
		Buf[i]->Lite, Buf[i]->Eng, Buf[i]->His, Buf[i]->Phy, Buf[i]->Avg);
	}
}

void freeArray(struct Trainee* traneeList[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		free(traneeList[i]);
	}
}
