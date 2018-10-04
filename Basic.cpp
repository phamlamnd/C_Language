	//LECTURE 1:
	
	int i = 10, j = 5;
	i = !i>14;
	printf("%d\n", i);
	printf("%d%d%d\n", j, ++j, ++j);
	std::cout << j << ++j << ++j << std::endl;
	std::cout << typeid(i).name() << std::endl;
	i = 5;
	printf("%d\n", i = ++i == 6);
	printf(4 + "anandavihar");
	printf("G\by\ba\bn\b" "tonic" "\r.com");
	int x = 3, y, z; y = x = 10; z = x < 10;
	printf("\nx = %d, y = %d, z = %d", x, y, z);
	int k = 35;
	printf("\n%d%d%d", k == 35, k = 50, k > 40);
	printf("%f", sqrt(36.0));
	int a = 4, b = 7, c;
	c = a == b;
	printf("\nc = %d", c);
	
	//LECTURE 2:
	int x = 0;
	switch(x)
	{
		case 1: printf("One");
		case 0: printf("Zero");
		case 2: printf("Hello World");
	}
	
	int a = 1;
	while(a<=100)
	{
		printf("\n%d",a++);
	}
	
	int i = 0, j = 1, k;
	k = (i,j)?i:j;	
	printf("\n%d", k);
	
	a = 10;
	printf("\n%d %d", a, !a++);
	
	
	EX1:
	#include<stdio.h>
	#include<conio.h>

	int main()
	{
		float So_Du_Dau_Thang, Tong_Tien_Da_Rut, Tong_Tien_Da_Gui_Trong_Thang, So_Du_Tai_Khoan_Cuoi_Thang;
		printf("\nNhap vao so du dau thang: ");
		scanf("%f",&So_Du_Dau_Thang);
		printf("\nNhap vao tong tien da rut: ");
		scanf("%f",&Tong_Tien_Da_Rut);
		printf("\nNhap vao tong so tien da gui trong thang: ");
		scanf("%f",&Tong_Tien_Da_Gui_Trong_Thang);
		
		So_Du_Tai_Khoan_Cuoi_Thang = So_Du_Dau_Thang - Tong_Tien_Da_Rut + Tong_Tien_Da_Gui_Trong_Thang
		- (Tong_Tien_Da_Rut + Tong_Tien_Da_Gui_Trong_Thang) * 0.01;
		
		printf("\nSo du tai khoan cuoi thang: %f", So_Du_Tai_Khoan_Cuoi_Thang);
	}
	
	
	
	