#include<stdio.h>
#include<conio.h>

int Sum(int N)
{
	int i, sum = 0;
	for(i = 1; i <= N; i++)
	{
		sum += i;
	}
	return sum;
}

int main()
{
	int N, Total;
	do{
		printf("\nEnter N(10~30): ");
		scanf("%d",&N);
		if(N < 20 || N > 30)
		{
			printf("\nInvalid");
		}
	}while(N < 20 || N > 30);
	Total = Sum(N);
	printf("\nTotal = %d", Total);
}
