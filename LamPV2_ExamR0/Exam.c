#include "Exam.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Question 1*/
/*Write data to file*/
void writeToFile(FILE *fp, char *filename, char name[], float math, float lite, float eng, float his, float phy)
{
	fp = fopen(filename, "a+");
	if (!fp)
	{
		printf("\nCan not open file");
	}
	fprintf(fp, "\n%s\t|%.1f\t|%.1f\t|%.1f\t|%.1f\t|%.1f", name, math, lite, eng, his, phy);
	fclose(fp);
}

/*Create data file*/
void createDataFile(FILE *fp, char *filename)
{
	fp = fopen(filename, "w+");
	if (!fp)
	{
		printf("\nCan not open file");
		return;
	}
	fprintf(fp, "%s\t\t|%s\t|%s\t|%s\t|%s\t|%s", "Name", "Math", "Lite", "Eng", "His", "Phy");
	fclose(fp);
	writeToFile(fp, filename, "Nguyen Van A", 8, 6.5, 7.5, 7.0, 4.3);
	writeToFile(fp, filename, "Nguyen Van B", 9, 6.5, 8.5, 7.0, 3.3);
	writeToFile(fp, filename, "Nguyen Van C", 8, 6.5, 7.5, 7.0, 3.3);
	writeToFile(fp, filename, "Nguyen Van D", 4, 6.5, 8.5, 7.0, 3.3);
	writeToFile(fp, filename, "Nguyen Van E", 8, 6.5, 7.5, 7.0, 5.3);
	writeToFile(fp, filename, "Nguyen Van F", 5, 6.5, 7.5, 5.0, 3.3);
	writeToFile(fp, filename, "Nguyen Van G", 8, 6.5, 7.5, 7.0, 3.3);
	writeToFile(fp, filename, "Nguyen Van H", 3, 6.5, 5.5, 6.0, 7.3);
	writeToFile(fp, filename, "Nguyen Van I", 4, 6.5, 7.5, 7.0, 3.3);
	writeToFile(fp, filename, "Nguyen Van J", 8, 6.5, 3.5, 7.0, 9.3);
	writeToFile(fp, filename, "Nguyen Van K", 8, 6.5, 7.5, 7.0, 3.3);
	writeToFile(fp, filename, "Nguyen Van L", 2, 6.5, 7.5, 7.0, 9.3);
	writeToFile(fp, filename, "Nguyen Van M", 1, 6.5, 7.5, 7.0, 3.3);
	writeToFile(fp, filename, "Nguyen Van N", 3, 6.5, 7.5, 7.0, 5.3);
	writeToFile(fp, filename, "Nguyen Van O", 8, 6.5, 7.5, 8.0, 9.3);
	
	printf("-->Create file '%s' success", filename);
}

/*standard String*/
char* standardString(char s[])
{
	int len = strlen(s);
	int i;
	int j;
	/*Delete space from left*/
	while((s[0] == ' ' || s[0] == '\n') && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			s[i] = s[i+1];
		}
		len--;
	}
	/*Delete space from right*/
	while((s[len-1] == ' ' || s[len-1] == '\n')  && len > 0)
	{
		s[len-1] = '\0';
		len--;
	}
	return s;
}

/*Question 2*/
/*Read data to array of pointer*/
void loadContentData(FILE *fp, char *filename, struct Trainee* traineeList[], int *n)
{
	//init number of trainee
	*n = 0; 
	fp = fopen(filename, "r");
	if (!fp)
	{
		printf("\nCan not open file");
		return;
	}
	
	char name[30];
	float math;
	float lite;
	float eng;
	float his;
	float phy;
	
	//read first line and ignore
	while(fgetc(fp)!= '\n');

	while(!feof(fp))
	{
		int i = 0;
		char c;
		while((c = fgetc(fp)) != '|')
		{
			name[i] = c;
			i++;
		}
		name[i] = '\0';		//add finish string
		fscanf(fp,"%f",&math);
		
		while(fgetc(fp) != '|');
		fscanf(fp,"%f",&lite);
		
		while(fgetc(fp) != '|');
		fscanf(fp,"%f",&eng);
		
		while(fgetc(fp) != '|');
		fscanf(fp,"%f",&his);
		
		while(fgetc(fp) != '|');
		fscanf(fp,"%f",&phy);
		//fgetc(fp);	//read '\n' chracter if not standard string
		
		traineeList[*n] = (struct Trainee*)malloc(sizeof(struct Trainee));
		strcpy(traineeList[*n]->Name, standardString(name));
		traineeList[*n]->Math = math;
		traineeList[*n]->Lite = lite;
		traineeList[*n]->Eng  = eng;
		traineeList[*n]->His  = his;
		traineeList[*n]->Phy  = phy;
		(*n)++;
	}
	fclose(fp);
}

