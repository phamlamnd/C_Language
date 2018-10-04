#include <stdio.h>
#include <conio.h>

int main()
{
	unsigned int a, b, c;
	do{
		printf("\nNhap a = ");
		scanf("%d", &a);
		if(a < 0)
		{
			printf("\na phai > 0");
		}
	}while(a < 0);
	
	do{
		printf("\nNhap b = ");
		scanf("%d", &b);
		if(a < 0)
		{
			printf("\nb phai > 0");
		}
	}while(a < 0);
	
	do{
		printf("\nNhap a = ");
		scanf("%d", &c);
		if(a < 0)
		{
			printf("\nc phai > 0");
		}
	}while(a < 0);
	
	int max = a;
	if(max < b)
	{
		max = b;
	}
	if(max < c)
	{
		max = c;
	}
	printf("\nMax = %d", max);
	
	return 0;
}
