#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int totalNQueens(int n)
	{
		vector<int> queen(n); //record queens in each row
		return dfs(queen, 0);
	}

	int dfs(vector<int> &queen, int row)
	{
		int N = queen.size();
		if (row >= N)
			return 1;
		int res = 0;
		for (int j = 0; j < N; ++j)
		{
			if (queenCheck(queen, row, j))
			{
				queen[row] = j;
				res += dfs(queen, row + 1);
			}
		}
		return res;
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