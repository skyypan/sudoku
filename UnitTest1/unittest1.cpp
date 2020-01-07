#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sudoku/main.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		char *argv1[3];
		
		TEST_METHOD(Testinput1)
		{
			argv1[0] = "sudoku.exe";
			argv1[1] = "-c";
			argv1[2] = "abc";
			int r = main(3,argv1);
			Assert::AreEqual(r, 0);
		}
		TEST_METHOD(Testinput2)
		{
			argv1[0] = "sudoku.exe";
			argv1[1] = "-c";
			argv1[2] = "0";
			int r = main(3, argv1);
			Assert::AreEqual(r, 0);
		}
		TEST_METHOD(Testinput3)
		{
			argv1[0] = "sudoku.exe";
			argv1[1] = "-c";
			argv1[2] = "10000000";
			int r = main(3, argv1);
			Assert::AreEqual(r, 0);
		}
		TEST_METHOD(Testinput4)
		{
			argv1[0] = "sudoku.exe";
			argv1[1] = "-s";
			argv1[2] = "abcd";
			int r = main(3, argv1);
			Assert::AreEqual(r, 0);
		}
		TEST_METHOD(Testinput5)
		{
			argv1[0] = "sudoku.exe";
			argv1[1] = "-a";
			argv1[2] = "10";
			int r = main(3, argv1);
			Assert::AreEqual(r, 0);
		}
		TEST_METHOD(Testinput6)
		{
			argv1[0] = "sudoku.exe";
			argv1[1] = "-c";
			argv1[2] = "1000";
			int r = main(3, argv1);
			Assert::AreEqual(r, 0);
		}
		TEST_METHOD(Testinput7)
		{
			argv1[0] = "sudoku.exe";
			argv1[1] = "-s";
			argv1[2] = "input.txt";
			int r = main(3, argv1);
			Assert::AreEqual(r, 0);
		}

		TEST_METHOD(Testsolve1)
		{
			bool flag = solve_sudoku("test_wrong.txt");
			Assert::AreEqual(flag,false);
		}
		TEST_METHOD(Testsolve2)
		{
			bool flag = solve_sudoku("input.txt");
			Assert::AreEqual(flag, true);
		}
	};
}