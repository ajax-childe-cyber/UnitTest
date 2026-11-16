#include "input.h"

#include <iostream>

char ReadOperator()
{
	char znak = ' ';
	std::cout << "Введите оператор: ";
	std::cin >> znak;
	return znak;
}

double ReadNumber(const char* prompt)
{
	double value = 0;
	std::cout << prompt;
	std::cin >> value;
	return value;
}