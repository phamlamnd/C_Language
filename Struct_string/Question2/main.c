#include <stdio.h>
#include <conio.h>
#define MAX 100

void input(int arr[][MAX], int m, int n)
{
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("\nNhap arr[%d][%d] = ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
}

void output(int arr[][MAX], int m, int n)
{
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}	
}

int searchMin(int arr[][MAX], int m, int n)
{
	int min = arr[0][0];
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(arr[i][j] < min)
			{
				min = arr[i][j];
			}
		}
	}
	return min;
}

int searchMax(int arr[][MAX], int m, int n)
{
	int max = arr[0][0];
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}
	return max;
}


int main()
{
	int arr[MAX][MAX];
	int m, n;
	do{
		printf("\nNhap so dong: ");
		scanf("%d", &m);
		if(m < 0 || m > MAX)
		{
			printf("\nSo dong phai tu 0 den MAX");
		}
	}while(m < 0 || m > MAX);
	
	do{
		printf("\nNhap so cot: ");
		scanf("%d", &n);
		if(n < 0 || n > MAX)
		{
			printf("\nSo cot phai tu 0 den MAX");
		}
	}while(n < 0 || n > MAX);
	
	input(arr, m, n);
	output(arr, m, n);
	
	int min = searchMin(arr, m, n);
	int max = searchMax(arr, m, n);
	printf("\nMin = %d", min);
	printf("\nMax = %d", max);
	
	return 0;
}
