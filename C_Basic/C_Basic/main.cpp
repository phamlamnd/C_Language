#include<iostream>
using namespace std;

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
//Parameter: 
void multiplyMatric(int **a, int **b, int **c, int row1, int rc, int col2)
{
	int i;
	int j;
	int k;
	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < col2; j++)
		{
			c[i][j] = 0;
			for (k = 0; k < rc; k++)
			{
				c[i][j] += a[i][k] + b[k][j];
			}
			cout << c[i][j] << "  ";
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
			if (a[j] > x) continue;
			if (x == (a[i] + a[j]))
			{
				cout << "{" << a[i] << " " << a[j] << "}" << endl;
			}
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
					cout << a[i] << endl;
					return;
				}
			}
		}
	}
	cout << "\nNo majority element";
}

int main()
{
	//int a[2][2] = { { 2, 4 },{ 3, 4 } };
	//int b[2][2] = { { 1, 2 },{ 1, 3 } };
	int c[2][2];
	int **a, **b;
	multiplyMatric(a, b, c, 2, 2, 2);
	system("pause");
}