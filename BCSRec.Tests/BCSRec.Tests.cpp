#include "pch.h"
#include "CppUnitTest.h"


extern "C" {
	int getPerimeter(int* length, int* width);
	int getArea(int* length, int* width);
	void setLength(int input, int* length);
	void setWidth(int input, int* width);
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

	//Testing for range requirement
	TEST_CLASS(Task2_RectangleDimensions)
	{
	public:

		//This function tests the setLength() with an out of range edge case of input=0
		//Setting the value of length to -1 in case the function does not run due to the if statement
		//The input shouldn't be equivalant to the width because of the requirement of range
		TEST_METHOD(LengthFunctionality_001) 
		{
			int input = 0;
			int length = -1;
			setLength(input, &length);
			Assert::IsFalse(length == input);
		}

		//This function tests the setLength() with an out of range edge case of input=100
		//Setting the value of length to -1 in case the function does not run due to the if statement
		TEST_METHOD(LengthFunctionality_002)
		{
			int input = 100;
			int length = -1;
			setLength(input, &length);
			Assert::IsFalse(length >= 1 && length <= 99);
		}

		//This function tests the setLength() with an in range edge case of input=1
		//Setting the value of length to -1 in case the function does not run due to the if statement
		TEST_METHOD(LengthFunctionality_003)
		{
			int input = 1;
			int length = -1;
			setLength(input, &length);
			Assert::IsTrue(length >=1 && length <= 99);
		}

		//This function tests the setWidth() with an out of range edge case of input=100
		//Setting the value of width to -1 in case the function does not run due to the if statement
		//The input shouldn't be equivalant to the width because of the requirement of range
		TEST_METHOD(WidthFunctionality_001)
		{
			int input = 100;
			int width = -1;
			setWidth(input, &width);
			Assert::IsFalse(input == width);
		}
		
		//This function tests the setWidth() with an in range edge case of input=99
		//Setting the value of width to -1 in case the function does not run due to the if statement
		TEST_METHOD(WidthFunctionality_002)
		{
			int input = 99;
			int width = -1;
			setLength(input, &width);
			Assert::IsTrue(width >= 1 && width <= 99);
		}

		//This function tests the setWidth() with an in-range case of input=50
		//Setting the value of width to -1 in case the function does not run due to the if statement
		TEST_METHOD(WidthFunctionality_003)
		{
			int input = 50;
			int width = -1;
			setLength(input, &width);
			Assert::IsTrue(width >= 1 && width <= 99);
		}
	};
}
