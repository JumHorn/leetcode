#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> res;
		vector<int> queen(n); //record queens in each row
		doSolveNQueens(queen, 0, 0, res);
		return res;
	}
	//using loop to solve N queens
	void doSolveNQueens(vector<int> &queen, int i, int j, vector<vector<string>> &res)
	{
		int n = queen.size();
		while (i != 0 || j != n)
		{
			queen[i] = j;
			if (j == n) //out of column
			{
				j = queen[--i] + 1;
				continue;
			}
			//queen check
			if (!queenCheck(queen, i, j))
			{
				++j;
				continue;
			}
			//success or not
			if (i == n - 1)
			{
				//create queen
				vector<string> tmp(n, string(n, '.'));
				for (int k = 0; k < n; k++)
					tmp[k][queen[k]] = 'Q';
				res.push_back(tmp);
			}
			else
			{
				++i;
				j = -1;
			}
			++j;
		}
	}

	bool queenCheck(vector<int> &queen, int row, int column)
	{
		for (int i = 0; i < row; i++)
			if (column == queen[i] || (abs(row - i) == abs(column - queen[i])))
				return false;
		return true;
	}
};