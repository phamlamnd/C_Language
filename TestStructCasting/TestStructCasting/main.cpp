#include "StructCasting.h"
#include <iostream>

int main()
{
	GPIOA->MODER |= 0x01 << 14;
	system("pause");
}