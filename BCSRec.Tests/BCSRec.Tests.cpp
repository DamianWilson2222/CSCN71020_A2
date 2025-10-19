#include "pch.h"
#include "CppUnitTest.h"


extern "C" {
	int getPerimeter(int* length, int* width);
	int getArea(int* length, int* width);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecTests
{
	TEST_CLASS(Task1_RectangleCalculator)
	{
	public:
		
		TEST_METHOD(PerimeterFunctionality_Length10Width3_Returns26)
		{
			int result = 0;
			int length = 10;
			int width = 3;
			result = getPerimeter(&length,&width);
			Assert::AreEqual(26, result);

		}

		TEST_METHOD(AreaFunctionality_Length80Width33_Returns2640)
		{
			int result = 0;
			int length = 80;
			int width = 33;
			result = getArea(&length, &width);
			Assert::AreEqual(2640, result);
		}
	};
}
