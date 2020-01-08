#include "main.h"

char output[200000000];//���
/*char output[200000000];//���
int point = 0;//outputλ��
int now[10][10];
//ת��ģ��
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
//ʹ��ģ��͵�һ�����ɳ�ʼ�����վ�
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
//д���ļ�
void generator::Write()
{
	remove("sudoku.txt");
	ofstream WriteFile("sudoku.txt");
	WriteFile << output;
}
//��������
void generator::generate_sudoku(int num)
{
	int first[] = { 5,1,2,3,4,6,7,8,9 };//��һ��
	int row_order[] = { 0,1,2,3,4,5,6,7,8 };//��˳��
	do {
		initialize(first);//����Ӧ�ó�ʼ�����վ�
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
					if(num > 1) output[point++] = '\n';//һ���վ����
					num--;
				} while (next_permutation(row_order + 6, row_order + 9) && num);
			} while (next_permutation(row_order + 3, row_order + 6) && num);
		} while (next_permutation(row_order + 1, row_order + 3) && num);
	} while (next_permutation(first + 1, first + 9) && num > 1);

	Write();
	return;
}