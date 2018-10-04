#include <stdio.h>
#include <conio.h>
#include "Day5.h"

int main()
{
	//Question 1
	int num = 89;
	printBinary(num);
	
	//Question 2
	int x = 17;
	printf("\nGreater or equal %d and smallest power of 2 is: %d", x, findNumberGreater(x));
	
	//Question 3
	isPowerOfTwo(32);
	
	//Question 4
	int arr[] = {1, 2, 3, 2, 2, 1, 3};
	printf("\nOdd number: %d", findNumberOdd(arr, 7));
	
	//Question 5
	int n = 1;
	printf("\nReversed bits = %u", reverseAllBits(n));
	
	//Question 6
	int A[]= {1,3,5};
	printf("\nFind sum of f(Ai, Aj) different bit = %d", sumOfF(A, 3));
	
	return 0;
}
