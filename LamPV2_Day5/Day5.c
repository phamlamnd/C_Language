#include "Day5.h"
#include <stdio.h>

/*Question 1: Write a program to print Binary representation of a given number*/
void printBinary(unsigned int num)
{
	int i;
	for(i = 0; i <= 31; i++)
	{
		printf("%d",(num<<i)&(1<<31)?1:0);
	}
}

/*Question 2: Write a function that, for a given no n, finds a number p which 
is greater than or equal to n and is a smallest power of 2.*/
int findNumberGreater(unsigned int num)
{
	int i;  
	for(i = 0; i <= 31; i++)
	{
		if(((num<<i) & (1<<31)) == (1<<31))
		{
			break;
		}	
	}
	
	if(num == 1<<(31-i))
	{
		return 1<<(31-i);
	}
	return 1<<(32-i);

}

/*Question 3: Given a positive integer,
write a function to find if it is a power of two or not.*/
int isPowerOfTwo(unsigned int num)
{
	int i;
	int count = 0;
	for(i = 0; i <= 31; i++)
	{
		count += (num>>i)&(0x01);
		if(count > 1)
		{
			printf("\nIs Power of two");
			return 0;
		}
	}
	printf("\nNone Power of two");
	return 1;
}

/*Question 4: Given an array of positive integers.
All numbers occur even number of times except one number which occurs odd number of times.
Find the number in O(n) time & constant space.*/
int findNumberOdd(int arr[], int n)
{
	int i;
	for(i = 1; i < n; i++)
	{
		arr[0] ^= arr[i];
	}
	return arr[0];
}

/*Question 5: Given an unsigned integer, reverse all 
bits of it and return the number with reversed bits*/
unsigned int reverseAllBits(unsigned int num)
{
	int i;
	int rev = 0;
	for(i = 0; i <= 31; i++)
	{
		rev |= ((num>>i)&(0x01))<<(31-i);
	}
	return rev;
}

/*Question 6: */
//count different bit between two number
int countDifferentBit(int x, int y)
{
	int tmp = x ^ y;
	int i;
	int count = 0;
	for(i = 0; i <= 31; i++)
	{
		count += (tmp>>i)&(0x01)?1:0;
	}
	return count;
}

int sumOfF(int arr[], int n)
{
	int i, j, sumdef = 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			sumdef += countDifferentBit(arr[i], arr[j]);
		}
	}
	return sumdef;
}
