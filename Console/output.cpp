#include "output.h"

#include <iostream>

void PrintResult(int status, double result)
{
	std::cout << "Ответ: ";
	if (status == 0)
	{
		std::cout << result << "\n";
	}
	else if (status == 1)
	{
		std::cout << "На ноль делить незя";
	}
	else
	{
		std::cout << "Неверный знак";
	}
}