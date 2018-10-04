#include "Day6.h"
#include <stdio.h>

int main()
{
	//Question 1
	printf("Sum of Natural number: %d\n", sumOfNaturalNumbers(20));

	//Question 2
	printf("Factorial of a Number: %d\n", findFactorialOfANumber(6));

	//Question 3
	printf("Find GCD: %d\n", findGCD(366, 60));

	//Question 4
	printf("Count the digits: %d\n", countDigits(12032));

	//Question 5
	printf("Sum of digits: %d\n", sumOfDigits(36));

	//Question 6
	int arr[5] = { 1, 5, 6, 9, 4 };
	printf("Max element = %d\n", getLargestElement(arr, 5));

	//Question 7
	reverseString("Pham Van Lam", 12);

	//Question 8
	printf("\n");
	convertToBinary(66);
	
	//Question 9
	int check =  isPrimeNumber(23, 3);
	if(check == 1)
	{
		printf("\nTrue");
	}
	else
	{
		printf("\nFalse");
	}

	getch();
}
