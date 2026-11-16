#include "calculation.h"

double Clojenie(double a, double b)
{
	return a + b;
}

double Vichitanie(double a, double b)
{
	return a - b;
}

double Umnojenie(double a, double b)
{
	return a * b;
}

double Delenie(double a, double b)
{
	return a / b;
}

int Clojenie(int a, int b)
{
	return a + b;
}

int Calculate(char op, double a, double b, double& result)
{
	if (op == '+')
	{
		result = Clojenie(a, b);
		return 0;
	}
	else if (op == '-')
	{
		result = Vichitanie(a, b);
		return 0;
	}
	else if (op == '*')
	{
		result = Umnojenie(a, b);
		return 0;
	}
	else if (op == '/')
	{
		if (b == 0)
		{
			return 1;
		}
		result = Delenie(a, b);
		return 0;
	}
	else
	{
		return 2;
	}
}