/*Select menu*/
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

/*Display mark table from array of pointer*/
void displayMarkTable(struct Trainee *traineeList[], int n)
{
	int i;
	printf("%s\t\t|%s\t|%s\t|%s\t|%s\t|%s", "Name", "Math", "Lite", "Eng", "His", "Phy");
	for(i = 0; i < n; i++)
	{
		char name[30];
		strcpy(name, traineeList[i]->Name);
		float math = traineeList[i]->Math;
		float lite = traineeList[i]->Lite;
		float eng = traineeList[i]->Eng;
		float his = traineeList[i]->His;
		float phy = traineeList[i]->Phy;
		printf("\n%s|%.1f\t|%.1f\t|%.1f\t|%.1f\t|%.1f", name, math, lite, eng, his, phy);	
	}
}

/*Display mark table from file*/
void displayFromFile(FILE *fp, char *filename)
{
	fp = fopen(filename, "r");
	if (!fp)
	{
		printf("\nCan not open file");
		return;
	}
	while(!feof(fp))
	{
		putchar(fgetc(fp));
	}
	fclose(fp);	
}

/*Get average mark one trainee*/
float getAverageMark(struct Trainee *person)
{
	return (person->Math + person->Lite + person->Eng + person->His + person->Phy)/5;
}

/*Selection sort*/
void selectionSort(struct Trainee *traineeList[], int n)
{
	int i, j;
	for(i = 0; i < n- 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(getAverageMark(traineeList[i]) < getAverageMark(traineeList[j]))
			{
				struct Trainee *tmp = traineeList[i];
				traineeList[i] = traineeList[j];
				traineeList[j] = tmp;
			}
		}
	}
}

/*Bubble sort*/
void bubbleSort(struct Trainee *traineeList[], int n)
{
	int i, j;
	for(i = 0; i < n - 1; i++)
	{
		for(j = n - 1; j > i; j--)
		{
			if(getAverageMark(traineeList[j]) > getAverageMark(traineeList[j - 1]))
			{
				struct Trainee *tmp = traineeList[j];
				traineeList[j] = traineeList[j - 1];
				traineeList[j - 1] = tmp;
			}
		}
	}
}

/*Insertion sort*/
void insertionSort(struct Trainee* traineeList[], int n)
{
	int i, j;
	for(i = 1; i < n; i++)
	{
		j = i - 1;
		struct Trainee *tmp = traineeList[i];
		float averge = getAverageMark(traineeList[i]);
		while(j >= 0 && averge > getAverageMark(traineeList[j]))
		{
			traineeList[j + 1] = traineeList[j];
			j--;
		}
		traineeList[j + 1] = tmp;
	}
}

/*Merge Sort*/
void merging(struct Trainee *traineeList[], struct Trainee *Buf[], int left, int mid, int right)
{
	int l1 = left;
	int l2 = mid + 1;
	int i = left;
	while(l1 <= mid && l2 <= right)
	{
		if(getAverageMark(traineeList[l1]) > getAverageMark(traineeList[l2]))
		{
			Buf[i] = traineeList[l1];
			i++;
			l1++;
		}
		else
		{
			Buf[i] = traineeList[l2];
			i++;
			l2++;
		}
	}
	while(l1 <= mid)
	{
		Buf[i] = traineeList[l1];
		i++;
		l1++;
	}
	while(l2 <= right)
	{
		Buf[i] = traineeList[l2];
		i++;
		l2++;
	}
	for(i = left; i <= right; i++)
	{
		traineeList[i] = Buf[i];
	}
}

void mergeSort(struct Trainee *traineeList[], struct Trainee *Buf[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(traineeList, Buf, left, mid);
		mergeSort(traineeList, Buf, mid + 1, right);
		merging(traineeList, Buf, left, mid, right);
	}
}

/*Quick sort*/
int partition(struct Trainee *traineeList[], int left, int right)
{
	struct Trainee *pivot = traineeList[right];
	struct Trainee *tmp;
	int i = left - 1;
	int j;
	for(j = left; j <= right - 1; j++)
	{
		if(getAverageMark(traineeList[j]) > getAverageMark(pivot))
		{
			i++;
			tmp = traineeList[i];
			traineeList[i] = traineeList[j];
			traineeList[j] = tmp;
		}
	}
	tmp = traineeList[i + 1];
	traineeList[i + 1] = traineeList[right];
	traineeList[right] = tmp;
	return i + 1;
}

void quickSort(struct Trainee *traineeList[], int left, int right)
{
	if(left < right)
	{
		int pi = partition(traineeList, left, right);
		quickSort(traineeList, left, pi-1);
		quickSort(traineeList, pi+1, right);
	}
}

