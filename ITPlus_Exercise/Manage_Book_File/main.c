#include <stdio.h>
#define MAX 100
struct Book
{
	char name[30];
	int page;
	float cost;
};

void input(struct Book booksList[], int *n)
{
	do{
		printf("\nEnter number of book: ");
		scanf("%d", n);
	}while(*n < 0 || *n > 100);
	
	int i;
	for(i = 0; i < *n; i++)
	{
		printf("\nEnter book name: ");
		fflush(stdin);
		gets(booksList[i].name);
		printf("\nEnter number of page: ");
		scanf("%d", &booksList[i].page);
		printf("\nEnter cost: ");
		scanf("%f", &booksList[i].cost);
	}
}

void output(struct Book booksList[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("\nName: %s", booksList[i].name);
		printf("\nPage: %d", booksList[i].page);
		printf("\nCost: %.2f", booksList[i].cost);
	}
}

void writeFile(struct Book booksList[], int n, char filename[])
{
	FILE *fp = fopen(filename, "w");
	int i;
	for(i = 0; i < n; i++)
	{
		fprintf(fp, "%s\t%d\t%.2f\n", booksList[i].name, booksList[i].page, booksList[i].cost);
	}
	
	fclose(fp);
}

int main()
{
	struct Book booksList[MAX];
	int n;
	input(booksList, &n);
	output(booksList, n);
	
	char filename[30] = "data.txt";
	writeFile(booksList, n, filename);
	
	return 0;
}
