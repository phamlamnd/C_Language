#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <ctime>       /* time */
using namespace std;

void output(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << "\n";
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

void selection_sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

void insertion_sort(int a[], int n)
{
	int value;
	int hole;
	int j;
	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		value = a[i];
		hole = i;
		while (j >= 0 && a[j] > value)
		{
			a[j + 1] = a[j];
			hole = j;
			j--;
		}
		a[hole] = value;
	}
}

void merge(int a[], int b[], int left, int mid, int right)
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

void merge_sort(int a[], int b[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(a, b, left, mid);
		merge_sort(a, b, mid + 1, right);
		merge(a, b, left, mid, right);
	}
}

int partition1(int a[], int left, int right)
{
	int pivot = a[right];
	int i = left - 1;
	int j = right;
	while (i <= j)
	{
		while (a[++i] < pivot && i <= j);
		while (a[--j] >= pivot && i <= j);
		if (i < j) swap(&a[i], &a[j]);
	}
	swap(&a[i], &a[right]);
	return i;
}

int partition2(int a[], int left, int right)
{
	int pivot = a[left];
	int i = left;
	int j = right + 1;
	while (i < j)
	{
		while (a[++i] <= pivot && i < j) {}
		while (a[--j] > pivot && i < j) {}
		if (i < j) { swap(a[i], a[j]); }
	}
	swap(a[i - 1], a[left]);
	return i - 1;
}


void quick_sort(int a[], int left, int right)
{
	if (left < right)
	{
		int pi = partition2(a, left, right);
		quick_sort(a, left, pi - 1);
		quick_sort(a, pi + 1, right);
	}
}

//n size of heap
void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[largest])
	{
		largest = l;
	}
	if (r < n && a[r] > a[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void heap_sort(int a[], int n)
{
	//build heap
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]); //move current node to end
		heapify(a, i, 0);
	}
}

int main()
{
	int a[10] = { 8,6,34,22,40,5,11,23,44,18 };
	int n = 10;
	//int b[10];
	//bubble_sort(a, n);
	//selection_sort(a, n);
	//insertion_sort(a, n);
	//merge_sort(a, b, 0, 9);
	//quick_sort(a, 0, 999);
	heap_sort(a, n);

	output(a, n);
	system("pause");
}
