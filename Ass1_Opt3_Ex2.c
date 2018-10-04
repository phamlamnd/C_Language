#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct Account
{
	char Name[50];
	int Age;
	char Address[50];
	float Balance;
};

int IsInteger(char *s)
{
	int i;
	int len = strlen(s);	
	for(i = 0; i < len; i++)
	{
		if(s[i] < '0' || s[i] > '9')
		{
			return 0;
		}
	}
	return 1;
}

void OpenBankAccount(struct Account **TPBank, unsigned int *n)
{
	*TPBank = (struct Account*)realloc(*TPBank, ((*n)++)*sizeof(struct Account));
	
}


int main()
{
	struct Account *TPBank = NULL;
	unsigned int n; //Number of Account in the TP Bank
	
	int buf[50];
	printf("======================================");
	printf("\n1.Open a Bank account");
	printf("\n2.Perform transactions for an account");
	printf("\n3.Exit the application");
	
	do{
		printf("\nChoose service>> ");
		fflush(stdin);
		gets(buf);
		if(IsInteger(buf) == 0 || atoi(buf) < 1 || atoi(buf) > 3)
		{
			printf("\nInvalid!");
		}
	}while(IsInteger(buf) == 0 || atoi(buf) < 1 || atoi(buf) > 3);
	free(TPBank);
	
	
}
