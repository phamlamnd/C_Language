#include "mylib.h"
#include <iostream>
using namespace std;

static void fun()
{
	cout << "I'm static function";
}

void dosomething()
{
	fun();
}

void inlineFunction(void)
{
	cout << "I'm inline function";
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

extern void merge(int a[], int b[], int left, int mid, int right)
{
	int l1 = left;
	int l2 = mid + 1;
	int i = left;
	while (l1 <= mid && l2 <= right)
	{
		if (a[l1] < a[l2])
		{
			b[i] = a[l1];
			i++;
			l1++;
		}
		else
		{
			b[i] = a[l2];
			i++;
			l2++;
		}
	}
	while (l1 <= mid)
	{
		b[i] = a[l1];
		i++;
		l1++;
	}
	while (l2 <= right)
	{
		b[i] = a[l2];
		i++;
		l2++;
	}
	for (i = left; i <= right; i++)
	{
		a[i] = b[i];
	}
}

void mergeSort(int a[], int b[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(a, b, left, mid);
		mergeSort(a, b, mid + 1, right);
		merge(a, b, left, mid, right);
	}
}

int partition(int a[], int left, int right)
{
	int pivot = a[right];
	int i = left;
	int j = right - 1;
	while (i <= j)
	{
		while (a[i] <= pivot && i <= j) { i++; }
		while (a[j] > pivot && i <= j) { j++; }
		if (i < j) SWAP(a[i], a[j]);
	}
	SWAP(a[i], a[right]);
	printArray(a, 7);
	cout << endl;
	cout << pivot << endl;
	return i;
}

void quickSort(int a[], int left, int right)
{
	if (left < right)
	{
		int pi = partition(a, left, right);
		quickSort(a, left, pi - 1);
		quickSort(a, pi + 1, right);
	}
}