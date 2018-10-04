#include<stdio.h>
#include<conio.h>
#include<string.h>

int IsInteger(char *s)
{
	int i;
	int len = strlen(s);
	for(i = 0; i < len; i++)
	{
		if(s[i] < '0' || s[i] > '9')
		{
			return 0;
		}
	}
	return 1;
}

//Check leap year function
//Input: integer
//Return 1 if leap year
//Return 0 if not
int IsLeapYear(int year)
{
	if((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
	{
		return 1;
	}
	return 0;
}

int main()
{
	int year1, year2;	
	int i, check;
	char buf[50];
	do{
		printf("\nEnter start year: ");
		fflush(stdin);
		gets(buf);
		year1 = atoi(buf);
		check = 0;
		if( year1 < 1900 || year1 > 2900)
		{
			check = 1;
			printf("\nInvalid. Please re-enter");
		}
	}while(check == 1);
	
	do{
		printf("\nEnter finish year: ");
		fflush(stdin);
		gets(buf);
		year2 = atoi(buf);
		check = 0;
		if( year2 < year1 || year2 > 2900)
		{
			check = 1;
			printf("\nInvalid. Please re-enter");
		}
	}while(check == 1);
	
	printf("\nPrint all leap year from %d to %d: ", year1, year2);
	for(i = year1; i < year2; i++)
	{
		if(IsLeapYear(i))
		{
			printf("%d\n", i);
		}
	}
}
