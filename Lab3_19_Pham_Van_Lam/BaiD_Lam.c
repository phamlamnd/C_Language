/*
Bai D
Name:  Pham Van Lam
Class: EP0818E
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100

struct Book
{
	char Name[30];
	int numPage;
	float Cost;
};

/*Ham nhap danh sach cac quyen sach*/
void input(struct Book BooksList[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("\nNhap thong cuon sach thu: %d", i + 1);
		printf("\nNhap vao ten sach: ");
		fflush(stdin);
		gets(BooksList[i].Name);
		
		do{
			printf("\nNhap so trang: ");
			scanf("%d", &BooksList[i].numPage);
		}while(BooksList[i].numPage < 0);
		
		do{
			printf("\nNhap gia tien: ");
			scanf("%f", &BooksList[i].Cost);
		}while(BooksList[i].Cost < 0);
	}
}

/*Ham in ra man hinh cac quyen sach*/
void output(struct Book BooksList[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("\n%s\t\t%d\t\t%.2f", BooksList[i].Name, BooksList[i].numPage, BooksList[i].Cost);
	}
}

/*Ham ghi ra file*/
void writeToFile(struct Book BooksList[], int n, char filename[])
{
	FILE *fp =fopen(filename, "w");
	if(!fp)
	{
		printf("\nCan not open file");
		return;
	}
	
	int i;
	for(i = 0; i < n; i++)
	{
		fprintf(fp, "%s\t\t%d\t\t%.2f\n", BooksList[i].Name, BooksList[i].numPage, BooksList[i].Cost);
	}
	
	fclose(fp);
}

int main()
{
	struct Book BooksList[MAX];
	int n;
	do{
		printf("\nNhap vao so luong sach: ");
		scanf("%d", &n);
	}while(n <= 0);
	
	/*Nhap thong tin cuon sach*/
	input(BooksList, n);
	
	/*In ra man hinh*/
	printf("\nDanh sach cac quyen sach: ");
	output(BooksList, n);
	
	/*Ghi ra file*/
	char filename[30] = "BOOKSLIST.TXT";
	writeToFile(BooksList, n, filename);
	
	getch();
	return 0;
}
