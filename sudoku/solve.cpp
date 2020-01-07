#include"main.h"

char input[100000000];
char s_output[100000000];
int need_solve[100];//需要填入的格子id记录
int a[10][10];
int row_mark[10][10];//row_mark[i][j]第i行数字j已经填入
int col_mark[10][10];//col_mark[i][j]第i列数字j已经填入
int block_mark[10][10];//block_mark[i][j]第i个九宫格数字j已经填入
int s_point = 0;

void setnum(int row, int col, int num, int flag)
{
	int block_id = (row / 3) * 3 + col / 3;
	row_mark[row][num] = flag;
	col_mark[col][num] = flag;
	block_mark[block_id][num] = flag;
	if (flag)
	{
		a[row][col] = num;
	}
	else
	{
		a[row][col] = 0;
	}
}

bool judge(int row, int col, int num)
{
	int block_id = (row / 3) * 3 + col / 3;
	if (!row_mark[row][num] && !col_mark[col][num] && !block_mark[block_id][num])
		return true;
	else
		return false;
}

bool dfs(int s,int count)
{
	if (s == count) return true;
	int row = need_solve[s] / 9;
	int col = need_solve[s] % 9;
	for (int i = 1; i < 10; i++)
	{
		if (judge(row, col, i))
		{
			setnum(row, col, i, 1);
			if (dfs(s + 1, count))
				return true;
			setnum(row, col, i, 0);
		}
	}
	return false;
}

void print_output()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			s_output[s_point++] = a[i][j] +'0';
			s_output[s_point++] = ' ';
		}
		s_output[s_point++] = a[i][8] + '0';
		s_output[s_point++] = '\n';
	}
	s_output[s_point++] = '\n';
}

bool solve_sudoku(string path)
{
	//从文件中读出数独
	ifstream readfile(path);
	if (!readfile)
	{
		cout << "Can not find file!" << endl;
		return false;
	}
	int p = 0;
	while (!readfile.eof())
	{
		readfile >> input[p++];
	}
	readfile.close();

	p = 0;
	while (input[p])
	{
		if (input[p] == ' ')
		{
			p++;
			continue;
		}
		int count = 0;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int tmp = input[p++] - '0';
				if (tmp == 0)
				{
					need_solve[count++] = i * 9 + j;
				}
				else
				{
					setnum(i, j, tmp, 1);
				}
			}
		}
		bool f = dfs(0,count);
		if (f == false) return false;
		print_output();

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				row_mark[i][j] = 0;
				col_mark[i][j] = 0;
				block_mark[i][j] = 0;
				a[i][j] = 0;
			}
		}
	}
	Write(s_output);
	return true;
}