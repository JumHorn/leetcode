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
		backTracking(queen, 0, res);
		return res;
	}

	void backTracking(vector<int> &queen, int row, vector<vector<string>> &res)
	{
		int N = queen.size();
		if (row >= N) //create queen
		{
			res.emplace_back(vector<string>(N, string(N, '.')));
			for (int i = 0; i < N; ++i)
				res.back()[i][queen[i]] = 'Q';
		}
		for (int j = 0; j < N; ++j)
		{
			if (queenCheck(queen, row, j))
			{
				queen[row] = j;
				backTracking(queen, row + 1, res);
			}
		}
	}

	bool queenCheck(vector<int> &queen, int row, int column)
	{
		for (int i = 0; i < row; ++i)
		{
			if (column == queen[i] || (abs(row - i) == abs(column - queen[i])))
				return false;
		}
		return true;
	}
};