#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "Exam.h"

int main()
{
	//Question 1
	FILE *fp;
	char filename[20] = "LamPV2.txt";
	createDataFile(fp, filename);
	
	//Question 2
	struct Trainee* traineeList[MAX];
	struct Node *head;
	int n;		//number of Trainee
	
	//load content file to array of pointer
	loadContentData(fp, filename, traineeList, &n);			
	
	//load to linked list
	init(&head);
	loadToLinkedList(fp, filename, &head);
	
	while(1)
	{
		char select = selectMenu();
		switch(select)
		{	
			case '1':
				displayMarkTable(traineeList, n);			//Option 1: display from array struct pointer
				//displayFromFile(fp, filename);			//Option 2: display from file
				//printLinkedList(&head);					//Option 2: display from linked list
				getch();
				break;
			case '2':
				displayTop5AverageMark(traineeList, n, 10);	//top 5 from array struct pointer
				getch();
				break;
			case 'q':
			case 'Q':
				printf("Quit program");
				goto finish;
		}
	}
	
	finish:
	freeArray(traineeList, n);	
	//removeFile(filename);
	return 0;
}
