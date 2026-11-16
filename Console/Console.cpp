#include <Windows.h>

#include "calculation.h"
#include "input.h"
#include "output.h"

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	char znak = ReadOperator();
	double a = ReadNumber("Введите первое число: ");
	double b = ReadNumber("Введите второе число: ");

	double result = 0;
	int status = Calculate(znak, a, b, result);
	PrintResult(status, result);

	return 0;
}