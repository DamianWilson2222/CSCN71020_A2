#include "pch.h"
#include "CppUnitTest.h"


extern "C" {
	int getPerimeter(int* length, int* width);
	int getArea(int* length, int* width);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecTests
{
	//Name for the testing section followed by the type of functions
	TEST_CLASS(Task1_RectangleCalculator)
	{
	public:
		
		//This function validates the getPerimeter() using a length of 10 and a width of 3 (within the range)
		//This function is expected to use the formula 2*(length+width)=perimeter or 2*(10+3)=26
		TEST_METHOD(PerimeterFunctionality_Length10Width3_Returns26)
		{
			int result = 0;
			int length = 10;
			int width = 3;
			result = getPerimeter(&length,&width);
			Assert::AreEqual(26, result);

		}

		//This function validates the getArea() using a length of 80 and a width of 33 (within the range)
		//This function is expected to use the formula length*width=area or 80*33=2640
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
