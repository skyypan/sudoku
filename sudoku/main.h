#include<fstream>
#include<iostream> 
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<math.h> 
#include<cstring>
#include <algorithm>
using namespace std;

void initialize(int first[]);
void Write(char * output);
void generate_sudoku(int num);
bool solve_sudoku(string path);
int main(int argc, char *argv[]);