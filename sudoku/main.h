#include<fstream>
#include<iostream> 
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<math.h> 
#include<cstring>
#include <algorithm>
using namespace std;

class generator {
private:
	
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
	};
public:
	void initialize(int first[]);
	void generate_sudoku(int num);
	void Write();
};

class solver {
private:
	
	int need_solve[100];//��Ҫ����ĸ���id��¼
	int a[10][10] = { 0 };
	int row_mark[10][10] = { 0 };//row_mark[i][j]��i������j�Ѿ�����
	int col_mark[10][10] = { 0 };//col_mark[i][j]��i������j�Ѿ�����
	int block_mark[10][10] = { 0 };//block_mark[i][j]��i���Ź�������j�Ѿ�����
	int s_point = 0;
public:
	void setnum(int row, int col, int num, int flag);
	bool judge(int row, int col, int num);
	bool dfs(int s, int count);
	void print_output();
	void solve_sudoku(string path);
	void Write();
};


