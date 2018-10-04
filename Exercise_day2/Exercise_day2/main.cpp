#include <iostream>
#include "mylib.h"
using namespace std;

/*Exercise 2: Largest Sum Contiguous Subarray:
Write an efficient program to find the sum of contiguous subarray within a one-dimensional 
array of numbers which has the largest sum.*/
int sumArray(int arr[], int n)
{
	int i;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int largestSum(int arr[], int n)
{
	int i, j, tmp;
	int largest = sumArray(arr, n);
	for (i = 0; i < n; i++)
	{
		tmp = sumArray(arr, i + 1);
		for (j = 0; j <= i; j++)
		{
			if (j > 0)
			{
				tmp -= arr[j - 1];
			}
			if (tmp > largest)
			{
				largest = tmp;
			}
		}
	}
	return largest;
}

/*Exercise 3: Find the Missing Number
You are given a list of n-1 integers and these integers are in the range of 1 to n.
There are no duplicates in list. One of the integers is missing in the list. 
Write an efficient code to find the missing integer.*/
int findMissingNumber(int arr[], int n)
{
	int i;
	int sum = (n + 1)*(n + 2) / 2;
	for (i = 0; i < n; i++)
	{
		sum -= arr[i];
	}
	return sum;
}

/*Exercise 4: Write a program to reverse an array or string (Iterative and recursive)*/
void reverseArray(int a[], int n)
{
	int i;
	for (i = 0; i < n/2; i++)
	{
		SWAP(a[i], a[n - i - 1]);
	}
}

void recursiveArray(int a[], int n, int i)
{
	if (i == n/2) return;
	SWAP(a[i], a[n - i - 1]);
	recursiveArray(a, n, i + 1);
}

/*Exercise 5: Program for array rotation:
Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements
Input: arr[] = { 1, 2, 3, 4, 5, 6, 7},  d = 2, n = 7
Output: Rotate the array by 2 { 3, 4, 5, 6, 7, 1, 2 }*/
void rotateArray(int a[], int n, int d)
{
	int i, j, tmp;
	for (i = 0; i < d; i++)
	{
		tmp = a[0];
		for (j = 0; j < n - 1; j++)
		{
			a[j] = a[j + 1];
		}
		a[n - 1] = tmp;
	}
}

/*Exercise 6: Reversal algorithm for array rotation:
Write a function reverseRotate(arr[], d, n) that reverse the rotation of arr[] of size n by d elements.
Input :  arr[] = { 1, 2, 3, 4, 5, 6, 7 ], d = 2, n = 7
Output : arr[] = { 3, 4, 5, 6, 7, 1, 2 }*/
void reverseRotate(int arr[], int d, int n)
{

}

/*Exercise 7: Union and Intersection of two sorted arrays
Given two sorted arrays, find their union and intersection.
Input : arr1[] = {1, 3, 4, 5, 7}
arr2[] = {2, 3, 5, 6}
Output : Union : {1, 2, 3, 4, 5, 6, 7}
Intersection : {3, 5}

Input : arr1[] = {2, 5, 6}
arr2[] = {4, 6, 8, 10}
Output : Union : {2, 4, 5, 6, 8, 10}
Intersection : {6}*/
void unionArray(int a[], int b[], int c[], int m, int n, int &k)
{
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (a[i] < b[j])
		{
			c[k] = a[i];
			i++;
			k++;
		}
		else if (a[i] > b[j])
		{
			c[k] = b[j];
			j++;
			k++;
		}
		else //a[i] == b[j]
		{
			c[k] = a[i];
			i++;
			j++;
			k++;
		}
	}
	while (i < m)
	{
		c[k] = a[i];
		i++;
		k++;
	}
	while (j < n)
	{
		c[k] = b[j];
		j++;
		k++;
	}
}


void intersectionArray(int a[], int b[], int c[], int m, int n, int &k)
{
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (a[i] < b[j])
		{
			i++;
		}
		else if (a[i] > b[j])
		{
			j++;
		}
		else //a[i] == b[j]
		{
			c[k] = a[i];
			i++;
			j++;
			k++;
		}
	}
}


/*Exercise 8: Program for array addition:
Write a function to add 2 square matrices of size N*N*/
void addArray(int a[][MAX], int b[][MAX], int c[][MAX], int n)
{
	int i;
	for (i = 0; i < n*n; i++)
	{
		c[i/n][i%n] = a[i/n][i%n] + b[i/n][i%n];
	}
}

/*Exercise 9: Program for array substraction:
Write a function to find the difference 2 square matrices of size N*N*/
void substractionArray(int a[][MAX], int b[][MAX], int c[][MAX], int n)
{
	int i;
	for (i = 0; i < n*n; i++)
	{
		c[i/n][i%n] = a[i/n][i%n] - a[i/n][i%n];
	}
}


int main()
{
	//dosomething();
	//fun();
	//inlineFunction();
	void(*fun)(void) = inlineFunction;
	(*fun)();
	system("pause");
	return 0;
}