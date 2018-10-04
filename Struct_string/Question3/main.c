#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct CongNhan
{
	int MaSo;
	char HoTen[30];
	char GioiTinh[10];
	float LuongCoBan;
	float HeSo;
	float PhuCap;
};

void input(struct CongNhan* List[], int *n)
{
	int maso;
	char hoten[30];
	char gioitinh[10];
	float luongcoban;
	float heso;
	float phucap;
	
	printf("\nNhap vao ma so: ");
	scanf("%d", &maso);
	
	printf("\nNhap vao ho ten: ");
	fflush(stdin);
	gets(hoten);
	
	printf("\nNhap vao gioi tinh: ");
	fflush(stdin);
	gets(gioitinh);
	
	printf("\nNhap vao luong co ban: ");
	scanf("%f", &luongcoban);
	
	printf("\nNhap vao he so: ");
	scanf("%f", &heso);
	
	printf("\nNhap vao phu cap: ");
	scanf("%f", &phucap);
	
	List[*n] = (struct CongNhan*)malloc(sizeof(struct CongNhan));
	
	List[*n]->MaSo = maso;
	strcpy(List[*n]->HoTen, hoten);
	strcpy(List[*n]->GioiTinh, gioitinh);
	List[*n]->LuongCoBan = luongcoban;
	List[*n]->HeSo = heso;
	List[*n]->PhuCap = phucap;
	(*n)++;
}

void output(struct CongNhan* List[], int n)
{
	int i;
	printf("\nDanh sach cong nhan");
	for(i = 0; i < n; i++)
	{
		printf("\n%d\t%s\t%s\t%.2f\t%.2f\t%.2f", List[i]->MaSo, List[i]->HoTen, List[i]->GioiTinh, List[i]->LuongCoBan, List[i]->HeSo, List[i]->PhuCap);
	}
}

float calSalary(struct CongNhan *person)
{
	return person->LuongCoBan * person->HeSo + person->PhuCap;
}

void printSalary(struct CongNhan* List[], int n)
{
	int i;
	printf("\nDanh sach cong nhan co luong > 2000000");
	for(i = 0; i < n; i++)
	{
		if(calSalary(List[i]) > 2000000)
		{
		printf("\n%d\t%s\t%s\t%.2f\t%.2f\t%.2f", List[i]->MaSo, List[i]->HoTen, List[i]->GioiTinh, List[i]->LuongCoBan, List[i]->HeSo, List[i]->PhuCap);
		}
	}
}

char selectMenu()
{
	printf("\nCHUONG TRINH QUAN LY CONG NHAN");
	printf("\n\tAn phim 1 de nhap cong nhan");
	printf("\n\tAn phim 2 de in danh sach cong nhan");
	printf("\n\tAn phim 3 de tim cong nhan luong > 2000000");
	printf("\n\tAn phim 'q' hoac 'Q' de thoat chuong trinh");
	char select;
	do{
		printf("\nNhap lua chon: ");
		fflush(stdin);
		select = getchar();
		if(select != '1' && select != '2' && select != '3' && select != 'q' && select != 'Q')
		{
			printf("\nChon lai phim 1 hoac 2 hoac 'q' hoac 'Q'");
		}
	}while(select != '1' && select != '2' && select != '3' && select != 'q' && select != 'Q');
	return select;
}

int main()
{
	struct CongNhan* List[MAX];
	int n = 0;
	
	while(1)
	{
		char select = selectMenu();
		switch(select)
		{
			case '1':
				input(List, &n);
				getch();
				break;
			case '2':
				output(List, n);
				getch();
				break;
			case '3':
				printSalary(List, n);
			case 'q':
			case 'Q':
				goto finish;
		}
	}
	finish:
	return 0;
}
