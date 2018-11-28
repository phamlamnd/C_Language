#include<iostream>
using namespace std;

int a[10] = { 8,6,34,-3,40,5,11,23,44,18 };
int b[10];
void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

void bubble_sort(int a[], int n)
{
	print(a, 10);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > 0; j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}			
		}
		print(a, 10);
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
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		print(a, 10);
	}
}

void insertion_sort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j = i - 1;
		while (temp < a[j] && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
		print(a, 10);
	}
}


//Merge sort
void merging(int left, int mid, int right)
{
	int l1 = left, l2 = mid + 1;
	int i;

	for (i = left; l1 <= mid && l2 <= right; i++)
	{
		if (a[l1] <= a[l2])
		{
			b[i] = a[l1++];
		}
		else
		{
			b[i] = a[l2++];
		}
	}

	while (l1 <= mid)
	{
		b[i++] = a[l1++];
	}

	while (l2 <= right)
	{
		b[i++] = a[l2++];
	}
	for (i = left; i <= right; i++)
	{
		a[i] = b[i];
	}
}

void merge_sort(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merging(left, mid, right);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
// 8,6,34,22,40,5,11,23,44,18 
int partition(int arr[], int left, int right)
{
	int pivot = arr[right];
	int i = left - 1, j = right;
	while (i < j)
	{
		while (arr[++i] < pivot && i <= j);
		while (arr[--j] >= pivot && i <= j);
		if (i < j) swap(&arr[i], &arr[j]);
	}
	swap(&arr[i], &arr[right]);
	return i;
}

void quick_sort(int arr[], int left, int right)
{
	if (left < right)
	{
		print(a, 10);
		int pi = partition(arr, left, right);
		quick_sort(arr, left, pi - 1);
		quick_sort(arr, pi + 1, right);
	}
}

int main()
{
	//bubble_sort(a, 10);
	//selection_sort(a, 10);
	//insertion_sort(a, 10);
	//merge_sort(0, 9);
	quick_sort(a, 0,9);
	print(a, 10);
	system("pause");
}