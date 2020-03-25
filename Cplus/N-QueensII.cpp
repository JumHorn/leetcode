#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
	int totalNQueens(int n)
	{
		if (n < 2)
			return 1;
		vector<int> queen(n); //record queens in each row
		return doTotalNQueens(queen, 0);
	}

	int doTotalNQueens(vector<int> &queen, int row)
	{
		int n = queen.size();
		if (row >= n)
			return 1;
		int res = 0;
		for (int j = 0; j < n; j++)
		{
			if (queenCheck(queen, row, j))
			{
				queen[row] = j;
				res += doTotalNQueens(queen, row + 1);
				queen[row] = 0;
			}
		}
		return res;
	}

	bool queenCheck(vector<int> &queen, int row, int column)
	{
		for (int i = 0; i < row; i++)
			if (column == queen[i] || (abs(row - i) == abs(column - queen[i])))
				return false;
		return true;
	}
};
