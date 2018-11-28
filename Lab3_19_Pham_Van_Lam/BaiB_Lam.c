/*
Bai B
Name:  Pham Van Lam
Class: EP0818E
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

int countUpper(char s[])
{
	int upper = 0;
	int len = strlen(s);
	int i;
	for(i = 0; i < len; i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			upper++;
		}
	}
	return upper;
}

int countLower(char s[])
{
	int lower = 0;
	int len = strlen(s);
	int i;
	for(i = 0; i < len; i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			lower++;
		}
	}
	return lower;
}

int countDigit(char s[])
{
	int digit = 0;
	int len = strlen(s);
	int i;
	for(i = 0; i < len; i++)
	{
		if(s[i] >= '1' && s[i] <= '9')
		{
			digit++;
		}
	}
	return digit;
}

int countWord(char s[])
{
	int word = 0;
	int len = strlen(s);
	int i;
	
	/*Neu chu so hien tai khac khoang trang, ky tu sau la khoang trang thi la 1 tu*/
	for(i = 0; i < len - 1; i++)
	{
		if(s[i] != ' ' && s[i + 1] == ' ')
		{
			word++;
		}
	}
	/*Xet them truong hop tu cuoi cung neu khac khoang trang thi tinh la 1 tu*/
	if(s[len - 1] != ' ')
	{
		word++;
	}
	
	return word;
}

int main()
{
	char s[30];
	printf("\nNhap vao chuoi ky tu: ");
	fflush(stdin);
	gets(s);
	
	printf("\nSo chu cai viet hoa: %d", countUpper(s));
	printf("\nSo chu cai viet thuong: %d", countLower(s));
	printf("\nSo ky tu chu so: %d", countDigit(s));
	printf("\nSo tu trong chuoi: %d", countWord(s));
	
	getch();
	return 0;
}