/*Heap sort*/
void heapify(struct Trainee *traineeList[], int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	if(l < n && getAverageMark(traineeList[l]) < getAverageMark(traineeList[largest]))
	{
		largest = l;
	}
	
	if(r < n && getAverageMark(traineeList[r]) < getAverageMark(traineeList[largest]))
	{
		largest = r;
	}
	
	if(largest != i)
	{
		struct Trainee *tmp = traineeList[i];
		traineeList[i] = traineeList[largest];
		traineeList[largest] = tmp;
		heapify(traineeList, n, largest);
	}
}

void heapSort(struct Trainee *traineeList[], int n)
{
	int i;
	for(i = n / 2 - 1; i >= 0; i--)
	{
		heapify(traineeList, n, i);
	}
	for(i = n - 1; i >= 0; i--)
	{
		struct Trainee *tmp = traineeList[0];
		traineeList[0] = traineeList[i];
		traineeList[i] = tmp;
		heapify(traineeList, i, 0);
	}
}

/*Display top 5 average mark*/
void displayTop5AverageMark(struct Trainee *traineeList[], int n, int top)
{
	int i;
	top = top < n ? top : n;
	//selectionSort(traineeList, n);
	//bubbleSort(traineeList, n);
	//insertionSort(traineeList, n);
	//struct Trainee *Buf[MAX];
	//mergeSort(traineeList, Buf, 0, n-1);
	//heapSort(traineeList, n);
	quickSort(traineeList, 0, n-1);
	printf("%s\t\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s", "Name", "Math", "Lite", "Eng", "His", "Phy", "Average");
	for(i = 0; i < top; i++)
	{
		char name[30];
		strcpy(name, traineeList[i]->Name);
		float math = traineeList[i]->Math;
		float lite = traineeList[i]->Lite;
		float eng = traineeList[i]->Eng;
		float his = traineeList[i]->His;
		float phy = traineeList[i]->Phy;
		printf("\n%s|%.1f\t|%.1f\t|%.1f\t|%.1f\t|%.1f\t|%.1f", name, math, lite, eng, his, phy, getAverageMark(traineeList[i]));
	}
}

/*Free memory*/
void freeArray(struct Trainee *traineeList[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		free(traineeList[i]);
	}
}

/*Remove file*/
void removeFile(char *filename)
{
	remove(filename);
}

/*init linked list*/
void init(struct Node **head)
{
	*head = NULL;	
}

/*Load data from file and insert to linked list*/
void loadToLinkedList(FILE *fp, char *filename, struct Node **head)
{
	fp = fopen(filename, "r");
	if (!fp)
	{
		printf("\nCan not open file");
		return;
	}
	
	char name[30];
	float math;
	float lite;
	float eng;
	float his;
	float phy;
	
	//read first line and ignore
	while(fgetc(fp)!= '\n');

	while(!feof(fp))
	{
		int i = 0;
		char c;
		while((c = fgetc(fp)) != '|')
		{
			name[i] = c;
			i++;
		}
		name[i] = '\0';		//add finish string
		fscanf(fp,"%f",&math);
		
		while(fgetc(fp) != '|');
		fscanf(fp,"%f",&lite);
		
		while(fgetc(fp) != '|');
		fscanf(fp,"%f",&eng);
		
		while(fgetc(fp) != '|');
		fscanf(fp,"%f",&his);
		
		while(fgetc(fp) != '|');
		fscanf(fp,"%f",&phy);
		//fgetc(fp);	//read '\n' chracter if not standard string
		
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));
		strcpy(p->Person.Name, standardString(name));
		p->Person.Math = math;
		p->Person.Lite = lite;
		p->Person.Eng = eng;
		p->Person.His = his;
		p->Person.Phy = phy;
		p->next = *head;	//insert head
		*head = p;
	}
	fclose(fp);
}

/*Print linked list*/
void printLinkedList(struct Node **head)
{
	if(*head == NULL)
	{
		return;
	}
	struct Node *p;
	printf("%s\t\t|%s\t|%s\t|%s\t|%s\t|%s", "Name", "Math", "Lite", "Eng", "His", "Phy");
	for(p = *head; p != NULL; p = p->next)
	{
		char name[30];
		strcpy(name, p->Person.Name);
		float math = p->Person.Math;
		float lite = p->Person.Lite;
		float eng = p->Person.Eng;
		float his = p->Person.His;
		float phy = p->Person.Phy;
		printf("\n%s|%.1f\t|%.1f\t|%.1f\t|%.1f\t|%.1f", name, math, lite, eng, his, phy);	
	}		
}

/*Free linked list*/
void freeLinkedList(struct Node **head)
{
	struct Node *p = *head;
	struct Node *tmp;
	while(p != NULL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	*head = NULL;
}
