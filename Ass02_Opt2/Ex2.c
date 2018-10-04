#include<stdio.h>
#include<conio.h>
#include<math.h>

int IsPrime(int x)
{
	int i;
	if(x < 2) return 0; 
	if(x == 2) return 1;
	if(x % 2 == 0) return 0;
	for(i = 3; i <= sqrt(x); i += 2)
		{if(x % i == 0) return 0;}
	return 1;
}

int main()
{
	char s[]="1234567890"; unsigned *p = (unsigned *)&s[2];
	printf("\nc = %c", (char)(*(p + 1)));
	*p=0x4163;
	printf("\ns = %s",s);
	printf("\nPrint all prime from 100 t0 150");
	int num;
	for(num = 100; num <= 150; num++)
	{
		if(IsPrime(num) == 0)
		{
			printf("\n%d", num);
		}
	}
}
