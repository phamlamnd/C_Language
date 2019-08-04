/*
** [Project 1] Multiples of 3 and 5
** If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
** The sum of these multiples is 23.
** Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>
#include <conio.h>

#define ZERO_NUMBER		0
#define THREE_NUMBER 	3
#define FIVE_NUMBER 	5

int sumAllMultiplesOfThreeAndFive(const int maxNumber)
{
	int num;
	int sum = ZERO_NUMBER;
	for (num = THREE_NUMBER; num < maxNumber; num++)
	{
		if ((ZERO_NUMBER == (num % THREE_NUMBER)) || (ZERO_NUMBER == (num % FIVE_NUMBER)))
		{
			sum += +num;
		}
	}
	return sum;
}

int main()
{
	int sum = sumAllMultiplesOfThreeAndFive(1000);
	printf("sum = %d", sum);

	return 0;
}
