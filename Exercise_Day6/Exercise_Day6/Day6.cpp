#include <C:\Program Files\Windows Kits\10\Include\10.0.10150.0\ucrt\stdio.h>
#include <C:\Program Files\Windows Kits\10\Include\10.0.10150.0\ucrt\math.h>
#include "D:\[LamPV2]@Fsoft\2.C_Language\Exercise_Day6\Exercise_Day6\Day6.h"

/*Question 1:
C Program to Find the Sum of Natural Numbers using Recursion.
Find the sum from 1 to N using recursion*/
int sumOfNaturalNumbers(int num)
{
	if (num == 1)
	{
		return 1;
	}
	return num + sumOfNaturalNumbers(num - 1);
}

/*Question 2:
C Program to Find Factorial of a Number N Using Recursion*/
int findFactorialOfANumber(int num)
{
	if (num == 1)
	{
		return 1;
	}
	return num * findFactorialOfANumber(num - 1);
}

/*Question 3:
C Program to Find G.C.D Using Recursion
This program takes two positive integers as input from the user and calculates GCD using recursion.*/
int findGCD(int num1, int num2)
{
	if (num1 == num2)
	{
		return num1;
	}
	else if(num1 > num2)
	{
		return findGCD(num1 - num2, num2);
	}
	else
	{
		return findGCD(num1, num2 - num1);
	}
}

/*Question 4
Write a program in C to count the digits of a given number using recursion*/
int countDigits(int num)
{
	if (num == 0)
	{
		return 0;
	}
	return 1 + countDigits(num / 10);
}

/*Question 5
Write a program in C to find the sum of digits of a number using recursion*/
int sumOfDigits(int num)
{
	if (num == 0)
	{
		return 0;
	}
	return (num % 10) + sumOfDigits(num / 10);
}

/*Question 6
Write a program in C to get the largest element of an array using recursion*/
int getLargestElement(int arr[], int n)
{
	if (n > 1)
	{
		if (arr[n - 1] > arr[n - 2])
		{
			arr[n - 2] = arr[n - 1];
		}
		getLargestElement(arr, n - 1);
	}
	return arr[0];
}

/*Question 7
Write a program in C to reverse a string using recursion*/
void reverseString(char str[], int len)
{
	if (len > 0)
	{
		putchar(str[len - 1]);
		reverseString(str, len - 1);
	}
}

/*Question 8
Write a program in C to convert a decimal number to binary using recursion*/
void convertToBinary(int num)
{
	if (num > 0)
	{
		convertToBinary(num >> 1);
		printf("%d", num & 0x01);
	}
}

/*Question 9
Write a program in C to check a number is a prime number or not using recursion*/
int isPrimeNumber(int num, int i)
{
	if (num < 2) return 0;
	if (num == 2) return 1;
	if (num % 2 == 0) return 0;
	if (i <= sqrt(num))
	{
		if (num % i == 0) return 0;
		isPrimeNumber(num, i + 2);
	}
	return 1;
}