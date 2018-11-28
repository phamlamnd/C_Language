/*
Bai A
Name:  Pham Van Lam
Class: EP0818E
*/

#include <stdio.h>
#include <conio.h>

int main()
{
	int a, b, c;
	int max;
	
	do{
		printf("\nNhap so nguyen duong a = ");
		scanf("%d", &a);
		if(a < 0)
		{
			printf("\na phai la so nguyen duong. Hay nhap lai!");
		}
	}while(a < 0);
	
	do{
		printf("\nNhap so nguyen duong b = ");
		scanf("%d", &b);
		if(b < 0)
		{
			printf("\nb phai la so nguyen duong. Hay nhap lai!");
		}
	}while(b < 0);
	
	do{
		printf("\nNhap so nguyen duong c = ");
		scanf("%d", &c);
		if(c < 0)
		{
			printf("\nc phai la so nguyen duong. Hay nhap lai!");
		}
	}while(c < 0);
	
	printf("\na = %d", a);
	printf("\nb = %d", b);
	printf("\nc = %d", c);
	
	max = a;
	if(b > max)
	{
		max = b;
	}
	if(c > max)
	{
		max = c;
	}
	
	printf("\nSo lon nhat max = %d", max);
	
	getch();
	return 0;
}
