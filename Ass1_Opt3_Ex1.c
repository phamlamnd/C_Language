#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 10
#define PackageFee 50

//Check the string is an integer number
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

float CalculateDistanceFee(int Distance)
{
	if(Distance < 20)
	{
		return 0;
	}
	else if(Distance >= 20 && Distance < 30)
	{
		return 25;
	}
	else if(Distance >= 30 && Distance < 40)
	{
		return 30;
	}
	else if(Distance >= 40 && Distance < 50)
	{
		return 35;
	}
	else
	{
		return 40;
	}	
}

float CalculateTimeFee(float TotalFee, int Time)
{
	if(Time >= 6 && Time <= 18)
	{
		return TotalFee * 0.1;
	}
	return 0;
}

int main()
{
	int NumberOfPackage, Distance, Time;
	float DistanceFee, TimeFee, TotalFee;
	char buf[MAX];
	printf("===========TRANSPORT FEE==========\n");
	
	do{
		printf("\nEnter number of package: ");
		fflush(stdin);
		gets(buf);
		if(IsInteger(buf) == 0)
		{
			printf("\nInvalid! Please!");
		}
	}while(IsInteger(buf) == 0);
	NumberOfPackage = atoi(buf);
	
	do{
		printf("\nEnter the distance to transport (km): ");
		fflush(stdin);
		gets(buf);
		if(IsInteger(buf) == 0)
		{
			printf("\nInvalid! Please!");
		}
	}while(IsInteger(buf) == 0);
	Distance = atoi(buf);
	DistanceFee = CalculateDistanceFee(Distance);
	TotalFee = NumberOfPackage * PackageFee + NumberOfPackage * DistanceFee;
	
	do{
		printf("\nEnter the time to transport (0h-24h): ");
		fflush(stdin);
		gets(buf);
		if(IsInteger(buf) == 0)
		{
			if(atoi(buf) < 0 || atoi(buf) > 24)
			{
				printf("\nInvalid! Please!");
			}
		}
	}while(IsInteger(buf) == 0 || atoi(buf) < 0 || atoi(buf) > 24);
	Time = atoi(buf);
	TimeFee = CalculateTimeFee(TotalFee, Time);
	
	printf("\nThe customer must pay: $%.2f", TotalFee + TimeFee);
}




















