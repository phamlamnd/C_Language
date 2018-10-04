#include<iostream>
using namespace std;

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int a[], int left, int right)
{
	int pivot = a[left];
	int i = left;
	int j = right + 1;
	while (i <= j)
	{
		while (a[++i] < pivot && i <= j);
		while (a[--j] >= pivot && i <= j);
		if (i < j) Swap(&a[i], &a[j]);
	}
	Swap(&a[j], &a[left]);
	return j;
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
			l1++;
			i++;
		}
		else
		{
			b[i] = a[l2];
			l2++;
			i++;
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

void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[largest] < a[l])
	{
		largest = l;
	}
	if (r < n && a[largest] < a[r])
	{
		largest = r;
	}
	if (largest != i)
	{
		Swap(&a[largest], &a[i]);
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	for (i = n - 1; i >= 0; i--)
	{
		Swap(&a[0], &a[i]);
		heapify(a, i, 0);
	}
}

void output(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << "\n";
}

int linearSearch(int a[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

int binarySearch(int a[], int left, int right, int x)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		if (x == a[mid])
		{
			return mid;
		}
		if (x < a[mid])
		{
			return binarySearch(a, left, mid - 1, x);
		}
		if (x > a[mid])
		{
			return binarySearch(a, mid + 1, right, x);
		}
	}
	return -1;
}


int main()
{
	int a[10] = { 8,6,34,22,40,5,11,23,44,18 };
	int b[10];
	int n = 10;
	int x = 40;
	output(a, n);
	system("pause");
}