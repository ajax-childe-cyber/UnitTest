#include "CppUnitTest.h"
#include "calculation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Коды, которые возвращает Calculate:
//   0 - успех, 1 - деление на ноль, 2 - неверный знак

namespace AppTests
{
	TEST_CLASS(CalculatePositiveTests)
	{
	public:

		TEST_METHOD(Calculate_Plus_TwoAndThree_ReturnsFive)
		{
			double result = 0;
			int status = Calculate('+', 2, 3, result);
			Assert::AreEqual(0, status);
			Assert::AreEqual(5.0, result, 0.0001);
		}

		TEST_METHOD(Calculate_Minus_TenAndFour_ReturnsSix)
		{
			double result = 0;
			int status = Calculate('-', 10, 4, result);
			Assert::AreEqual(0, status);
			Assert::AreEqual(6.0, result, 0.0001);
		}

		TEST_METHOD(Calculate_Multiply_ThreeAndFour_ReturnsTwelve)
		{
			double result = 0;
			int status = Calculate('*', 3, 4, result);
			Assert::AreEqual(0, status);
			Assert::AreEqual(12.0, result, 0.0001);
		}

		TEST_METHOD(Calculate_Divide_SixAndThree_ReturnsTwo)
		{
			double result = 0;
			int status = Calculate('/', 6, 3, result);
			Assert::AreEqual(0, status);
			Assert::AreEqual(2.0, result, 0.0001);
		}

		TEST_METHOD(Clojenie_Double_OnePointFiveAndTwoPointFive_ReturnsFour)
		{
			Assert::AreEqual(4.0, Clojenie(1.5, 2.5), 0.0001);
		}

		TEST_METHOD(Clojenie_Int_TwoAndThree_ReturnsFive)
		{
			Assert::AreEqual(5, Clojenie(2, 3));
		}

		TEST_METHOD(Vichitanie_SevenAndTwo_ReturnsFive)
		{
			Assert::AreEqual(5.0, Vichitanie(7, 2), 0.0001);
		}

		TEST_METHOD(Umnojenie_TwoAndFour_ReturnsEight)
		{
			Assert::AreEqual(8.0, Umnojenie(2, 4), 0.0001);
		}

		TEST_METHOD(Delenie_NineAndThree_ReturnsThree)
		{
			Assert::AreEqual(3.0, Delenie(9, 3), 0.0001);
		}
	};

	TEST_CLASS(CalculateBoundaryTests)
	{
	public:

		TEST_METHOD(Calculate_Plus_ZeroAndZero_ReturnsZero)
		{
			double result = 1;
			int status = Calculate('+', 0, 0, result);
			Assert::AreEqual(0, status);
			Assert::AreEqual(0.0, result, 0.0001);
		}

		TEST_METHOD(Calculate_Minus_EqualNumbers_ReturnsZero)
		{
			double result = 1;
			int status = Calculate('-', 5, 5, result);
			Assert::AreEqual(0, status);
			Assert::AreEqual(0.0, result, 0.0001);
		}

		TEST_METHOD(Calculate_Multiply_ByZero_ReturnsZero)
		{
			double result = 1;
			int status = Calculate('*', 12345, 0, result);
			Assert::AreEqual(0, status);
			Assert::AreEqual(0.0, result, 0.0001);
		}

		TEST_METHOD(Calculate_Divide_ZeroByNumber_ReturnsZero)
		{
			double result = 1;
			int status = Calculate('/', 0, 5, result);
			Assert::AreEqual(0, status);
			Assert::AreEqual(0.0, result, 0.0001);
		}

		TEST_METHOD(Calculate_Multiply_NegativeAndPositive_ReturnsNegative)
		{
			double result = 0;
			int status = Calculate('*', -2, 3, result);
			Assert::AreEqual(0, status);
			Assert::AreEqual(-6.0, result, 0.0001);
		}

		TEST_METHOD(Calculate_Divide_OneByFour_ReturnsQuarter)
		{
			double result = 0;
			int status = Calculate('/', 1, 4, result);
			Assert::AreEqual(0, status);
			Assert::AreEqual(0.25, result, 0.0001);
		}

		TEST_METHOD(Calculate_Plus_ZeroPointOneAndZeroPointTwo_ReturnsAboutZeroPointThree)
		{
			double result = 0;
			int status = Calculate('+', 0.1, 0.2, result);
			Assert::AreEqual(0, status);
			Assert::AreEqual(0.3, result, 0.0001);
		}

		TEST_METHOD(Calculate_Multiply_LargeNumbers_ReturnsProduct)
		{
			double result = 0;
			int status = Calculate('*', 1000000000, 1000000000, result);
			Assert::AreEqual(0, status);
			Assert::AreEqual(1e18, result, 1.0);
		}
	};

	TEST_CLASS(CalculateNegativeTests)
	{
	public:

		TEST_METHOD(Calculate_Divide_ByZero_ReturnsCodeOne)
		{
			double result = 0;
			int status = Calculate('/', 5, 0, result);
			Assert::AreEqual(1, status);
		}

		TEST_METHOD(Calculate_Divide_ZeroByZero_ReturnsCodeOne)
		{
			double result = 0;
			int status = Calculate('/', 0, 0, result);
			Assert::AreEqual(1, status);
		}

		TEST_METHOD(Calculate_UnknownOperator_Letter_ReturnsCodeTwo)
		{
			double result = 0;
			int status = Calculate('x', 2, 3, result);
			Assert::AreEqual(2, status);
		}

		TEST_METHOD(Calculate_UnknownOperator_Space_ReturnsCodeTwo)
		{
			double result = 0;
			int status = Calculate(' ', 2, 3, result);
			Assert::AreEqual(2, status);
		}

		TEST_METHOD(Calculate_Error_DoesNotChangeResult)
		{
			double result = 777.0;
			Calculate('/', 5, 0, result);
			Assert::AreEqual(777.0, result, 0.0001);

			Calculate('?', 5, 5, result);
			Assert::AreEqual(777.0, result, 0.0001);
		}

		TEST_METHOD(Delenie_ByZero_ReturnsInfinity)
		{
			Logger::WriteMessage("Delenie(1, 0) is called directly, without Calculate");
			double r = Delenie(1, 0);
			Assert::IsTrue(r > 1e308);
		}
	};
}