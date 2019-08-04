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

//Check number is positive integer
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

//Check number is float > 0
int IsFloat(char *s)
{
	int i;
	int count = 0;
	int len = strlen(s);	
	for(i = 0; i < len; i++)
	{
		if(s[i] == '.')
		{
			count++;
			if(count == 2) 
				return 0;
		}
		if((s[i] < '0' || s[i] > '9') && s[i] != '.')
		{
			return 0;
		}
	}
	return 1;
}

//Open an account TPBank, n: number of account
void OpenBankAccount(struct Account **TPBank, unsigned int *n)
{
	int i;
	char buf[50];
	int check;
	
	*TPBank = (struct Account*)realloc(*TPBank, (*n + 1)*sizeof(struct Account));
	if(*TPBank == NULL)
	{
		//Can't open account
		printf("\nSorry! Not enough memory. Can't open account");
		return;
	}
	else
	{
		//Increase number of account
		(*n)++;
	}
	
	do{
		check = 0;
		printf("\nEnter your name: ");
		fflush(stdin);
		gets(buf);
		//Check account already open
		for(i = 0; i < (*n) - 1; i++)
		{
			if(strcmp(buf, (*TPBank + i)->Name) == 0)
			{
				check = 1;
				printf("\ncheck %s", (*TPBank + i)->Name);
				printf("\nAccount already open! Please re-enter!");
				break;
			}
		}
	}while(check == 1);
	strcpy((*TPBank + *n - 1)->Name,buf);
	
	do{
		printf("Enter your age: ");
		fflush(stdin);
		gets(buf);
		if(IsInteger(buf) == 0 || atoi(buf) <= 0)
		{
			printf("Invalid!\n");
		}
	}while((IsInteger(buf) == 0) || atoi(buf) <= 0);
	(*TPBank + (*n) - 1)->Age = atoi(buf);
	
	printf("Enter your address: ");
	fflush(stdin);
	gets((*TPBank + (*n) - 1)->Address);
	
	do{
		printf("Enter your balance: ");
		fflush(stdin);
		gets(buf);
		if(IsFloat(buf) == 0)
		{
			printf("Invalid!\n");
		}
	}while(IsFloat(buf) == 0);
	(*TPBank + (*n) - 1)->Balance = atof(buf);
	
	printf("\nWelcome new account, your information:");
	printf("\nName: %s", (*TPBank + (*n) - 1)->Name);
	printf("\nAge: %d", (*TPBank + (*n) - 1)->Age);
	printf("\nAddress: %s", (*TPBank + (*n) - 1)->Address);
	printf("\nBalance: $%.2f", (*TPBank + (*n) - 1)->Balance);
	getch();
}

int SelectionMenu()
{
	int selection;
	char buf[50];
	printf("\n\n======================================");
	printf("\nWelcome to Tien phong bank ATM System");
	printf("\n1.Open a Bank account");
	printf("\n2.Perform transactions for an account");
	printf("\n3.Exit the application");
	
	do{
		printf("\nChoose service>> ");
		fflush(stdin);
		gets(buf);
		selection = atoi(buf);
		if(IsInteger(buf) == 0 || selection < 1 || selection > 3)
		{
			printf("Invalid!");
		}
	}while(IsInteger(buf) == 0 || selection < 1 || selection > 3);
	
	return selection;
}

int SelectionPerformTransactions()
{
	int selection;
	char buf[50];
	printf("\nPlease choose the service:");
	printf("\n1.Deposit money in his account");
	printf("\n2.Withdraw money from his account");
	printf("\n3.Display the number of transactions and losing balance");
	printf("\n4.Exit from the application");
	
	do{
		printf("\nChoose service>> ");
		fflush(stdin);
		gets(buf);
		selection = atoi(buf);
		if(IsInteger(buf) == 0 || selection < 1 || selection > 4)
		{
			printf("Invalid!");
		}
	}while(IsInteger(buf) == 0 || selection < 1 || selection > 4);
	return selection;
}

void PerformTransactions(struct Account **TPBank, unsigned int n)
{
	if(n == 0)
	{
		printf("\nTPBank no have any account");
		getch();
		return;
	}
	
	int selection; //1~4
	int numberOfTransaction = 0;
	char buf[50];
	
	while(1)
	{
		selection = SelectionPerformTransactions();
		if(selection == 1)
		{
			numberOfTransaction++;		
			do{
				printf("\nEnter amount to deposit: ");
				fflush(stdin);
				gets(buf);
				if(IsFloat(buf) == 0)
				{
					printf("Invalid!");
				}
			}while(IsFloat(buf) == 0);
			float deposit = atof(buf);
			printf("You have deposit: %.2f$",deposit);
			(*TPBank + n - 1)->Balance += deposit;
			printf("\nYour balance is: %.2f$", (*TPBank + n - 1)->Balance);
			getch();
		}
		else if(selection == 2)
		{
			numberOfTransaction++;
			do{
				printf("\nEnter amount to withdrawn: ");
				fflush(stdin);
				gets(buf);
				if(IsFloat(buf) == 0)
				{
					printf("Invalid!");
				}
			}while(IsFloat(buf) == 0);			
			float withdrawn = atof(buf);
			printf("You have withdrawn: %.2f$",withdrawn);
			(*TPBank + n - 1)->Balance -= withdrawn;
			printf("\nYour balance is: %.2f$\n", (*TPBank + n - 1)->Balance);
			getch();
		}
		else if(selection == 3)
		{
			printf("\nYou have perform %d transaction(s)", numberOfTransaction);
			printf("\nYour balance is: %.2f$", (*TPBank + n - 1)->Balance);
			getch();
		}
		else //if(selection == 4)
		{
			printf("\nExit from the application");
			break;
		}
	}
}

int main()
{
	struct Account *TPBank = NULL;
	unsigned int n = 0; //Number of Account in the TP Bank
	int selection;
	
	while(1)
	{
		selection = SelectionMenu();
		if(selection == 1)
		{
			
			printf("\nOpen an account");
			OpenBankAccount(&TPBank, &n);
		}
		else if(selection == 2)
		{
			printf("\nPerform transactions for an account");
			PerformTransactions(&TPBank, n);
		}
		else // if(selection == 3)
		{
			printf("\nExit the application");
			break;
		}
	}
	
	free(TPBank);
}
