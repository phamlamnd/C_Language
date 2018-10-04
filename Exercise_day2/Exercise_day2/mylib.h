#ifndef _MY_LIB_H_
#define _MY_LIB_H_

#include <string.h>
#define MAX 100
#define SWAP(a,b) ((a)=(a)+(b),(b)=(a)-(b),(a)=(a)-(b))

void printArray(int arr[], int n);
void mergeSort(int a[], int b[], int left, int right);
void quickSort(int a[], int left, int right);

static void fun(void);
extern void dosomething(void);
extern inline void inlineFunction(void);

#endif