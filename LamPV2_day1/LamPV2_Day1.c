#include<conio.h>
#include<stdio.h>

//Exercise 1
//Write a program to find sum of elements in a given array
int sumElement(int a[], int n)
{
	int sum = 0, i;
	for (i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}

//Exercise 2
//Write a program to find largest element in an array
int findLargestElement(int a[], int n)
{
	int i;
	int largest = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] > largest)
		{
			largest = a[i];
		}
	}
	return largest;
}

//Exercise 3
//Write a Recursive program to linearly search an element in a given array: 
//Given an unsorted array and an element x, search x in given array.
//Write recursive C code for this.If element is not present, return -1.
int linearSearch(int a[], int n, int x)
{
	if (a[n - 1] == x)
	{
		return n - 1;
	}
	if (n - 2 >= 0)
	{
		return linearSearch(a, n - 1, x);
	}
	return -1;
}

//Exercise 4
//Write a Program to multiply two matrices
void multiplyMatric(int a[][2], int b[][2], int c[][2], int row1, int rc, int col2)
{
	int i, j, k, tmp;
	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < col2; j++)
		{
			tmp = 0;
			for (k = 0; k < rc; k++)
			{
				tmp += a[i][k] * b[k][j];
			}
			c[i][j] = tmp;
		}
	}
}

//Exercise 5
//Write a Program that Given an array A[] and a number x, check for pair in A[] with sum as x
void pairNumber(int a[], int n, int x)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		if (a[i] > x) continue;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] != (x - a[i])) continue;
			printf(" {%d %d}", a[i], a[j]);
		}
	}
}

//Exercise 6
//Write a function which takes an array and prints the majority element (if it exists), otherwise prints “No Majority Element”. 
void majorityElement(int a[], int n)
{
	int i, j, count;
	for (i = 0; i < n / 2; i++)
	{
		count = 1;
		for(j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				count++;
				if (count > n / 2)
				{
					printf("%d", a[i]);
					return;
				}
			}
		}
	}
	printf("No majority element");
}

int main()
{
	//Exercise 1
	int arr[] = {12, 34, 54, 2, 3};
	int n = 5;
	int sum = sumElement(arr, n);
	printf("\nSum = %d", sum);
	
	//Exercise 2
	int largest = findLargestElement(arr, n);
	printf("\nLargest = %d", largest);
	
	//Exercise 3
	int x = 2;
	int position = linearSearch(arr, n, x);
	printf("\nPosition of x: %d", position);
	
	//Exercise 4
	int i, j;
	int mat1[2][2] = { { 2, 4 },{ 3, 4 } };
	int mat2[2][2] = { { 1, 2 },{ 1, 3 } };
	int mat3[2][2];
	multiplyMatric(mat1, mat2, mat3, 2, 2, 2);
	printf("\nMultiply matric:\n");
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("%d ", mat3[i][j]);
		}
		printf("\n");
	}
	
	//Exercise 5
	int x1 = 16;
	int arr1[] = {1, 4, 45, 6, 10, -8};
	printf("\nPair number:");
	pairNumber(arr1, 6, x1);
	
	//Exercise 6
	int arr2[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
	n = 9;
	printf("\nMajority element: ");
	majorityElement(arr2, n);
	
	getch();
}
