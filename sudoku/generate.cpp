#include "main.h"

char output[200000000];//输出
/*char output[200000000];//输出
int point = 0;//output位置
int now[10][10];
//转换模板
int trans[10][10] = {
	{5,1,2,3,4,6,7,8,9},
	{3,4,6,7,8,9,5,1,2},
	{7,8,9,5,1,2,3,4,6},
	{1,2,3,4,6,7,8,9,5},
	{4,6,7,8,9,5,1,2,3},
	{8,9,5,1,2,3,4,6,7},
	{2,3,4,6,7,8,9,5,1},
	{6,7,8,9,5,1,2,3,4},
	{9,5,1,2,3,4,6,7,8},
};*/
//使用模板和第一行生成初始数独终局
void generator::initialize(int first[])
{
	int tmp[10];
	for (int i = 0; i < 9; i++)
	{
		tmp[trans[0][i]] = first[i];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			now[i][j] = tmp[trans[i][j]];
		}
	}
}
//写入文件
void generator::Write()
{
	remove("sudoku.txt");
	ofstream WriteFile("sudoku.txt");
	WriteFile << output;
}
//生成数独
void generator::generate_sudoku(int num)
{
	int first[] = { 5,1,2,3,4,6,7,8,9 };//第一行
	int row_order[] = { 0,1,2,3,4,5,6,7,8 };//行顺序
	do {
		initialize(first);//生存应该初始数独终局
		do {
			do {
				do
				{
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							output[point++] = now[row_order[i]][j] + '0';
							output[point++] = ' ';
						}
						output[point++] = now[row_order[i]][8] + '0';
						output[point++] = '\n';
					}
					if(num > 1) output[point++] = '\n';//一个终局完成
					num--;
				} while (next_permutation(row_order + 6, row_order + 9) && num);
			} while (next_permutation(row_order + 3, row_order + 6) && num);
		} while (next_permutation(row_order + 1, row_order + 3) && num);
	} while (next_permutation(first + 1, first + 9) && num > 1);

	Write();
	return;
}