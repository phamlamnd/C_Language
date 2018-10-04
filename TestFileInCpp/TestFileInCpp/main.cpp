#include <fstream>
#include <iostream>


int main()
{
	std::fstream fp;
	fp.open("Test.txt", std::ios::out);
	fp << "Pham Van Lam";
	fp.close();
	system("pause");
	return 0;
}