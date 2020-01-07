#include"main.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Incorrect number of arguments!" << endl;
		return 0;
	}
	if (strcmp(argv[1], "-c") != 0 && strcmp(argv[1], "-s") != 0)
	{
		cout << "Illegal argument input!" << endl;
		return 0;
	}
	if (argv[1][1] == 'c')
	{
		int n = atoi(argv[2]);
		if (strspn(argv[2], "0123456789") != strlen(argv[2]) || n < 1 || n > 1000000)
		{
			cout << "Illegal argument input!\nMake sure the 1<=N<=1000000" << endl;
			return 0;
		}
		generate_sudoku(n);
	}
	else if (argv[1][1] == 's')
	{
		bool f = solve_sudoku(argv[2]);
		if (!f) cout << "Solve sudoku failed!" << endl;
	}
	return 0;
}