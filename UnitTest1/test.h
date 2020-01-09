#pragma once
#include "stdafx.h"
//int s[100000000];

//测试行中是否有重复
bool test_row(int a[10][10])
{
	for (int i = 0; i < 9; i++)
	{
		int flag[11] = { 0 };
		for (int j = 0; j < 9; j++)
		{
			if (flag[a[i][j]] == 0) flag[a[i][j]] = 1;
			else return false;
		}
	}
	return true;
}
//测试列中是否有重复
bool test_col(int a[10][10])
{
	for (int i = 0; i < 9; i++)
	{
		int flag[11] = { 0 };
		for (int j = 0; j < 9; j++)
		{
			if (flag[a[j][i]] == 0) flag[a[j][i]] = 1;
			else return false;
		}
	}
	return true;
}
//测试块中是否有重复
bool test_blo(int a[10][10])
{
	int tmp_a[10][10] = {
		{a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]},
		{a[3][0],a[3][1],a[3][2],a[4][0],a[4][1],a[4][2],a[5][0],a[5][1],a[5][2]},
		{a[6][0],a[6][1],a[6][2],a[7][0],a[7][1],a[7][2],a[8][0],a[8][1],a[8][2]},
		{a[0][3],a[0][4],a[0][5],a[1][3],a[1][4],a[1][5],a[2][3],a[2][4],a[2][5]},
		{a[3][3],a[3][4],a[3][5],a[4][3],a[4][4],a[4][5],a[5][3],a[5][4],a[5][5]},
		{a[6][3],a[6][4],a[6][5],a[7][3],a[7][4],a[7][5],a[8][3],a[8][4],a[8][5]},
		{a[0][6],a[0][7],a[0][8],a[1][6],a[1][7],a[1][8],a[2][6],a[2][7],a[2][8]},
		{a[3][6],a[3][7],a[3][8],a[4][6],a[4][7],a[4][8],a[5][6],a[5][7],a[5][8]},
		{a[6][6],a[6][7],a[6][8],a[7][6],a[7][7],a[7][8],a[8][6],a[8][7],a[8][8]},
	};
	if (test_row(tmp_a)) return true;
	else return false;
}

bool test_txt(char *out, int num)
{
	/*int p = 0,k = 0;
	while (out[p])
	{
		if (out[p] >= '0'&&out[p] <= '9')
		{
			s[k++] = out[p] - '0';
		}
		p++;
	}*/
    int p = 0;
	int count = 0;
	while (out[p])
	{
		if (out[p] == ' ' || out[p] == '\n')
		{
			p++;
			continue;
		}

		int test_a[10][10];
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (out[p] == ' ' || out[p] == '\n')
				{
					p++;
					j--;
					continue;
				}
				test_a[i][j] = out[p++] - '0';
			}
		}
		if (test_row(test_a) && test_col(test_a) && test_blo(test_a))
		{
			count++;
			if (count > num)
				return false;
		}
		else
		{
			return false;
		}
	}
	if (count < num) return false;
	return true;
}
