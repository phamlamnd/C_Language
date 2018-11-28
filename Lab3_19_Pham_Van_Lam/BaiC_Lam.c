/*
Bai C
Name:  Pham Van Lam
Class: EP0818E
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*Struct sinh vien*/
struct Student
{
	int Code;
	char Name[30];
	char Sex[30];
	float Mark1;
	float Mark2;
	float Mark3;	
};

/*Nhap thong tin sinh vien*/
void input(struct Student* studentList, int n)
{
	int i, j;
	int check;	/*Bien kiem tra ma sinh vien co bi trung khong*/
	for(i = 0; i < n; i++)
	{
		printf("\nNhap thong tin sinh vien thu %d:", i + 1);
		
		/*Nhap ma sinh vien. Kiem tra dieu kien khong duoc trung nhau*/
		do{
			printf("\nNhap ma sinh vien:");
			scanf("%d", &studentList[i].Code);
			check = 0;
			for(j = 0; j < i; j++)
			{
				if(studentList[j].Code == studentList[i].Code)
				{
					check = 1;
				}
			}
			
		}while(check == 1);
		
		/*Nhap ho ten sinh vien*/
		printf("\nNhap ho ten: ");
		fflush(stdin);
		gets(studentList[i].Name);
		
		/*Nhap gioi tinh*/
		printf("\nNhap gioi tinh: ");
		fflush(stdin);
		gets(studentList[i].Sex);
		
		/*Nhap diem mon 1*/
		printf("\nNhap diem mon 1: ");
		scanf("%f", &studentList[i].Mark1);
		
		/*Nhap diem mon 2*/
		printf("\nNhap diem mon 2: ");
		scanf("%f", &studentList[i].Mark2);
		
		/*Nhap diem mon 3*/
		printf("\nNhap diem mon 3: ");
		scanf("%f", &studentList[i].Mark3);
	}
}


/*In ra man hinh danh sach sinh vien da nhap*/
void output(struct Student* studentList, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("\n%d\t%s\t%s\t%.1f\t%.1f\t%.1f", studentList[i].Code, studentList[i].Name,
		studentList[i].Sex, studentList[i].Mark1, studentList[i].Mark2, studentList[i].Mark3);
	}
}

/*Ham tinh diem trung binh cua 1 sinh vien*/
float AvgCal(struct Student oneStudent)
{
	return (oneStudent.Mark1 + oneStudent.Mark2 + oneStudent.Mark3)/3;
}

/*In ra danh sach nhung sinh vien co diem trung binh lon hon 5*/
void printMark5(struct Student* studentList, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(AvgCal(studentList[i]) > (float)5)
		{
			printf("\n%d\t%s\t%s\t%.1f\t%.1f\t%.1f\t%.1f", studentList[i].Code, studentList[i].Name,
			studentList[i].Sex, studentList[i].Mark1, studentList[i].Mark2, studentList[i].Mark3, AvgCal(studentList[i]));	
		}
	}
}


int main()
{
	struct Student* studentList;
	int n;
	
	printf("\nNhap so luong sinh vien: ");
	scanf("%d", &n);
	studentList = (struct Student*)malloc(n * sizeof(struct Student));
	
	/*Nhap danh sach sinh vien*/
	input(studentList, n);
	
	printf("\nIn ra man hinh danh sach sinh vien: ");
	output(studentList, n);
	
	printf("\n\nDanh sach sinh vien diem > 5: ");
	printMark5(studentList, n);
	
	/*Giai phong vung nho da cap phat*/
	free(studentList);
	
	getch();
	return 0;
}
