#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sudoku/main.h"
#include "test.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{		
	TEST_CLASS(Input)
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

	};
	TEST_CLASS(Generate)
	{
		TEST_METHOD(Generate1)
		{
			generator gtest1;
			gtest1.generate_sudoku(1);
			bool flag = test_txt(gtest1.out, 1);
			Assert::AreEqual(flag,true);

		}
		TEST_METHOD(Generate500000)
		{
			generator gtest3;
			gtest3.generate_sudoku(500000);
			bool flag = test_txt(gtest3.out, 500000);
			Assert::AreEqual(flag, true);

		}
		TEST_METHOD(Generate1000000)
		{
			generator gtest2;
			gtest2.generate_sudoku(1000000);
			bool flag = test_txt(gtest2.out, 1000000);
			Assert::AreEqual(flag, true);

		}
	};

	TEST_CLASS(Solve)
	{
		TEST_METHOD(Slove1)
		{
			solver stest1;
			stest1.solve_sudoku("input.txt");
			bool flag = test_txt(stest1.out, 1000000);
			Assert::AreEqual(flag, true);

		}
		/*TEST_METHOD(Slove2)
		{
			solver stest2;
			stest2.solve_sudoku("input1.txt");
			bool flag = test_txt(stest2.out, 4);
			Assert::AreEqual(flag, true);

		}*/
	};
}