#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Exam.h"

int main()
{
	//Question 1
	FILE *fp;
	createDataFile(fp);	
	
	//Question 2
	struct Trainee* traneeList[100];
	int n = 0;		//number of Trainee
	loadContentData(fp, traneeList, &n);
	
	while(1)
	{
		char select = selectMenu();
		switch(select)
		{
			case '1':
				displayMarkTable(traneeList, n);		//Display mark table
				getch();
				break;
			case '2':
				displayTop5AverageMark(traneeList, n);	//Display top 5
				getch();
				break;
			case 'q':
			case 'Q':
				printf("\nQuit");
				goto finish;
		}
	}
	finish:
	freeArray(traneeList,n);
	getch();
	return 0;
}
