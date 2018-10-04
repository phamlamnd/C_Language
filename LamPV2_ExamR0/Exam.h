#ifndef _EXAM_H_
#define _EXAM_H_
#define MAX 100
#include <stdio.h>

/*Declare struct one Trainee*/
struct Trainee
{
	char Name[30];
	float Math;
	float Lite;
	float Eng;
	float His;
	float Phy;
};

/*Declare struct one Node in Linked List*/
struct Node
{
	struct Trainee Person;
	struct Node *next;
};

/*Write data to file*/
void writeToFile(FILE *fp, char *filename, char name[], float math, float lite, float eng, float his, float phy);
/*Create data file*/
void createDataFile(FILE *fp, char *filename);

/*standard String*/
char* standardString(char[]);
/*Load data to array of pointer*/
void loadContentData(FILE *fp, char *filename, struct Trainee* traineeList[], int *n);
/*Select menu*/
char selectMenu();
/*Display mark table from array of pointer*/
void displayMarkTable(struct Trainee *traineeList[], int n);
/*Display mark table from file*/
void displayFromFile(FILE *fp, char *filename);
/*Get average mark one trainee*/
float getAverageMark(struct Trainee *person);

/*Selection sort*/
void selectionSort(struct Trainee *traineeList[], int n);
/*Bubble sort*/
void bubbleSort(struct Trainee *traineeList[], int n);
/*Insertion sort*/
void insertionSort(struct Trainee *traineeList[], int n);
/*Merge Sort*/
void mergeSort(struct Trainee *traineeList[], struct Trainee *Buf[], int left, int right);
/*Quick sort*/
void quickSort(struct Trainee *traineeList[], int left, int right);
/*Heap sort*/
void heapSort(struct Trainee *traineeList[], int n);

/*Display top 5 average mark*/
void displayTop5AverageMark(struct Trainee *traineeList[], int n, int top);
/*Free memory*/
void freeArray(struct Trainee *traineeList[], int n);
/*Remove file*/
void removeFile(char *filename);

/*Use linked list*/
void init(struct Node **head);
/*Load data from file and insert to linked list*/
void loadToLinkedList(FILE *fp, char *filename, struct Node **head);
/*Print linked list*/
void printLinkedList(struct Node **head);
/*Free linked list*/
void freeLinkedList(struct Node **head);

#endif /*end of file*/
